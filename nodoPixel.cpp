#include "nodoPixel.h"


nodoPixel::nodoPixel(pixel *dato)
{
    _dato = dato;

}

pixel *nodoPixel::getPixel()
{
    return _dato;
}

nodoPixel * nodoPixel::getPixelNext()
{
    return _next;
}

nodoPixel* nodoPixel::getPixelPrev()
{
    return _prev;
}

void nodoPixel::setPixelNext(nodoPixel* pPixelNext)
{
    _next = pPixelNext;
}

void nodoPixel::setPixelPrev(nodoPixel* pPixelPrev)
{
    _prev = pPixelPrev;
}

void nodoPixel::setDato(pixel* pDato)
{
    _dato = pDato;
}


