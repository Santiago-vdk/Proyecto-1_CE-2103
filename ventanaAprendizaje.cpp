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

#include "ListaPuntos.h"


using namespace Qt;
using namespace std;
using namespace cv;

ventanaAprendizaje::ventanaAprendizaje(QWidget *parent, Facade* pFacade) :
    QWidget(parent),
    ui(new Ui::ventanaAprendizaje)
{
    _facade = pFacade;
    ui->setupUi(this);

    this->setWindowFlags(windowFlags() ^ Qt::WindowMaximizeButtonHint);
    QPixmap bkgnd(":/recursos/COLOURlovers.com-Twilight_Tree.png");
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    camera = cvCreateCameraCapture(0);
    cvQueryFrame(camera);
    QVBoxLayout *layout = new QVBoxLayout;

    windowCamara = new CameraWindow(camera,0);

    QWidget *widget = new QWidget(this);

    connect(windowCamara, SIGNAL(guardeImagen()), this, SLOT(elSlot()));
    connect(windowCamara, SIGNAL(interpretaImagen()), this, SLOT(interpretaImagenCompuesta()));

    connect(this, SIGNAL(habilitarAprendeForma()), windowCamara, SLOT(habilitaAprendeForma()));
    connect(this, SIGNAL(deshabilitarAprendeForma()),windowCamara, SLOT(deshabilitaAprendeForma()));
    connect(windowCamara, SIGNAL(aprendeFormaCompuesta()),this, SLOT(aprenderFormaCompuesta()));

    widget->resize(600,600);

    layout->addWidget(windowCamara);
    widget->setLayout(layout);

    ui->botonEnviar->setDisabled(true);
    ui->botonNo->setDisabled(true);
    ui->botonSi->setDisabled(true);
    ui->botonRecuerdos->setDisabled(true);
    ui->botonIgnorar->setDisabled(true);

    ui->output->setReadOnly(true);
    banderaComando = false;

    connect(this, SIGNAL(procesamientoFinalizado()), this, SLOT(interaccionPC()));

    ui->output->setTextColor("black");

    ui->output->append("-> Inicializando sistema de aprendizaje");
    ui->output->append("-> Activando alzheimer");
    ui->output->append("-> Procesando monos con nanoreceptores");
    ui->output->append("-> Sistemas listos...");
    ui->output->append("-> Si.D.A Activado");
    ui->output->append("-------------------------------");


}

