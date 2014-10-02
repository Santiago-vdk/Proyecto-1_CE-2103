#include "nodoFigura.h"

nodoFigura::nodoFigura(figura *dato)
{
    _dato = dato;

}

figura *nodoFigura::getFigura()
{
    return _dato;
}

nodoFigura * nodoFigura::getFiguraNext()
{
    return _next;
}

nodoFigura* nodoFigura::getFiguraPrev()
{
    return _prev;
}

void nodoFigura::setFiguraNext(nodoFigura* pFiguraNext)
{
    _next = pFiguraNext;
}

void nodoFigura::setFiguraPrev(nodoFigura* pFiguraPrev)
{
    _prev = pFiguraPrev;
}

void nodoFigura::setDato(figura* pDato)
{
    _dato = pDato;
}
