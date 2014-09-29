#ifndef LISTAPIXEL_H
#define LISTAPIXEL_H
#include <nodoPixel.h>

#include <pixel.h>

class listaPixel
{
public:
    listaPixel();

    nodoPixel *getHead();
    nodoPixel *getTail();
    listaPixel *getNext();
    listaPixel *getPrev();

    void setHead(nodoPixel *pHead);
    void setTail(nodoPixel *pTail);
    void setNext(listaPixel *pNext);
    void setPrev(listaPixel *pPrev);

    void insertarFinal(pixel *nodo);
    void borrarPos(int i);


private:
    nodoPixel* _head=NULL;
    nodoPixel* _tail=NULL;
    listaPixel* _next=NULL;
    listaPixel* _prev=NULL;
};

#endif // LISTAPIXEL_H
