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
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>


using namespace Qt;
using namespace std;
using namespace cv;

ventanaAprendizaje::ventanaAprendizaje(QWidget *parent, Facade* pFacade) :
    QWidget(parent),
    ui(new Ui::ventanaAprendizaje)
{
    _facade = pFacade;
    ui->setupUi(this);
    camera = cvCreateCameraCapture(0);
    cvQueryFrame(camera);
    QVBoxLayout *layout = new QVBoxLayout;

    windowCamara = new CameraWindow(camera,0);

    QWidget *widget = new QWidget(this);

    connect(windowCamara, SIGNAL(guardeImagen()), this, SLOT(elSlot()));
    connect(windowCamara, SIGNAL(interpretaImagen()), this, SLOT(interpretaImagenCompuesta()));

    widget->resize(600,600);

    layout->addWidget(windowCamara);
    widget->setLayout(layout);

    ui->botonEnviar->setDisabled(true);
    ui->botonNo->setDisabled(true);
    ui->botonSi->setDisabled(true);
    ui->botonRecuerdos->setDisabled(true);
    ui->botonIgnorar->setDisabled(true);

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
//    cvNamedWindow("Raw");
//    cvShowImage("Raw",img);

    //smooth the original image using Gaussian kernel to remove noise
    cvSmooth(img, img, CV_GAUSSIAN,3,3);

    //converting the original image into grayscale
    IplImage* imgGrayScale = cvCreateImage(cvGetSize(img), 8, 1);
    cvCvtColor(img,imgGrayScale,CV_BGR2GRAY);


//    cvNamedWindow("GrayScale Image");
//     cvShowImage("GrayScale Image",imgGrayScale);


     //thresholding the grayscale image to get better results
     cvThreshold(imgGrayScale,imgGrayScale,100,255,CV_THRESH_BINARY_INV);

//     cvNamedWindow("Thresholded Image");
//     cvShowImage("Thresholded Image",imgGrayScale);

    CvSeq* contours;  //hold the pointer to a contour in the memory block
    CvSeq* result;   //hold sequence of points of a contour
    CvMemStorage *storage = cvCreateMemStorage(0); //storage area for all contours
    //finding all contours in the image
    cvFindContours(imgGrayScale, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

    //###############################################################################################
    bool banderaDetecteContornos = false;
    while(contours)
    {
        result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0);
        //if there are 3  vertices  in the contour(It should be a triangle)
        if(result->total==3  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100 )
        {
            CvPoint *pt[3];
            for(int i=0;i<3;i++){
                pt[i] = (CvPoint*)cvGetSeqElem(result, i);
            }

            cvLine(img, *pt[0], *pt[1], cvScalar(255,0,0),4);
            cvLine(img, *pt[1], *pt[2], cvScalar(255,0,0),4);
            cvLine(img, *pt[2], *pt[0], cvScalar(255,0,0),4);
            qDebug() << "Triangulo";
            banderaDetecteContornos = true;
             _vertices = result->total;
            break;
        }
        //if there are 4 vertices in the contour(It should be a quadrilateral)
        else if(result->total==4  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
        {
            CvPoint *pt[4];
            for(int i=0;i<4;i++){
                pt[i] = (CvPoint*)cvGetSeqElem(result, i);
            }

            cvLine(img, *pt[0], *pt[1], cvScalar(0,255,0),4);
            cvLine(img, *pt[1], *pt[2], cvScalar(0,255,0),4);
            cvLine(img, *pt[2], *pt[3], cvScalar(0,255,0),4);
            cvLine(img, *pt[3], *pt[0], cvScalar(0,255,0),4);
            qDebug() << "Cuadrilatero";
            banderaDetecteContornos = true;
             _vertices = result->total;
            break;
        }
        //if there are 7  vertices  in the contour(It should be a heptagon)
        else if(result->total ==7   && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
        {

            CvPoint *pt[7];
            for(int i=0;i<7;i++){
                pt[i] = (CvPoint*)cvGetSeqElem(result, i);
            }
            cvLine(img, *pt[0], *pt[1], cvScalar(0,0,255),4);
            cvLine(img, *pt[1], *pt[2], cvScalar(0,0,255),4);
            cvLine(img, *pt[2], *pt[3], cvScalar(0,0,255),4);
            cvLine(img, *pt[3], *pt[4], cvScalar(0,0,255),4);
            cvLine(img, *pt[4], *pt[5], cvScalar(0,0,255),4);
            cvLine(img, *pt[5], *pt[6], cvScalar(0,0,255),4);
            cvLine(img, *pt[6], *pt[0], cvScalar(0,0,255),4);
            qDebug() << "Heptagono";
            banderaDetecteContornos = true;
             _vertices = result->total;

            break;
        }
        //obtain the next contour
        contours = contours->h_next;
    }
    qDebug() << banderaDetecteContornos;
    if (!banderaDetecteContornos){

        Mat src, src_gray;
        /// Read the image
        src = imread(cstr, 1 );
        /// Convert it to gray
        cvtColor( src, src_gray, CV_BGR2GRAY );
        GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );
        vector<Vec3f> circles;
        HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 2, src_gray.rows/2, 200, 100);

        /// Draw the circles detected
        for( size_t i = 0; i < circles.size(); i++ )
        {
            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            // circle center
            cv::circle( src, center, 3, Scalar(0,255,0), 3);
            // circle outline
            cv::circle( src, center, radius, Scalar(0,0,255), 3);
            qDebug() << "Circulo";;
            banderaDetecteContornos = true;
         }

        /// Show your results
        cv::namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
        cv::imshow( "Hough Circle Transform Demo", src );
         _vertices = -1;

    }

    qDebug() << banderaDetecteContornos;
    if (!banderaDetecteContornos){

        Mat src,dst,cdst;
        /// Read the image
        src = imread(cstr, 1 );
        Canny(src, dst, 50, 200, 3);

        cvtColor(dst, cdst, CV_GRAY2BGR);
        vector<Vec4i> lines;
        HoughLinesP(dst, lines, 1, CV_PI/180, 200, 50, 10 );
        for ( size_t i = 0; i < lines.size(); i++ ) {
            Vec4i l = lines[i];
            line( cdst, Point(l[0], l[1]),
                  Point(l[2], l[3]), Scalar(0,0,255),
                  3, CV_AA);
            qDebug() << "Linea";
            banderaDetecteContornos = true;
        }

        imshow("detected lines", cdst);
    }
    qDebug() << banderaDetecteContornos;
    qDebug() << "Termine procesamiento";
    //###############################################################################################



    if(banderaDetecteContornos){
        ui->output->setTextColor("red");
        ui->output->append("Ordenador: Como deberia llamar esta forma?");
        ui->botonEnviar->setDisabled(false);
        ui->botonIgnorar->setDisabled(false);
    }
    else if(!banderaDetecteContornos){
        ui->output->setTextColor("red");
        ui->output->append("Ordenador: No detecte ninguna forma");
    }



    //show the image in which identified shapes are marked
    cvNamedWindow("Tracked");
    cvShowImage("Tracked",img);

    cvWaitKey(0); //wait for a key press

    //cleaning up
    cvDestroyAllWindows();
    cvReleaseMemStorage(&storage);
    cvReleaseImage(&img);
    cvReleaseImage(&imgGrayScale);




}

