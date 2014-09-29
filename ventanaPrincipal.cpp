#include "ventanaPrincipal.h"
#include "ui_ventanaPrincipal.h"
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#include "reconstructorImagen.h"
#include <QPushButton>
#include <QVBoxLayout>



using namespace std;
ventanaPrincipal::ventanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaPrincipal)
{
    ui->setupUi(this);
    ui->pushButton_2->setDisabled(true);
//    QPixmap bkgnd(":/recursos/bg1.png");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
//    QPalette palette;
//    palette.setBrush(QPalette::Background, bkgnd);
//    this->setPalette(palette);


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

    int blancos = reconstructor->getErrores();

    QString blanc = QString::number(blancos);



    popup = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *botonCorregir = new QPushButton("Corregir", popup);
    QPushButton *botonCancelar = new QPushButton("Cancelar", popup);
    QLabel *indicador = new QLabel("Errores Detectados: ", popup);

    QLabel *indicadorNumero = new QLabel(blanc, popup);
    popup->setMinimumWidth(300);
    popup->setMinimumHeight(150);
    popup->setWindowFlags(windowFlags() ^ Qt::WindowMaximizeButtonHint);

    layout->addWidget(botonCorregir);
    layout->addWidget(botonCancelar);

    layout->addWidget(indicador);
    layout->addWidget(indicadorNumero);

    popup->setLayout(layout);
    popup->show();

    connect(botonCorregir, SIGNAL(released()), this, SLOT(popupCorregir()));
    connect(botonCancelar, SIGNAL(released()), this, SLOT(popupCancelar()));




}


ventanaPrincipal::~ventanaPrincipal()
{
    delete ui;
}



void ventanaPrincipal::on_pushButton_2_clicked()
{
    //this->close();
    reconstructor = new reconstructorImagen(this,imagen );
    reconstructor->setVisible(true);
    ui->labelCargar->setText("Lectura Lista");
    ventanaRevisado();

}

void ventanaPrincipal::popupCancelar()
{

    popup->close();

}

void ventanaPrincipal::popupCorregir()
{
    reconstructor->arreglarImagen();
}
