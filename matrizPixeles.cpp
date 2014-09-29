#include "matrizPixeles.h"
#include "listaPixel.h"
#include <QDebug>
#include "pixel.h"

matrizPixeles::matrizPixeles(int i, int j)
{
    listaPixel *tmp = new listaPixel();
    _head = tmp;
    for(int a = 0; a < i; a++){
        for(int b = 0; b < j; b++){
            tmp->insertarFinal(NULL);
        }

        listaPixel *tmp2 = new listaPixel();
        tmp = tmp2;
    }
    delete tmp->getNext();
    tmp->setNext(NULL);
}

matrizPixeles::~matrizPixeles()
{
    listaPixel *tmp=_head->getNext();
    delete _head;
    while(tmp!=NULL){
        _head=tmp;
        tmp=tmp->getNext();
        delete _head;
    }
}

void matrizPixeles::insertarPos(int i, int j, pixel *dato)
{
    listaPixel *tmp = _head;
    for(int a = 0; a < i; a++){
        tmp = tmp->getNext();
    }
    nodoPixel *tmp2 = (*tmp).getHead();
    for(int b = 0; b < j; b++){
        tmp2 = tmp2->getPixelNext();
    }
    tmp2->setDato(dato);
}

pixel *matrizPixeles::getPos(int i, int j)
{
    listaPixel *tmp = _head;
    for(int a = 0; a < i; a++){
        tmp = tmp->getNext();
    }
    nodoPixel *tmp2 = (*tmp).getHead();
    for(int b = 0; b < j; b++){
        tmp2 = tmp2->getPixelNext();
    }
    return tmp2->getDato();
}


