#ifndef NODOFIGURA_H
#define NODOFIGURA_H
#include <figura.h>

class nodoFigura
{
public:
    nodoFigura(figura *dato);
    figura *getFigura();
    nodoFigura* getFiguraNext();
    nodoFigura* getFiguraPrev();
    void setFiguraNext(nodoFigura *pFiguraNext);
    void setFiguraPrev(nodoFigura *pFiguraPrev);

    void setDato(figura *pDato);

private:
    nodoFigura *_next=NULL;
    nodoFigura *_prev=NULL;
    figura * _dato=NULL;


};

#endif // NODOFIGURA_H
