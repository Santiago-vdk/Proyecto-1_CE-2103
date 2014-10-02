#include "matrizPixeles.h"
#include "listaPixel.h"
#include "nodoPixel.h"
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
    nodoPixel *tmp2 = tmp->getHead();
    for(int b = 0; b < j; b++){
        tmp2 = tmp2->getPixelNext();
    }
    return tmp2->getPixel();
}

void matrizPixeles::corregirMatriz()
{
    int i=0;
    int contador=CantidadBlancos();
    _recorrido1I = 0;
    _recorrido1J = 0;
    _recorrido2I = 0;
    _recorrido2J = _largoJ-1;
    _recorrido3I = _anchoI-1;
    _recorrido3J = 0;
    _recorrido4I = _anchoI-1;
    _recorrido4J = _largoJ-1;
    _recorrido5I = 0;
    _recorrido5J = 0;
    _recorrido6I = 0;
    _recorrido6J = _largoJ-1;
    _recorrido7I = _anchoI-1;
    _recorrido7J = 0;
    _recorrido8I = _anchoI-1;
    _recorrido8J = _largoJ-1;

    while(contador>0){
        if(i==0){
            recorrer1();
            i++;
        }
        else{
            if(i==1){
                recorrer2();
                i++;
            }
            else{

             if(i==2){

                recorrer3();
                i++;
            }
             else{
             if(i==3){
                recorrer4();
                i++;
            }
             else{
                 if(i==4){
                    recorrer5();
                    i++;
                }
                 else{
                     if(i==5){
                        recorrer6();
                        i++;
                    }
                     else{
                         if(i==6){
                            recorrer7();
                            i++;
                        }
                         else{
                             if(i==7){
                                recorrer8();
                                i=0;
                            }
                         }
                     }
                 }
             }


             }
            }
    }
        contador--;
    }

}

void matrizPixeles::recorrer1()
{
    while(_recorrido1I<_anchoI){
        while(_recorrido1J<_largoJ){
            if(getPos(_recorrido1I,_recorrido1J)->esBlanco()){
                break;
            }
           _recorrido1J++;

        }

        if((_recorrido1J<_largoJ)&&(getPos(_recorrido1I,_recorrido1J)->esBlanco())){

            break;
        }
        _recorrido1I++;
        _recorrido1J =0 ;
    }

    pintar(_recorrido1I,_recorrido1J);
}
void matrizPixeles::recorrer2()
{

    while(_recorrido2I<_anchoI){
        while(_recorrido2J>-1){
            if(getPos(_recorrido2I,_recorrido2J)->esBlanco()){

                break;
            }
            _recorrido2J--;

        }

        if((_recorrido2J>-1)&&(getPos(_recorrido2I,_recorrido2J)->esBlanco())){

            break;
        }
        _recorrido2I++;
        _recorrido2J =_largoJ-1;
    }
    pintar(_recorrido2I,_recorrido2J);
}
void matrizPixeles::recorrer3()
{
    while(_recorrido3I>-1){
        while(_recorrido3J<_largoJ){
            if(getPos(_recorrido3I,_recorrido3J)->esBlanco()){

                break;
            }
            _recorrido3J++;

        }

        if((_recorrido3J<_largoJ)&&(getPos(_recorrido3I,_recorrido3J)->esBlanco())){

            break;
        }
        _recorrido3I--;
        _recorrido3J =0;
    }
    pintar(_recorrido3I,_recorrido3J);
}
void matrizPixeles::recorrer4()
{
    while(_recorrido4I>-1){
        while(_recorrido4J>-1){
            if(getPos(_recorrido4I,_recorrido4J)->esBlanco()){
                break;
            }
            _recorrido4J--;

        }

        if((_recorrido4J>-1)&&(getPos(_recorrido4I,_recorrido4J)->esBlanco())){
            break;
        }
        _recorrido4I--;
        _recorrido4J =_largoJ-1;
    }
    pintar(_recorrido4I,_recorrido4J);
}

void matrizPixeles::recorrer5()
{
    while(_recorrido5J<_largoJ-1){
        while(_recorrido5I<_anchoI-1){
            if(getPos(_recorrido5I,_recorrido5J)->esBlanco()){
                break;
            }
            _recorrido5I++;

        }

        if((_recorrido5I<_anchoI-1)&&(getPos(_recorrido5I,_recorrido5J)->esBlanco())){
            break;
        }
        _recorrido5J++;
        _recorrido5I =0;
    }
    pintar(_recorrido5I,_recorrido5J);
}

void matrizPixeles::recorrer6()
{
    while(_recorrido6J>-1){
        while(_recorrido6I<_anchoI-1){
            if(getPos(_recorrido6I,_recorrido6J)->esBlanco()){
                break;
            }
            _recorrido6I++;

        }

        if((_recorrido6I>-1)&&(getPos(_recorrido6I,_recorrido6J)->esBlanco())){
            break;
        }
        _recorrido6J--;
        _recorrido6I =0;
    }
    pintar(_recorrido6I,_recorrido6J);
}