void ventanaAprendizaje::procesadorImagen(string pUltimaImagen)
{

    qDebug() << "Procesando";
    std::string str = pUltimaImagen;
    const char *cstr = str.c_str();
    IplImage* img =  cvLoadImage(cstr);
    cvSmooth(img, img, CV_GAUSSIAN,3,3);
    IplImage* imgGrayScale = cvCreateImage(cvGetSize(img), 8, 1);
    cvCvtColor(img,imgGrayScale,CV_BGR2GRAY);
    cvThreshold(imgGrayScale,imgGrayScale,100,255,CV_THRESH_BINARY_INV);
    CvSeq* contours;
    CvSeq* result;
    CvMemStorage *storage = cvCreateMemStorage(0);


    cvFindContours(imgGrayScale, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
    //###############################################################################################
    bool banderaDetecteContornos = false;
    while(contours)
    {
        result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0);

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

        else if(result->total==5  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
        {
            CvPoint *pt[5];
            for(int i=0;i<5;i++){
                pt[i] = (CvPoint*)cvGetSeqElem(result, i);
            }

            cvLine(img, *pt[0], *pt[1], cvScalar(0,255,0),4);
            cvLine(img, *pt[1], *pt[2], cvScalar(0,255,0),4);
            cvLine(img, *pt[2], *pt[3], cvScalar(0,255,0),4);
            cvLine(img, *pt[3], *pt[4], cvScalar(0,255,0),4);
            cvLine(img, *pt[4], *pt[0], cvScalar(0,255,0),4);
            qDebug() << "Pentagono";
            banderaDetecteContornos = true;
            _vertices = result->total;
            break;
        }



        else if(result->total==6  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
        {
            CvPoint *pt[6];
            for(int i=0;i<6;i++){
                pt[i] = (CvPoint*)cvGetSeqElem(result, i);
            }

            cvLine(img, *pt[0], *pt[1], cvScalar(0,255,0),4);
            cvLine(img, *pt[1], *pt[2], cvScalar(0,255,0),4);
            cvLine(img, *pt[2], *pt[3], cvScalar(0,255,0),4);
            cvLine(img, *pt[3], *pt[4], cvScalar(0,255,0),4);
            cvLine(img, *pt[4], *pt[5], cvScalar(0,255,0),4);
            cvLine(img, *pt[5], *pt[0], cvScalar(0,255,0),4);

            qDebug() << "Hexagono";
            banderaDetecteContornos = true;
            _vertices = result->total;
            break;
        }


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
        if(banderaDetecteContornos){
            /// Show your results
            cv::namedWindow( "Detecte un Circulo", CV_WINDOW_AUTOSIZE );
            cv::imshow( "Detecte un Circulo", src );
        }
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
        if(banderaDetecteContornos){
            imshow("Lineas Detectadas", cdst);
        }


    }
    qDebug() << banderaDetecteContornos;
    qDebug() << "Termine procesamiento";
    //###############################################################################################

    if(banderaDetecteContornos){
        ui->output->setTextColor("red");
        ui->output->append("Ordenador: Como deberia llamar esta forma?");
        ui->botonEnviar->setDisabled(false);
        ui->botonIgnorar->setDisabled(false);
        deshabilitarAprendeForma();
    }
    else if(!banderaDetecteContornos){
        ui->output->setTextColor("red");
        ui->output->append("Ordenador: No detecte ninguna forma");
    }

    if(banderaDetecteContornos){
        cvNamedWindow("Tracked");
        cvShowImage("Tracked",img);
    }

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
        ui->botonIgnorar->setDisabled(true);
        habilitarAprendeForma();
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
    habilitarAprendeForma();
}

void ventanaAprendizaje::on_botonIgnorar_clicked()
{
    ui->output->setTextColor("red");
    ui->output->append("Ordenador: Ignorare la ultima figura.");
    ui->botonIgnorar->setDisabled(true);
    ui->botonEnviar->setDisabled(true);
    habilitarAprendeForma();

}

void ventanaAprendizaje::aprenderFormaCompuesta()
{

    std::string str = windowCamara->getultimaImagenCompuesta();
    const char *cstr = str.c_str();
    IplImage* imgIpl =  cvLoadImage(cstr);
    cvSmooth(imgIpl, imgIpl, CV_GAUSSIAN,3,3);
    IplImage* imgGrayScale = cvCreateImage(cvGetSize(imgIpl), 8, 1);
    cvCvtColor(imgIpl,imgGrayScale,CV_BGR2GRAY);

    cvThreshold(imgGrayScale,imgGrayScale,128,255,CV_THRESH_BINARY);

    CvSeq* contours;
    CvSeq* result;
    CvMemStorage *storage = cvCreateMemStorage(0);
    cvFindContours(imgGrayScale, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
    _facade->nuevaCombinacion();

    while(contours)
    {
        result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0);


        if(result->total==3  && _facade->recordar(3) && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
        {

            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<3;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(255,0,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(255,0,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(0)), cvScalar(255,0,0),4);
            _facade->agregarEnUltimaCombinacion(result,puntos);

        }

        else if(result->total==4 && _facade->recordar(4)  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<4;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,255,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,255,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,255,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(0)), cvScalar(0,255,0),4);
            _facade->agregarEnUltimaCombinacion(result,puntos);


        }



        else if(result->total==5&& _facade->recordar(5)  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100 )
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<5;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,0,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,0,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,0,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(0,0,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(0)), cvScalar(0,0,255),4);
            _facade->agregarEnUltimaCombinacion(result,puntos);

        }


        //if there are 6  vertices  in the contour(It should be a triangle)
        else if(result->total==6  && _facade->recordar(6) && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100 )
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<6;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(4)), *(puntos->getDatoEnPos(5)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(0)), cvScalar(0,255,255),4);
            _facade->agregarEnUltimaCombinacion(result,puntos);

        }


        //if there are 7  vertices  in the contour(It should be a heptagon)
        else if(result->total == 7  && _facade->recordar(7) && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100 )
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<7;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(4)), *(puntos->getDatoEnPos(5)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(6)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(6)), *(puntos->getDatoEnPos(0)), cvScalar(199,6,186),4);
            _facade->agregarEnUltimaCombinacion(result,puntos);
        }


        contours = contours->h_next;
    }

    //    cv::Mat imgMat = cv::cvarrToMat(imgIpl);

    //    Mat src, src_gray;
    //    src = imread(cstr, 1 );
    //    /// Convert it to gray
    //    cvtColor( src, src_gray, CV_BGR2GRAY );
    //    GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );
    //    vector<Vec3f> circles;
    //    HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 2, src_gray.rows/2, 200, 100);

    //    /// Draw the circles detected
    //    for( size_t i = 0; i < circles.size(); i++ )
    //    {
    //        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
    //        int radius = cvRound(circles[i][2]);
    //        // circle center
    //        cv::circle( imgMat, center, 3, Scalar(0,255,0), 3);
    //        // circle outline
    //        cv::circle( imgMat, center, radius, Scalar(0,0,255), 3);

    //    }

    //    Mat src,dst,cdst;
    //    /// Read the image
    //    src = imread(cstr, 1 );
    //    Canny(src, dst, 50, 200, 3);

    //    cvtColor(dst, cdst, CV_GRAY2BGR);
    //    vector<Vec4i> lines;
    //    HoughLinesP(dst, lines, 1, CV_PI/180, 200, 50, 10 );
    //    for ( size_t i = 0; i < lines.size(); i++ ) {
    //        Vec4i l = lines[i];
    //        line( cdst, Point(l[0], l[1]),Point(l[2], l[3]), Scalar(0,0,255),3, CV_AA);
    //    }




    cvNamedWindow("Tracked");
    cvShowImage("Tracked",imgIpl);
    //cv::imshow( "Tracked", imgIpl );
    cvWaitKey(0);
    cvDestroyAllWindows();
    cvReleaseMemStorage(&storage);
    cvReleaseImage(&imgIpl);
    cvReleaseImage(&imgGrayScale);

    qDebug() << "Termine aprender figura compuesta";


}


