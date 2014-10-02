#include "ventanaPrincipal.h"
#include "ui_ventanaPrincipal.h"
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#include "reconstructorImagen.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <cvimagewidget.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <ventanaAprendizaje.h>
#include <QMessageBox>



using namespace cv;
using namespace std;
ventanaPrincipal::ventanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaPrincipal)
{
    ui->setupUi(this);
    ui->pushButton_2->setDisabled(true);
    this->setWindowFlags(windowFlags() ^ Qt::WindowMaximizeButtonHint);
    banderaPrimeraCorrida  = true;
    banderaGuardado  = false;

}

void ventanaPrincipal::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Directory"), directory.path(), tr("JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)"));
    if ( path.isNull() == false )
    {
        directory.setPath(path);
    }
    imagen = directory.path().toStdString();
    cout << imagen << endl;
    ui->labelCargar->setText("Imagen Cargada!");
    ui->pushButton_2->setDisabled(false);
}

void ventanaPrincipal::ventanaRevisado()
{
    if (!banderaPrimeraCorrida){
        ui->pushButton_2->setDisabled(true);
        this->close();
    }


    int blancos = reconstructor->getErrores();
    QString blanc = QString::number(blancos);
    popupDialogReconstruir = new QDialog();

    QVBoxLayout *layout = new QVBoxLayout;
    botonCorregir = new QPushButton("Corregir");
    QPushButton *botonCancelar = new QPushButton("Cancelar");

    QLabel *indicador = new QLabel("Errores Detectados: ");
    QLabel *indicadorNumero = new QLabel(blanc);
    popupDialogReconstruir->setMinimumWidth(300);
    popupDialogReconstruir->setMinimumHeight(150);
    popupDialogReconstruir->setWindowFlags(windowFlags() ^ Qt::WindowMaximizeButtonHint);

    layout->addWidget(botonCorregir);
    layout->addWidget(botonCancelar);

    layout->addWidget(indicador);
    layout->addWidget(indicadorNumero);

    popupDialogReconstruir->setLayout(layout);
    popupDialogReconstruir->show();

    connect(botonCorregir, SIGNAL(released()), this, SLOT(popupCorregir()));
    connect(botonCancelar, SIGNAL(released()), this, SLOT(popupCancelar()));
    if (reconstructor->getErrores() == 0){
        botonCorregir->setDisabled(true);
        botonCorregir->setText("Sin Errores");
    }





}




void ventanaPrincipal::ventanaMostrado()
{
    Mat image;
    image = reconstructor->arreglarImagen();

    _image = image;

    QPixmap newpix(":/recursos/new.png");
    QPixmap openpix(":/recursos/open.png");
    QPixmap savepix(":/recursos/save.png");
    QPixmap quitpix(":/recursos/quit.png");

    QToolBar *toolbar = addToolBar("ToolBar");
    //toolbar->addAction(QIcon(newpix), "New File");
    QAction *niw = toolbar->addAction(QIcon(newpix),"New Image");
    //toolbar->addAction(QIcon(openpix), "Open File");
    QAction *save = toolbar->addAction(QIcon(savepix),"Save Image");
    toolbar->addSeparator();
    QAction *quit = toolbar->addAction(QIcon(quitpix),"Quit Application");

    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(save, SIGNAL(triggered()), this, SLOT(guardarImagen()));
    connect(niw, SIGNAL(triggered()), this, SLOT(nuevaImagen()));

    CVImageWidget* imageWidget = new CVImageWidget;
    ventanaReconstructor = new QMainWindow();

    QWidget *mainWidget = new QWidget(ventanaReconstructor);

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(imageWidget);

   ventanaReconstructor->addToolBar(toolbar);

    mainWidget->setLayout(layout);
    ventanaReconstructor->setCentralWidget(mainWidget);

    imageWidget->showImage(image);

    ventanaReconstructor->show();
}

ventanaPrincipal::~ventanaPrincipal()
{
    delete ui;
}

void ventanaPrincipal::nuevaReconstruccion()
{

    QString path = QFileDialog::getOpenFileName(this, tr("Directory"), directory.path(), tr("JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)"));
    if ( path.isNull() == false )
    {
        directory.setPath(path);
    }
    imagen = directory.path().toStdString();
    cout << imagen << endl;

    reconstructor = new reconstructorImagen(0,imagen);
    ventanaRevisado();
}

void ventanaPrincipal::on_pushButton_2_clicked()
{
    reconstructor = new reconstructorImagen(0,imagen);
    ui->labelCargar->setText("Lectura Lista");
    ventanaRevisado();
}

void ventanaPrincipal::popupCancelar()
{
   popupDialogReconstruir->close();
}

void ventanaPrincipal::popupCorregir()
{
    ventanaMostrado();
    popupDialogReconstruir->close();

}

void ventanaPrincipal::guardarImagen()
{
    cv::imwrite("Guardada.jpg",_image);
    banderaGuardado = true;
}



void ventanaPrincipal::on_buttonAprendizaje_clicked()
{
    this->close();
    ventanaAprendizaje *ventAprendizaje = new ventanaAprendizaje();
    ventAprendizaje->show();
}

void ventanaPrincipal::nuevaImagen()
{
    if ( !banderaGuardado )
      {
      switch  (	QMessageBox::warning(
          this, "Su imagen no ha sido guardada",
          "Su imagen anterior fue reconstruida, pero no guardada\n"
          "Si continua, perdera la imagen anterior.\n"
          "Continuar?",
          "&Guardar y continuar", "&Cancelar", QString::null, 1, 1 )  )
      {
      case 0:
          guardarImagen();
          banderaPrimeraCorrida = false;
          banderaGuardado = false;
          ventanaReconstructor->close();
          nuevaReconstruccion();
          break;
      default:
          break;
      }
      }
    else{
        ventanaReconstructor->close();
        nuevaReconstruccion();
    }
}
