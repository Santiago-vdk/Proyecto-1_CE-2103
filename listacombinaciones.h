#ifndef LISTACOMBINACIONES_H
#define LISTACOMBINACIONES_H

#include <combinaciones.h>
#include <nodoCombinacion.h>

class listaCombinaciones
{
public:
    listaCombinaciones();
    ~listaCombinaciones();

    nodoCombinacion *getHead();
    nodoCombinacion *getTail();
    int getTamanio();
    nodoCombinacion *getPos(int i);

    void setHead(nodoCombinacion *pHead);
    void setTail(nodoCombinacion *pTail);

    void insertarFinal(combinaciones *nodo);


private:
    nodoCombinacion* _head=NULL;
    nodoCombinacion* _tail=NULL;
    int _tamanio;

};

#endif // LISTACOMBINACIONES_H
