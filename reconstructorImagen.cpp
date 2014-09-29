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

using namespace cv;
using namespace std;

reconstructorImagen::reconstructorImagen(QWidget *parent, string pImagen) :
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

void reconstructorImagen::detectorFallos()
{

    qDebug() << "matrizPixeles.size()";
}
