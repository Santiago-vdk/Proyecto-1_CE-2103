#include "combinaciones.h"
#include <QDebug>

combinaciones::combinaciones()
{
    listaElementos=new listaFigura();
}

void combinaciones::insertarFigura(figura *nFigura)
{
    listaElementos->insertarFinal(nFigura);

}

int combinaciones::getCantidad()
{
    return listaElementos->getTamanio();
}

listaFigura *combinaciones::getListaElementos()
{
    return listaElementos;
}
