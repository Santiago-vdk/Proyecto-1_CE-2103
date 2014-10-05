#include "combinaciones.h"


combinaciones::combinaciones()
{
}

void combinaciones::insertarFigura(figura *nFigura)
{

    listaElementos->insertarFinal(nFigura);


}

int combinaciones::getCantidad()
{
    return listaElementos->getTamanio();
}

listaFigura combinaciones::getListaElementos()
{
    return *listaElementos;
}
