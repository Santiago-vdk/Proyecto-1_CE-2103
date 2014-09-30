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
#include <cvimagewidget.h>
#include <QMainWindow>
#include <QDialog>

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

    std::cout << img.rows << std::endl;
    std::cout << img.cols << std::endl;

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

void reconstructorImagen::arreglarImagen()
{
    //Codigo para arreglar la imagen
    matrizLectura->corregirMatriz();
    int j2 =0;
    unsigned char bits[matrizLectura->getAnchoI()][matrizLectura->getLargoJ() *3];
    for(int i = 0; i < matrizLectura->getAnchoI(); i++){
        for(int j = 0; j < matrizLectura->getLargoJ() * 3; j+=3){
            bits[i][j + 0] = matrizLectura->getPos(i,j2)->getBlue();
            bits[i][j + 1] = matrizLectura->getPos(i,j2)->getGreen();
            bits[i][j + 2] = matrizLectura->getPos(i,j2)->getRed();
            j2++;
        }
        j2 = 0;

    }

    Mat image(matrizLectura->getAnchoI(),matrizLectura->getLargoJ(), CV_8UC3, bits);
    cv::imwrite("test.jpg",image);
    CVImageWidget* imageWidget = new CVImageWidget();
    QMainWindow *popup = new QMainWindow();
    popup->setCentralWidget(imageWidget);
    imageWidget->showImage(image);
    popup->show();




}










