#ifndef COMBINACIONES_H
#define COMBINACIONES_H
#include <string>
#include <listafigura.h>
#include <Figura.h>
#include <nodofigura.h>
using namespace std;
class combinaciones
{
public:
    combinaciones();
    void insertarFigura(figura *nFigura);
    int getCantidad();
    listaFigura *getListaElementos();


private:
    listaFigura *listaElementos; // guarda todas las figuras que contiene la combinacion


};

#endif // COMBINACIONES_H
