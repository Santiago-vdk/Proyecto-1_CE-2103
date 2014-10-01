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



using namespace cv;
using namespace std;
ventanaPrincipal::ventanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaPrincipal)
{
    ui->setupUi(this);
    ui->pushButton_2->setDisabled(true);

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
    ui->pushButton_2->setDisabled(true);

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
    unsigned char bits = reconstructor->arreglarImagen();
    Mat image(reconstructor->getMatrizI(),reconstructor->getMatrizJ(), CV_8UC3, bits);
    cv::imwrite("test.jpg",image);
    CVImageWidget* imageWidget = new CVImageWidget();
    QMainWindow *popup = new QMainWindow();
    popup->setCentralWidget(imageWidget);
    imageWidget->showImage(image);
    popup->show();
}

ventanaPrincipal::~ventanaPrincipal()
{
    delete ui;
}



void ventanaPrincipal::on_pushButton_2_clicked()
{
    //this->close();
    reconstructor = new reconstructorImagen(0,imagen );
    //reconstructor->setVisible(true);
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
