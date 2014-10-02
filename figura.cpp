#include "figura.h"

figura::figura(string pNombre, int pVertices)
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

