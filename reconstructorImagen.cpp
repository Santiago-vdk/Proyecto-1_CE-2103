#include "reconstructorImagen.h"
#include "ui_reconstructorImagen.h"
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include <windows.h>
#include <QDebug>
#include "pixel.h"
#include "matrizPixeles.h"
#include <QProgressBar>

using namespace cv;
using namespace std;

reconstructorImagen::reconstructorImagen(QWidget *parent, string pImagen):
    QWidget(parent),
    ui(new Ui::reconstructorImagen)
{
    ui->setupUi(this);
    _imagen = pImagen;
    descomponerImagen();
    detectorFallos();


}


reconstructorImagen::~reconstructorImagen()
{
    delete ui;
}

void reconstructorImagen::descomponerImagen()
{
    cv::Mat img = cv::imread(_imagen,CV_LOAD_IMAGE_COLOR);
    unsigned char *input = (unsigned char*)(img.data);
    matrizLectura = new matrizPixeles(img.rows,img.cols);
    int r,g,b;
    for(int i = 0; i < img.rows ;i++){
            for(int j = 0; j < img.cols ;j++){
                b = input[img.step[0] * i + img.step[1] * j ];
                g = input[img.step[0] * i + img.step[1] * j + 1] ;
                r = input[img.step[0] * i + img.step[1] * j + 2] ;
                pixel *Pixel = new pixel(r,g,b);
                matrizLectura->insertarPos(i,j, Pixel);
            }
     }



}

bool reconstructorImagen::detectorFallos()
{
    int pixelesBlancos = 0;
    for(int i = 0; i < matrizLectura->getAnchoI(); i++){
        for(int j = 0; j < matrizLectura->getLargoJ(); j++){
            if(matrizLectura->getPos(i,j)->esBlanco() == true){
                pixelesBlancos ++;
            }
            else{
            }
        }
    }
    if(pixelesBlancos > 0){
        std::cout << "La matriz tiene pixeles blancos, hay: " << pixelesBlancos << std::endl;
        std::cout << "Se debe arreglar" << endl;
        _errores = pixelesBlancos;
        return true;
    }
    else{
        std::cout << "La matriz no posee pixeles bancos" << endl;
        _errores = pixelesBlancos;
        return false;
    }
}

int reconstructorImagen::getErrores()
{
    return _errores;
}

bool reconstructorImagen::arreglarImagen()
{
    //Codigo para arreglar la imagen
    unsigned char bits[10][10];
    int casita = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(casita % 2 == 0){
                bits[i][j] = 255;
            }
            else{
                bits[i][j] = 0;
            }
            casita++;
        }
    }


    Mat image(10,10, CV_8UC1,bits);


    imshow("test", image);



}










