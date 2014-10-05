#include "figura.h"

figura::figura(string pNombre,CvSeq * pResult,CvPoint *pPuntos)
{
    _Nombre = pNombre;
    _Vertices = pResult->total;
    _Config= *pResult;
    _Puntos= *pPuntos;

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

CvSeq figura::getResult()
{
    return _Config;
}

CvPoint figura::getPuntos()
{
    return _Puntos;
}
