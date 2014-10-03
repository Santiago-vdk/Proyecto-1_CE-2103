#include "ventanaAprendizaje.h"
#include "ui_ventanaaprendizaje.h"

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <assert.h>
#include "opencv2/core/core.hpp"

#include "CameraWidget.h"
#include "CameraWindow.h"

#include <QTextEdit>
#include <QLineEdit>



using namespace Qt;
using namespace std;

ventanaAprendizaje::ventanaAprendizaje(QWidget *parent, Facade* pFacade) :
    QWidget(parent),
    ui(new Ui::ventanaAprendizaje)
{
    _facade = pFacade;
    ui->setupUi(this);
    camera = cvCreateCameraCapture(0);
    IplImage *image = cvQueryFrame(camera);
    assert(image);
    QVBoxLayout *layout = new QVBoxLayout;

    windowCamara = new CameraWindow(camera,0);

    QWidget *widget = new QWidget(this);
    QPushButton *btn = new QPushButton("Test");

    connect(windowCamara, SIGNAL(guardeImagen()), this, SLOT(elSlot()));

    widget->resize(600,600);
    layout->addWidget(btn);
    layout->addWidget(windowCamara);
    widget->setLayout(layout);

    ui->botonEnviar->setDisabled(true);
    ui->botonNo->setDisabled(true);
    ui->botonSi->setDisabled(true);

    //###############################################################

    ui->output->setReadOnly(true);

    banderaComando = false;


    connect(this, SIGNAL(procesamientoFinalizado()), this, SLOT(interaccionPC()));

}

void ventanaAprendizaje::procesadorImagen(string pUltimaImagen)
{

    qDebug() << "Procesando";
    std::string str = pUltimaImagen;
    const char *cstr = str.c_str();


    IplImage* img =  cvLoadImage(cstr);

    //show the original image
    cvNamedWindow("Raw");
    cvShowImage("Raw",img);

    //converting the original image into grayscale
    IplImage* imgGrayScale = cvCreateImage(cvGetSize(img), 8, 1);
    cvCvtColor(img,imgGrayScale,CV_BGR2GRAY);

    //thresholding the grayscale image to get better results
    cvThreshold(imgGrayScale,imgGrayScale,128,255,CV_THRESH_BINARY);

    CvSeq* contours;  //hold the pointer to a contour in the memory block
    CvSeq* result;   //hold sequence of points of a contour
    CvMemStorage *storage = cvCreateMemStorage(0); //storage area for all contours

    //finding all contours in the image
    cvFindContours(imgGrayScale, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

    //###############################################################################################


    //iterating through each contour
    bool banderaDetecte = false;

    //while(!banderaDetecte)
    while(contours)
    {
        //obtain a sequence of points of contour, pointed by the variable 'contour'
        result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0);

        //if there are 3  vertices  in the contour(It should be a triangle)
        if(result->total==3 )
        {
            //iterating through each point
            CvPoint *pt[3];
            for(int i=0;i<3;i++){
                pt[i] = (CvPoint*)cvGetSeqElem(result, i);
            }

            //drawing lines around the triangle
            cvLine(img, *pt[0], *pt[1], cvScalar(255,0,0),4);
            cvLine(img, *pt[1], *pt[2], cvScalar(255,0,0),4);
            cvLine(img, *pt[2], *pt[0], cvScalar(255,0,0),4);


            qDebug() << "Triangulo";
            banderaDetecte = true;
            break;

        }


        //if there are 4 vertices in the contour(It should be a quadrilateral)
        else if(result->total==4 )
        {
            //iterating through each point
            CvPoint *pt[4];
            for(int i=0;i<4;i++){
                pt[i] = (CvPoint*)cvGetSeqElem(result, i);
            }

            //drawing lines around the quadrilateral
            cvLine(img, *pt[0], *pt[1], cvScalar(0,255,0),4);
            cvLine(img, *pt[1], *pt[2], cvScalar(0,255,0),4);
            cvLine(img, *pt[2], *pt[3], cvScalar(0,255,0),4);
            cvLine(img, *pt[3], *pt[0], cvScalar(0,255,0),4);


            qDebug() << "Cuadrilatero";
            banderaDetecte = true;
            break;
        }

        //if there are 7  vertices  in the contour(It should be a heptagon)
        else if(result->total ==7  )
        {
            //iterating through each point
            CvPoint *pt[7];
            for(int i=0;i<7;i++){
                pt[i] = (CvPoint*)cvGetSeqElem(result, i);
            }

            //drawing lines around the heptagon
            cvLine(img, *pt[0], *pt[1], cvScalar(0,0,255),4);
            cvLine(img, *pt[1], *pt[2], cvScalar(0,0,255),4);
            cvLine(img, *pt[2], *pt[3], cvScalar(0,0,255),4);
            cvLine(img, *pt[3], *pt[4], cvScalar(0,0,255),4);
            cvLine(img, *pt[4], *pt[5], cvScalar(0,0,255),4);
            cvLine(img, *pt[5], *pt[6], cvScalar(0,0,255),4);
            cvLine(img, *pt[6], *pt[0], cvScalar(0,0,255),4);


            qDebug() << "Heptagono";
            banderaDetecte = true;
            break;

        }


        //obtain the next contour
        contours = contours->h_next;
    }

    qDebug() << "Termine procesamiento";

    _vertices = result->total;



    //###############################################################################################

    //show the image in which identified shapes are marked
    cvNamedWindow("Tracked");
    cvShowImage("Tracked",img);



    cvWaitKey(0); //wait for a key press

    //cleaning up
    cvDestroyAllWindows();
    cvReleaseMemStorage(&storage);
    cvReleaseImage(&img);
    cvReleaseImage(&imgGrayScale);

    ui->botonEnviar->setDisabled(false);

    ui->output->setTextColor("red");
    ui->output->append("Ordenador: Como deberia llamar esta forma?");



}



