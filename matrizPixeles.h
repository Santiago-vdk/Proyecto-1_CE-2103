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
    void recorrer5();
    void recorrer6();
    void recorrer7();
    void recorrer8();
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
    int _recorrido5I;
    int _recorrido5J;
    int _recorrido6I;
    int _recorrido6J;
    int _recorrido7I;
    int _recorrido7J;
    int _recorrido8I;
    int _recorrido8J;


};

#endif // MATRIZPIXELES_H
