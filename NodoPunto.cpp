#include "NodoPunto.h"

NodoPunto::NodoPunto()
{
}

CvPoint *NodoPunto::getDato()
{
    return _dato;
}

NodoPunto *NodoPunto::getNext()
{
    return _next;
}

NodoPunto *NodoPunto::getPrev()
{
    return _prev;
}

void NodoPunto::setNext(NodoPunto *pNext)
{
    _next = pNext;
}

void NodoPunto::setPrev(NodoPunto *pPrev)
{
    _prev = pPrev;
}

void NodoPunto::setDato(CvPoint *pDato)
{
    _dato = pDato;
}