void ventanaAprendizaje::on_botonNo_clicked()
{
    ui->output->setTextColor("red");
    ui->output->append("Ordenador: Ok! Ignorare esta nueva figura");
    ui->botonNo->setDisabled(true);
    ui->botonEnviar->setDisabled(true);
    ui->botonSi->setDisabled(true);
    habilitarAprendeForma();
}

void ventanaAprendizaje::on_botonSi_clicked()
{
    _facade->reaprender(_vertices,_figuraNombre);
    ui->output->setTextColor("red");
    ui->output->append("Ordenador: Listo! Volvi a aprender esta figura");
    ui->botonNo->setDisabled(true);
    ui->botonEnviar->setDisabled(true);
    ui->botonSi->setDisabled(true);
    habilitarAprendeForma();

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
    qDebug()<< "interpretaImagenCompuesta";
    std::string str = "C:/fotos/rand.jpg";
    const char *cstr = str.c_str();
    IplImage* imgIpl =  cvLoadImage(cstr);
    cvSmooth(imgIpl, imgIpl, CV_GAUSSIAN,3,3);
    IplImage* imgGrayScale = cvCreateImage(cvGetSize(imgIpl), 8, 1);
    cvCvtColor(imgIpl,imgGrayScale,CV_BGR2GRAY);

    //cvThreshold(imgGrayScale,imgGrayScale,100,255,CV_THRESH_BINARY_INV);
    cvThreshold(imgGrayScale,imgGrayScale,128,255,CV_THRESH_BINARY);

    CvSeq* contours;
    CvSeq* result = new CvSeq();
    CvMemStorage *storage = cvCreateMemStorage(0);
    cvFindContours(imgGrayScale, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));



    while(contours)
    {
        result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0);

        //if there are 3  vertices  in the contour(It should be a triangle)
        if(result->total==3  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100 )
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<3;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(255,0,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(255,0,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(0)), cvScalar(255,0,0),4);

            int v=result->total;
            _facade->insertarListaTemporal(v);
            std::cout<< "al insertar" << puntos->getDatoEnPos(0)->x << std::endl;
            _facade->getListaTemporal()->getTail()->getFigura()->setPuntos(puntos);
            std::cout<< "al insertar dsdsfasdf" << _facade->getListaTemporal()->getTail()->getFigura()->getPuntos()->getDatoEnPos(0)->x << std::endl;

        }


        //if there are 4 vertices in the contour(It should be a quadrilateral)
        else if(result->total==4  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<4;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,255,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,255,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,255,0),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(0)), cvScalar(0,255,0),4);

            qDebug() << "cuadrado";
            int v=result->total;
            _facade->insertarListaTemporal(v);
            _facade->getListaTemporal()->getTail()->getFigura()->setPuntos(puntos);


        }



        else if(result->total==5  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100 )
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<5;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }

            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,0,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,0,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,0,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(0,0,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(0)), cvScalar(0,0,255),4);
            int v=result->total;
            _facade->insertarListaTemporal(v);
            _facade->getListaTemporal()->getTail()->getFigura()->setPuntos(puntos);

        }


        //if there are 6  vertices  in the contour(It should be a triangle)
        if(result->total==6  && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100 )
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<6;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(4)), *(puntos->getDatoEnPos(5)), cvScalar(0,255,255),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(0)), cvScalar(0,255,255),4);
            int v=result->total;
            _facade->insertarListaTemporal(v);
            _facade->getListaTemporal()->getTail()->getFigura()->setPuntos(puntos);

        }


        //if there are 7  vertices  in the contour(It should be a heptagon)
        else if(result->total == 7   && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100 )
        {
            ListaPuntos *puntos = new ListaPuntos();
            for(int i=0;i<7;i++){
                puntos->insertarDato((CvPoint*)cvGetSeqElem(result, i));
            }
            cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(4)), *(puntos->getDatoEnPos(5)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(6)), cvScalar(199,6,186),4);
            cvLine(imgIpl, *(puntos->getDatoEnPos(6)), *(puntos->getDatoEnPos(0)), cvScalar(199,6,186),4);
            int v=result->total;
            _facade->insertarListaTemporal(v);
            _facade->getListaTemporal()->getTail()->getFigura()->setPuntos(puntos);
        }

        contours = contours->h_next;
    }

    //    cv::Mat imgMat = cv::cvarrToMat(imgIpl);

    //    Mat src, src_gray;
    //    src = imread(cstr, 1 );
    //    /// Convert it to gray
    //    cvtColor( src, src_gray, CV_BGR2GRAY );
    //    GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );
    //    vector<Vec3f> circles;
    //    HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 2, src_gray.rows/2, 200, 100);

    //    /// Draw the circles detected
    //    for( size_t i = 0; i < circles.size(); i++ )
    //    {
    //        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
    //        int radius = cvRound(circles[i][2]);
    //        // circle center
    //        cv::circle( imgMat, center, 3, Scalar(0,255,0), 3);
    //        // circle outline
    //        cv::circle( imgMat, center, radius, Scalar(0,0,255), 3);

    //    }

    //    Mat src,dst,cdst;
    //    /// Read the image
    //    src = imread(cstr, 1 );
    //    Canny(src, dst, 50, 200, 3);

    //    cvtColor(dst, cdst, CV_GRAY2BGR);
    //    vector<Vec4i> lines;
    //    HoughLinesP(dst, lines, 1, CV_PI/180, 200, 50, 10 );
    //    for ( size_t i = 0; i < lines.size(); i++ ) {
    //        Vec4i l = lines[i];
    //        line( cdst, Point(l[0], l[1]),Point(l[2], l[3]), Scalar(0,0,255),3, CV_AA);
    //    }


    for(int k = 0; k < _facade->getListaTemporal()->getTamanio(); k++){
        qDebug() << "la lista" << _facade->getListaTemporal()->getPos(1)->getFigura()->getPuntos()->getDatoEnPos(k)->x;
    }



    for(int k = 0; k < _facade->getCombinacionEnPos(0)->getListaElementos()->getTamanio(); k++){
        qDebug() << "la lista 1" << _facade->getCombinacionEnPos(0)->getListaElementos()->getPos(k)->getFigura()->getPuntos()->getDatoEnPos(0)->x;
    }

    qDebug()<< "Interpreta figura compuesta tracked";

    qDebug()<< "A dibujar";
    dibujarFiguraCompuesta();


}

