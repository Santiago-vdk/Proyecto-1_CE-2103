#include "ventanaAprendizaje.h"
#include "ui_ventanaaprendizaje.h"

ventanaAprendizaje::ventanaAprendizaje(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ventanaAprendizaje)
{
    ui->setupUi(this);
}

ventanaAprendizaje::~ventanaAprendizaje()
{
    delete ui;
}
