#include "listaPixel.h"
#include <QDebug>

listaPixel::listaPixel()
{
}





void listaPixel::insertarFinal(pixel *nodo)
{
    nodoPixel *tmp = new nodoPixel(nodo);
    if(_head == NULL){
        _head = _tail = tmp;
    }
    else{
        _tail->setPixelNext(tmp);
        tmp->setPixelPrev(_tail);
        _tail = tmp;
    }
}









nodoPixel *listaPixel::getHead()
{
    return _head;
}

nodoPixel*listaPixel::getTail()
{
    return _tail;
}

listaPixel* listaPixel::getNext()
{
    return _next;
}

listaPixel* listaPixel::getPrev()
{
    return _prev;
}

void listaPixel::setHead(nodoPixel *pHead)
{
    _head = pHead;
}

void listaPixel::setTail(nodoPixel *pTail)
{
    _tail = pTail;
}

void listaPixel::setNext(listaPixel *pNext)
{
    _next = pNext;
}

void listaPixel::setPrev(listaPixel* pPrev)
{
    _prev = pPrev;
}


