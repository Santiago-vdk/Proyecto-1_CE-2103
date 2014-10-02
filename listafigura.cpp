#include "listaFigura.h"
#include <QDebug>

listaFigura::listaFigura()
{
    _tamanio=0;
}

listaFigura::~listaFigura()
{
    for(int i=0;i<_tamanio;i++){
        nodoFigura *tmp=_head;
        _head=_head->getFiguraNext();
        delete tmp;
    }
}





void listaFigura::insertarFinal(figura *nodo)
{
    nodoFigura *tmp = new nodoFigura(nodo);
    if(_head == NULL){
        _head = _tail = tmp;
    }
    else{
        _tail->setFiguraNext(tmp);
        tmp->setFiguraPrev(_tail);
        _tail = tmp;
    }
    _tamanio++;
}









nodoFigura *listaFigura::getHead()
{
    return _head;
}

nodoFigura*listaFigura::getTail()
{
    return _tail;
}

int listaFigura::getTamanio()
{
    return _tamanio;
}

nodoFigura *listaFigura::getPos(int i)
{
    nodoFigura *tmp= _head;
    for(int a=0;a<i;a++){
        tmp=tmp->getFiguraNext();
    }
    return tmp;
}

nodoFigura *listaFigura::buscarIndice(int vertices)
{
    nodoFigura *tmp= _head;
    while((tmp!=NULL)&&(tmp->getFigura()->getVertices()!=vertices)){
        tmp=tmp->getFiguraNext();
    }
    return tmp;
}

void listaFigura::setHead(nodoFigura *pHead)
{
    _head = pHead;
}

void listaFigura::setTail(nodoFigura *pTail)
{
    _tail = pTail;
}

