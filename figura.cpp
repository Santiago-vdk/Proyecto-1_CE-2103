#include "figura.h"
#include "ListaPuntos.h"
#include <QDebug>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <assert.h>
#include "opencv2/core/core.hpp"

figura::figura(int pVertices, string pNombre)
{
    _Nombre = pNombre;
    _Vertices = pVertices;



}

int figura::getVertices()
{
    return _Vertices;
}

string figura::getNombre()
{
    return _Nombre;
}

void figura::setVertices(int vertices)
{
    _Vertices = vertices;
}

void figura::setNombre(string nombre)
{
    _Nombre= nombre;
}

void figura::setConfig(CvSeq *Config)
{
    _Config = Config;
}

void figura::setPuntos(ListaPuntos *Puntos)
{
    _Puntos = Puntos;
    qDebug() << "insercion logica" << _Puntos->getDatoEnPos(0)->x;
}

CvSeq *figura::getResult()
{
    return _Config;
}

ListaPuntos *figura::getPuntos()
{
    qDebug() << "extraccion logica" << _Puntos->getDatoEnPos(0)->x;
    return _Puntos;
}
