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
    int CantidadBlancos();

    int getAnchoI();
    int getLargoJ();

private:
    listaPixel *_head=NULL;
    listaPixel *_tail=NULL;
    int _anchoI;
    int _largoJ;

    int _recorrido1I;
    int _recorrido1J;
    int _recorrido2I;
    int _recorrido2J;
    int _recorrido3I;
    int _recorrido3J;
    int _recorrido4I;
    int _recorrido4J;


};

#endif // MATRIZPIXELES_H
