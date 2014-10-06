#ifndef LISTAPUNTOS_H
#define LISTAPUNTOS_H
#include "NodoPunto.h"
#include <opencv/cv.h>

class ListaPuntos
{
public:
    ListaPuntos();
    ~ListaPuntos();
    NodoPunto *getHead();
    NodoPunto *getTail();
    void insertarDato(CvPoint *pDato);
    CvPoint *getDatoEnPos(int i);

private:
    NodoPunto *_Head;
    NodoPunto *_Tail;
    int _Tamanio;
};

#endif // LISTAPUNTOS_H
