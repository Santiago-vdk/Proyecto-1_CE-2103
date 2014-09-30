#ifndef MATRIZPIXELES_H
#define MATRIZPIXELES_H
#include "listaPixel.h"
#include "pixel.h"

class matrizPixeles
{
public:
    matrizPixeles(int i, int j);
    ~matrizPixeles();
    void insertarPos(int i, int j, pixel *dato);

    listaPixel *getHead();
    listaPixel *getTail();
    pixel * getPos(int i, int j);
    void corregirMatriz();
    void recorrer1();
    void recorrer2();
    void recorrer3();
    void recorrer4();
    void pintar(int i, int j);
    bool HayBlancos();

    int getAnchoI();
    int getLargoJ();

private:
    listaPixel *_head=NULL;
    listaPixel *_tail=NULL;
    int _anchoI;
    int _largoJ;


};

#endif // MATRIZPIXELES_H