void ventanaAprendizaje::dibujarFiguraCompuesta()
{
    qDebug()<< "dibujarFIguraCompuesta";



    std::string str = "C:/fotos/blackimg.jpg";
    const char *cstr = str.c_str();
    IplImage* imgIpl =  cvLoadImage(cstr);

    for(int i = 0; i < _facade->getTamanioCombinaciones(); i++){
        if(_facade->CombinacionCorrecta(i)){



            for(int j = 0; j < _facade->getCombinacionEnPos(i)->getCantidad(); j++){

                ListaPuntos *puntos=_facade->getCombinacionEnPos(i)->getListaElementos()->getPos(j)->getFigura()->getPuntos();



                //Figura de 3 vertices
                if(_facade->getCombinacionEnPos(i)->getListaElementos()->getPos(j)->getFigura()->getVertices() == 3){

                    qDebug()<< "triangulo";

                    std::cout<< _facade->getCombinacionEnPos(i)->getListaElementos()->getPos(j)->getFigura()->getPuntos()->getDatoEnPos(0)->x << std::endl;
                    cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(255,0,0),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(255,0,0),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(0)), cvScalar(255,0,0),4);


                }

                //Figura de 4 vertices


                else if(_facade->getCombinacionEnPos(i)->getListaElementos()->getPos(j)->getFigura()->getVertices() == 4){
                    qDebug()<< "cuadrado";


                    cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,255,0),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,255,0),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,255,0),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(0)), cvScalar(0,255,0),4);
                }

                //Figura de 5 vertices
                else if(_facade->getCombinacionEnPos(i)->getListaElementos()->getPos(j)->getFigura()->getVertices() == 5){
                    cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,0,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,0,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,0,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(0,0,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(0)), cvScalar(0,0,255),4);
                }

                //Figura de 6 vertices
                else if(_facade->getCombinacionEnPos(i)->getListaElementos()->getPos(j)->getFigura()->getVertices() == 6){
                    cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,255,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,255,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,255,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(0,255,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(4)), *(puntos->getDatoEnPos(5)), cvScalar(0,255,255),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(0)), cvScalar(0,255,255),4);
                }

                //Figura de 7 vertices
                else if(_facade->getCombinacionEnPos(i)->getListaElementos()->getPos(j)->getFigura()->getVertices() == 7){
                    cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(199,6,186),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(199,6,186),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(199,6,186),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(199,6,186),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(4)), *(puntos->getDatoEnPos(5)), cvScalar(199,6,186),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(6)), cvScalar(199,6,186),4);
                    cvLine(imgIpl, *(puntos->getDatoEnPos(6)), *(puntos->getDatoEnPos(0)), cvScalar(199,6,186),4);
                }
            }
        }
    }



    //Sale primer for
    if(_facade->getListaTemporal()->getTamanio() > 0){


        qDebug() << "tamanio de " << _facade->getListaTemporal()->getTamanio();

        for(int santiGuapo = 0; santiGuapo < _facade->getListaTemporal()->getTamanio(); santiGuapo++){

            ListaPuntos *puntos = _facade->getListaTemporal()->getPos(santiGuapo)->getFigura()->getPuntos();
            //Figura de 3 vertices
            qDebug() << "antes if " << _facade->getListaTemporal()->getPos(santiGuapo)->getFigura()->getVertices();
            if(_facade->getListaTemporal()->getPos(santiGuapo)->getFigura()->getVertices() == 3){
                qDebug() << "if 3 vertices";
                cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(255,0,0),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(255,0,0),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(0)), cvScalar(255,0,0),4);
            }

            //Figura de 4 vertices
            if(_facade->getListaTemporal()->getPos(santiGuapo)->getFigura()->getVertices() == 4){

                qDebug() << "if 4 vertices";

                cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,255,0),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,255,0),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,255,0),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(0)), cvScalar(0,255,0),4);
            }

            //Figura de 5 vertices
            if(_facade->getListaTemporal()->getPos(santiGuapo)->getFigura()->getVertices() == 5){

                qDebug() << "if 5 vertices";

                cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,0,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,0,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,0,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(0,0,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(0)), cvScalar(0,0,255),4);
            }

            //Figura de 6 vertices
            if(_facade->getListaTemporal()->getPos(santiGuapo)->getFigura()->getVertices() == 6){

                qDebug() << "if 6 vertices";

                cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(0,255,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(0,255,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(0,255,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(0,255,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(4)), *(puntos->getDatoEnPos(5)), cvScalar(0,255,255),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(0)), cvScalar(0,255,255),4);
            }

            //Figura de 7 vertices
            if(_facade->getListaTemporal()->getPos(santiGuapo)->getFigura()->getVertices() == 7){

                qDebug() << "if 7 vertices";

                cvLine(imgIpl, *(puntos->getDatoEnPos(0)), *(puntos->getDatoEnPos(1)), cvScalar(199,6,186),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(1)), *(puntos->getDatoEnPos(2)), cvScalar(199,6,186),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(2)), *(puntos->getDatoEnPos(3)), cvScalar(199,6,186),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(3)), *(puntos->getDatoEnPos(4)), cvScalar(199,6,186),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(4)), *(puntos->getDatoEnPos(5)), cvScalar(199,6,186),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(5)), *(puntos->getDatoEnPos(6)), cvScalar(199,6,186),4);
                cvLine(imgIpl, *(puntos->getDatoEnPos(6)), *(puntos->getDatoEnPos(0)), cvScalar(199,6,186),4);
            }

        }

    }



    //cv::Mat imgMat = cv::cvarrToMat(imgIpl);
    cvNamedWindow("Tracked2");
    cvShowImage("Tracked2",imgIpl);
    //cvResize(imgIpl,final);




} //Llave metodo















