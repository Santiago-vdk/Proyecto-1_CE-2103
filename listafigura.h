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
    int getTamanio();
    nodoFigura *getPos(int i);
    nodoFigura *buscarIndice(int vertices);

    void setHead(nodoFigura *pHead);
    void setTail(nodoFigura *pTail);

    void insertarFinal(figura *nodo);


private:
    nodoFigura* _head=NULL;
    nodoFigura* _tail=NULL;
    int _tamanio;
};

#endif // LISTAFIGURA_H
