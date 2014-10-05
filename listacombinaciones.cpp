#include "listacombinaciones.h"
#include <QDebug>

listaCombinaciones::listaCombinaciones()
{
    _tamanio=0;
}

listaCombinaciones::~listaCombinaciones()
{
    for(int i=0;i<_tamanio;i++){
        nodoCombinacion *tmp=_head;
        _head=_head->getCombinacionesNext();
        delete tmp;
    }
}





void listaCombinaciones::insertarFinal(combinaciones *nodo)
{
    nodoCombinacion *tmp = new nodoCombinacion(nodo);
    if(_head == NULL){
        _head = _tail = tmp;
    }
    else{
        _tail->setCombinacionesNext(tmp);
        tmp->setCombinacionesPrev(_tail);
        _tail = tmp;
    }
    _tamanio++;
}









nodoCombinacion *listaCombinaciones::getHead()
{
    return _head;
}

nodoCombinacion*listaCombinaciones::getTail()
{
    return _tail;
}

int listaCombinaciones::getTamanio()
{
    return _tamanio;
}

nodoCombinacion *listaCombinaciones::getPos(int i)
{
    nodoCombinacion *tmp= _head;
    for(int a=0;a<i;a++){
        tmp=tmp->getCombinacionesNext();
    }
    return tmp;
}

nodoCombinacion * listaCombinaciones::buscarIndice(int vertices)
{
    nodoCombinacion *tmp= _head;
    while((tmp!=NULL)&&(tmp->getCombinaciones()->getContador()!=vertices)){
        tmp=tmp->getCombinacionesNext();
    }
    return tmp;
}

void listaCombinaciones::setHead(nodoCombinacion *pHead)
{
    _head = pHead;
}

void listaCombinaciones::setTail(nodoCombinacion *pTail)
{
    _tail = pTail;
}
