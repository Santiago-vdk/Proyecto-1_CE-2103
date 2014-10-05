#include "figura.h"

figura::figura(int pVertices,string pNombre)
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

void figura::setPuntos(CvPoint *Puntos)
{
    _Puntos = Puntos;
}

CvSeq figura::getResult()
{
    return *_Config;
}

CvPoint figura::getPuntos()
{
    return *_Puntos;
}
