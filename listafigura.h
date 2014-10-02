#ifndef LISTAFIGURA_H
#define LISTAFIGURA_H

#include <nodoFigura.h>
#include <figura.h>

class listaFigura
{
public:
    listaFigura();
    ~listaFigura();

    nodoFigura *getHead();
    nodoFigura *getTail();
    listaFigura *getNext();
    listaFigura *getPrev();
    int getTamanio();
    nodoFigura *getPos(int i);

    void setHead(nodoFigura *pHead);
    void setTail(nodoFigura *pTail);
    void setNext(listaFigura *pNext);
    void setPrev(listaFigura *pPrev);

    void insertarFinal(figura *nodo);


private:
    nodoFigura* _head=NULL;
    nodoFigura* _tail=NULL;
    listaFigura* _next=NULL;
    listaFigura* _prev=NULL;
    int _tamanio;
};

#endif // LISTAFIGURA_H
