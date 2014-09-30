#ifndef LISTAPIXEL_H
#define LISTAPIXEL_H
#include <nodoPixel.h>

#include <pixel.h>

class listaPixel
{
public:
    listaPixel();
    ~listaPixel();

    nodoPixel *getHead();
    nodoPixel *getTail();
    listaPixel *getNext();
    listaPixel *getPrev();
    int getTamanio();
    nodoPixel *getPos(int i);

    void setHead(nodoPixel *pHead);
    void setTail(nodoPixel *pTail);
    void setNext(listaPixel *pNext);
    void setPrev(listaPixel *pPrev);

    void insertarFinal(pixel *nodo);


private:
    nodoPixel* _head=NULL;
    nodoPixel* _tail=NULL;
    listaPixel* _next=NULL;
    listaPixel* _prev=NULL;
    int _tamanio=0;
};

#endif // LISTAPIXEL_H
