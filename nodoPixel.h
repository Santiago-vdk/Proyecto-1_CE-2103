#ifndef NODOPIXEL_H
#define NODOPIXEL_H

#include <pixel.h>

class nodoPixel
{
public:
    nodoPixel(pixel *dato);
    pixel * getPixel();
    nodoPixel* getPixelNext();
    nodoPixel* getPixelPrev();
    void setPixelNext(nodoPixel *pPixelNext);
    void setPixelPrev(nodoPixel *pPixelPrev);

    void setDato(pixel *pDato);
    pixel *getDato();

private:
    nodoPixel *_next=NULL;
    nodoPixel *_prev=NULL;
    pixel * _dato=NULL;

};

#endif // NODOPIXEL_H