void ventanaAprendizaje::elSlot()
{
    qDebug() << "Se guardo una imagen nueva";
    //Identificacion y abstraccion
    std::string ultimaImagen = windowCamara->getultimaImagen();
    std::cout <<"ultima imagen"<< ultimaImagen << std::endl;
    procesadorImagen(ultimaImagen);

}


void ventanaAprendizaje::interaccionPC()
{
    qDebug() << "Comienzo a interactuar";
    std::cout << "El numero de vertices de la ultima figura es: " << _vertices << std::endl;

    if(_facade->recordar(_vertices)){
        ui->output->setTextColor("red");
        ui->output->append("Ordenador: Ya conozco esta figura, la vuelvo a aprender?");
        ui->botonSi->setDisabled(false);
        ui->botonNo->setDisabled(false);

        qDebug() << "En espera de respuesta";
    }

    else{
        ui->output->setTextColor("red");
        ui->output->append("Ordenador: Figura aprendida!");
        _facade->aprender(_vertices,_figuraNombre);
        qDebug() << "Aprendi sin problemas";
        _figuraNombre = "";
        _vertices = 0;
    }




}


ventanaAprendizaje::~ventanaAprendizaje()
{
    delete ui;
}

void ventanaAprendizaje::on_botonEnviar_clicked()
{

    ui->output->setTextColor("blue");
    ui->output->append(ui->input->text());
    comando = ui->input->text().toStdString();
    banderaComando = true;
    procesamientoFinalizado();
    ui->botonEnviar->setDisabled(true);

}



void ventanaAprendizaje::on_botonNo_clicked()
{
    ui->output->setTextColor("red");
    ui->output->append("Ordenador: Ok! Ignorare esta nueva figura");
    ui->botonNo->setDisabled(true);
    ui->botonEnviar->setDisabled(true);
    ui->botonSi->setDisabled(true);
}

void ventanaAprendizaje::on_botonSi_clicked()
{
    _facade->reaprender(_vertices,_figuraNombre);
    ui->output->setTextColor("red");
    ui->output->append("Ordenador: Listo! Volvi a aprender esta figura");
    ui->botonNo->setDisabled(true);
    ui->botonEnviar->setDisabled(true);
    ui->botonSi->setDisabled(true);


}
