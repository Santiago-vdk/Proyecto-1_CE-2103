#include "listaPixel.h"
#include <QDebug>

listaPixel::listaPixel()
{
    _tamanio=0;
}

listaPixel::~listaPixel()
{
    for(int i=0;i<_tamanio;i++){
        nodoPixel *tmp=_head;
        _head=_head->getPixelNext();
        delete tmp;
    }
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
    _tamanio++;
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

int listaPixel::getTamanio()
{
    return _tamanio;
}

nodoPixel *listaPixel::getPos(int i)
{
    nodoPixel *tmp= _head;
    for(int a=0;a<i;a++){
        tmp=tmp->getPixelNext();
    }
    return tmp;
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