void matrizPixeles::recorrer7()
{
    while(_recorrido7J<_anchoI-1){
        while(_recorrido7I>-1){
            if(getPos(_recorrido7I,_recorrido7J)->esBlanco()){
                break;
            }
            _recorrido7I--;

        }

        if((_recorrido7I>-1)&&(getPos(_recorrido7I,_recorrido7J)->esBlanco())){
            break;
        }
        _recorrido7J++;
        _recorrido7I =_anchoI-1;
    }
    pintar(_recorrido7I,_recorrido7J);
}

void matrizPixeles::recorrer8()
{
    while(_recorrido8J>-1){
        while(_recorrido8I>-1){
            if(getPos(_recorrido8I,_recorrido8J)->esBlanco()){
                break;
            }
            _recorrido8I--;

        }

        if((_recorrido8I>-1)&&(getPos(_recorrido8I,_recorrido8J)->esBlanco())){
            break;
        }
        _recorrido8J--;
        _recorrido8I =_anchoI-1;
    }
    pintar(_recorrido8I,_recorrido8J);
}


void matrizPixeles::pintar(int i, int j)
{

    listaPixel * adyacentesNoBlancos = new listaPixel();
    if((i>0) && !(getPos(i-1,j)->esBlanco())){
        adyacentesNoBlancos->insertarFinal(getPos(i-1,j));
    }
    if((i<_anchoI-1) && !(getPos(i+1,j)->esBlanco())){
        adyacentesNoBlancos->insertarFinal(getPos(i+1,j));
    }
    if((j>0) && !(getPos(i,j-1)->esBlanco())){
        adyacentesNoBlancos->insertarFinal(getPos(i,j-1));
    }
    if((j<_largoJ-1)&&!(getPos(i,j+1)->esBlanco())){
        adyacentesNoBlancos->insertarFinal(getPos(i,j+1));
    }

    if((i>0)&&(j>0)&&!(getPos(i-1,j-1)->esBlanco())){
        adyacentesNoBlancos->insertarFinal(getPos(i-1,j-1));
    }
    if((i>0)&&(j<_largoJ-1)&&!(getPos(i-1,j+1)->esBlanco())){
        adyacentesNoBlancos->insertarFinal(getPos(i-1,j+1));
    }
    if((i<_anchoI-1)&&(j>0)&&!(getPos(i+1,j-1)->esBlanco())){
        adyacentesNoBlancos->insertarFinal(getPos(i+1,j-1));
    }
    if((i<_anchoI-1)&&(j<_largoJ-1)&&!(getPos(i-1,j+1)->esBlanco())){
        adyacentesNoBlancos->insertarFinal(getPos(i-1,j+1));
    }


    int red=0;
    int green=0;
    int blue=0;
    for(int a=0;a<adyacentesNoBlancos->getTamanio();a++){
        //std::cout <<"red"<<adyacentesNoBlancos->getPos(a)->getPixel()->getRed() << std::endl;
        if(adyacentesNoBlancos->getPos(a)->getPixel()->getRed()<245){
        red+=adyacentesNoBlancos->getPos(a)->getPixel()->getRed();
        }
        if(adyacentesNoBlancos->getPos(a)->getPixel()->getGreen()<245){
        green+=adyacentesNoBlancos->getPos(a)->getPixel()->getGreen();
        }
        if(adyacentesNoBlancos->getPos(a)->getPixel()->getBlue()<245){
        blue+=adyacentesNoBlancos->getPos(a)->getPixel()->getBlue();
        }
    }
    //std::cout <<"total"<< red <<","<<green<<","<<blue<<  std::endl;
    std::cout <<"adyacentes"<<adyacentesNoBlancos->getTamanio()<< std::endl;

    red=(red/(adyacentesNoBlancos->getTamanio()));
    green=(green/(adyacentesNoBlancos->getTamanio()));
    blue=(blue/(adyacentesNoBlancos->getTamanio()));


    getPos(i,j)->setRed(red);
    getPos(i,j)->setGreen(green);
    getPos(i,j)->setBlue(blue);
    delete adyacentesNoBlancos;
}

int matrizPixeles::CantidadBlancos()
{
    int contador=0;
    for(int i =0;i<_anchoI;i++){
        for(int j =0;j<_largoJ;j++){
            if(getPos(i,j)->esBlanco()){
                //qDebug()<<"contador: " << contador;
                contador++;
            }
        }
    }
    return contador;
}

int matrizPixeles::getAnchoI()
{
    return _anchoI;
}

int matrizPixeles::getLargoJ()
{
    return _largoJ;
}


