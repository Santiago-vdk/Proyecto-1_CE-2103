#ifndef NODOCOMBINACION_H
#define NODOCOMBINACION_H

#include <combinaciones.h>
class nodoCombinacion
{
public:
    nodoCombinacion(combinaciones *dato);
    combinaciones *getCombinaciones();
    nodoCombinacion* getCombinacionesNext();
    nodoCombinacion* getCombinacionesPrev();
    void setCombinacionesNext(nodoCombinacion *pCombinacionesNext);
    void setCombinacionesPrev(nodoCombinacion *pCombinacionesPrev);

    void setDato(combinaciones *pDato);

private:
    nodoCombinacion *_next=NULL;
    nodoCombinacion *_prev=NULL;
    combinaciones * _dato=NULL;


};

#endif // NODOCOMBINACION_H
