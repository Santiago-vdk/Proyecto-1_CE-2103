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

    int getAnchoI();
    int getLargoJ();

private:
    listaPixel *_head=NULL;
    listaPixel *_tail=NULL;
    int _anchoI;
    int _largoJ;


};

#endif // MATRIZPIXELES_H
