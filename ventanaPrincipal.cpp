#include "ventanaPrincipal.h"
#include "ui_ventanaPrincipal.h"
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#include "reconstructorImagen.h"


using namespace std;
ventanaPrincipal::ventanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaPrincipal)
{
    ui->setupUi(this);
    ui->pushButton_2->setDisabled(true);
    QPixmap bkgnd(":/recursos/bg1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


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


ventanaPrincipal::~ventanaPrincipal()
{
    delete ui;
}



void ventanaPrincipal::on_pushButton_2_clicked()
{
    this->close();
    reconstructorImagen *reconstructor = new reconstructorImagen(this,imagen );
    reconstructor->setVisible(true);
}
