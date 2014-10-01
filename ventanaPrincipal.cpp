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
    Mat image;
    image = reconstructor->arreglarImagen();

    _image = image;

    QPixmap newpix(":/recursos/new.png");
    QPixmap openpix(":/recursos/open.png");
    QPixmap savepix(":/recursos/save.png");
    QPixmap quitpix(":/recursos/quit.png");

    QToolBar *toolbar = addToolBar("ToolBar");
    //toolbar->addAction(QIcon(newpix), "New File");
    //toolbar->addAction(QIcon(openpix), "Open File");
    QAction *save = toolbar->addAction(QIcon(savepix),"Save Image");
    toolbar->addSeparator();
    QAction *quit = toolbar->addAction(QIcon(quitpix),"Quit Application");

    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(save, SIGNAL(triggered()), this, SLOT(guardarImagen()));

    CVImageWidget* imageWidget = new CVImageWidget;
    QMainWindow *popup = new QMainWindow();

    QWidget *mainWidget = new QWidget(popup);

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(imageWidget);

    popup->addToolBar(toolbar);

    mainWidget->setLayout(layout);
    popup->setCentralWidget(mainWidget);

    imageWidget->showImage(image);

    popup->show();
}

ventanaPrincipal::~ventanaPrincipal()
{
    delete ui;
}

void ventanaPrincipal::on_pushButton_2_clicked()
{
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

void ventanaPrincipal::guardarImagen()
{
    cv::imwrite("test.jpg",_image);
}