void ventanaAprendizaje::elSlot()
{
    qDebug() << "Se guardo una imagen nueva";
    //Identificacion y abstraccion
    std::string ultimaImagen = windowCamara->getultimaImagen();
    std::cout <<"ultima imagen "<< ultimaImagen << std::endl;
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
        qDebug() << QString::fromStdString (_figuraNombre);
        _facade->aprender(_vertices,_figuraNombre);
        qDebug() << "Aprendi sin problemas";
        _figuraNombre = "";
        _vertices = 0;
        ui->botonRecuerdos->setDisabled(false);
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

    qDebug()<< ui->input->text();

    comando = ui->input->text().toStdString();
    banderaComando = true;

    _figuraNombre = comando;

        std::cout << _figuraNombre << std::endl;

    ui->botonEnviar->setDisabled(true);
    procesamientoFinalizado();
}




void ventanaAprendizaje::on_botonIgnorar_clicked()
{
    ui->output->setTextColor("red");
    ui->output->append("Ordenador: Ignorare la ultima figura.");
    ui->botonIgnorar->setDisabled(true);
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

void ventanaAprendizaje::on_botonRecuerdos_clicked()
{
    for(int i=0;i<_facade->cantidadRecuerdos();i++){
        int Number = _facade->verticesRecuerdo(i);//number to convert int a string
        string Result;//string which will contain the result

        stringstream convert; // stringstream used for the conversion

        convert << Number;//add the value of Number to the characters in the stream
        Result = convert.str();//set Result to the content of the stream
        ui->output->setTextColor("green");
        ui->output->append("Ordenador: Conozco la figura: " + QString::fromStdString (_facade->nombreRecuerdo(i)) + " que tiene " + QString::fromStdString (Result) + " vertices.");
    }
}

void ventanaAprendizaje::interpretaImagenCompuesta()
{






}














