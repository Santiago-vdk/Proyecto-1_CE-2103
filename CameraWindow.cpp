#include <CameraWindow.h>



//Constructor
CameraWindow::CameraWindow(CvCapture *cam, QWidget *parent)
    : QWidget(parent)
{
    imagenTomada = false;

    m_camera = cam;
    m_photoCounter = 0;
    m_cvwidget = new CameraWidget(this);

    QVBoxLayout *layout = new QVBoxLayout;
    button = new QPushButton("Aprender Forma");

    QPushButton *buttonCompuesta = new QPushButton("Aprender Figura Compuesta");

    botonInterpretar = new QPushButton("Interpretar Figura");

    //botonInterpretar->setDisabled(true);

    layout->addWidget(buttonCompuesta);
    layout->addWidget(m_cvwidget);
    layout->addWidget(button);
    layout->addWidget(botonInterpretar);
    setLayout(layout);
    resize(800, 700);

   connect(button, SIGNAL(clicked()), this, SLOT(savePicture()));

   connect(botonInterpretar, SIGNAL(clicked()), this, SLOT(interpretarImagen()));


   connect(buttonCompuesta, SIGNAL(clicked()), this, SLOT(figuraCompuesta()));


   startTimer(100);  // 0.1-second timer
}

string CameraWindow::getultimaImagen()
{
    return _ultimaImagen;
}

bool CameraWindow::getBanderaTomada()
{
    return imagenTomada;
}

//Puts a new frame in the widget every 100 msec
void CameraWindow::timerEvent(QTimerEvent*)
{
    IplImage *image = cvQueryFrame(m_camera);
    m_cvwidget->putFrame(image);
}



//Saves a new picture
void CameraWindow::interpretarImagen(void)
{
//    botonInterpretar->setDisabled(false);
//    IplImage *image = cvQueryFrame(m_camera);
//    QPixmap photo = m_cvwidget->toPixmap(image);
//    QString returnImagen = "c:\\fotos\\imagen" + QString::number(m_photoCounter) + ".jpg";
//    if (photo.save("c:\\fotos\\imagen" + QString::number(m_photoCounter) + ".jpg")) {
//        qDebug("Picture successfully saved!");
//        _ultimaImagen = returnImagen.toStdString();
//        imagenTomada = true;
//        m_photoCounter++;
//    } else {
//        qDebug("Error while saving the picture");
//    }
    interpretaImagen();

}

void CameraWindow::deshabilitaAprendeForma()
{
    button->setDisabled(true);
}

void CameraWindow::figuraCompuesta()
{
    IplImage *image = cvQueryFrame(m_camera);
    QPixmap photo = m_cvwidget->toPixmap(image);
    QString returnImagen = "c:\\fotos\\imagen" + QString::number(m_photoCounter) + ".jpg";
    if (photo.save("c:\\fotos\\imagen" + QString::number(m_photoCounter) + ".jpg")) {
        qDebug("Picture successfully saved!");
        _ultimaImagen = returnImagen.toStdString();
        imagenTomada = true;
        m_photoCounter++;
    } else {
        qDebug("Error while saving the picture");
    }
    aprendeFormaCompuesta();
}

void CameraWindow::habilitaAprendeForma()
{
    button->setDisabled(false);
}


//Saves a new picture
void CameraWindow::savePicture(void)
{
    IplImage *image = cvQueryFrame(m_camera);
    QPixmap photo = m_cvwidget->toPixmap(image);
    QString returnImagen = "c:\\fotos\\imagen" + QString::number(m_photoCounter) + ".jpg";
    if (photo.save("c:\\fotos\\imagen" + QString::number(m_photoCounter) + ".jpg")) {
        qDebug("Picture successfully saved!");
        _ultimaImagen = returnImagen.toStdString();
        imagenTomada = true;
        m_photoCounter++;
    } else {
        qDebug("Error while saving the picture");
    }
    guardeImagen();
}


