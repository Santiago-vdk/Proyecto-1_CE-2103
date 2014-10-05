#include "nodoCombinacion.h"

nodoCombinacion::nodoCombinacion(combinaciones *dato)
{
    _dato = dato;

}

combinaciones *nodoCombinacion::getCombinaciones()
{
    return _dato;
}

nodoCombinacion * nodoCombinacion::getCombinacionesNext()
{
    return _next;
}

nodoCombinacion* nodoCombinacion::getCombinacionesPrev()
{
    return _prev;
}

void nodoCombinacion::setCombinacionesNext(nodoCombinacion* pCombinacionesNext)
{
    _next = pCombinacionesNext;
}

void nodoCombinacion::setCombinacionesPrev(nodoCombinacion* pCombinacionesPrev)
{
    _prev = pCombinacionesPrev;
}

void nodoCombinacion::setDato(combinaciones * pDato)
{
    _dato = pDato;
}
