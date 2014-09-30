#include "matrizPixeles.h"
#include "listaPixel.h"
#include <QDebug>
#include "pixel.h"
#include <iostream>

using namespace std;

matrizPixeles::matrizPixeles(int i, int j)
{
    _anchoI = i;
    _largoJ = j;
    listaPixel *tmp = new listaPixel();
    _head = tmp;
    for(int a = 0; a < i; a++){
        for(int b = 0; b < j; b++){
            tmp->insertarFinal(NULL);
        }

        listaPixel *tmp2 = new listaPixel();
        tmp->setNext(tmp2);
        tmp2->setPrev(tmp);
        tmp=tmp2;
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

void matrizPixeles::corregirMatriz()
{
    int i=0;
    while(HayBlancos()){
        if(i==0){
            recorrer1();
            i++;
        }
        if(i==1){
            recorrer2();
            i++;
        }
        if(i==2){
            recorrer3();
            i++;
        }
        else{
            recorrer4();
            i==0;
        }
    }
}

void matrizPixeles::recorrer1()
{
    int i=0;
    int j=0;
    while((i<_anchoI)&& !(getPos(i,j)->esBlanco())){
        while((j<_largoJ)&& !(getPos(i,j)->esBlanco())){
            j++;
        }
        i++;
    }
    pintar(i,j);
}
void matrizPixeles::recorrer2()
{
    int i=0;
    int j=_largoJ-1;
    while((i<_anchoI)&& !(getPos(i,j)->esBlanco())){
        while((j>-1)&& !(getPos(i,j)->esBlanco())){
            j--;
        }
        i++;
    }
    pintar(i,j);
}
void matrizPixeles::recorrer3()
{
    int i=_anchoI-1;
    int j=0;
    while((i>-1)&& !(getPos(i,j)->esBlanco())){
        while((j<_largoJ)&& !(getPos(i,j)->esBlanco())){
            j++;
        }
        i--;
    }
    pintar(i,j);
}
void matrizPixeles::recorrer4()
{
    int i=_anchoI-1;
    int j=_largoJ-1;
    while((i>-1)&& !(getPos(i,j)->esBlanco())){
        while((j>-1)&& !(getPos(i,j)->esBlanco())){
            j--;
        }
        i--;
    }
    pintar(i,j);
}

void matrizPixeles::pintar(int i, int j)
{
    listaPixel adyacentesNoBlancos=new listaPixel();
    if((i>0) && (!getPos(i-1,j)->esBlanco())){
        adyacentesNoBlancos.insertarFinal(getPos(i-1,j));
    }
    if((i<_anchoI-1) && (!getPos(i+1,j)->esBlanco())){
        adyacentesNoBlancos.insertarFinal(getPos(i+1,j));
    }
    if((j>0) && (!getPos(j-1,j)->esBlanco())){
        adyacentesNoBlancos.insertarFinal(getPos(j-1,j));
    }
    if((j<_largoJ-1)&&(!getPos(j+1,j)->esBlanco())){
        adyacentesNoBlancos.insertarFinal(getPos(j+1,j));
    }
    int red=0;
    int green=0;
    int blue=0;
    for(int i=0;i<adyacentesNoBlancos.getTamanio();i++){
        red+=adyacentesNoBlancos.getPos(i);
        green+=adyacentesNoBlancos.getPos(i);
        blue+=adyacentesNoBlancos.getPos(i);
    }
    red=(red/adyacentesNoBlancos.getTamanio());
    green=(green/adyacentesNoBlancos.getTamanio());
    blue=(blue/adyacentesNoBlancos.getTamanio());


    getPos(i,j)->setRed(red);
    getPos(i,j)->setGreen(green);
    getPos(i,j)->setBlue(blue);
}

bool matrizPixeles::HayBlancos()
{
    for(int i =0;i<_anchoI;i++){
        for(int j =0;i<_largoJ;j++){
            if(getPos(i,j)->esBlanco()){
                return true;
            }
        }
        return false;
    }
}

int matrizPixeles::getAnchoI()
{
    return _anchoI;
}

int matrizPixeles::getLargoJ()
{
    return _largoJ;
}


