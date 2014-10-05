#include "combinaciones.h"


combinaciones::combinaciones(string pNombre,int pContador)
{
    _Nombre=pNombre;
    _Contador=pContador;
}

void combinaciones::insertarFigura(figura *nFigura)
{

    listaElementos->insertarFinal(nFigura);


}

string combinaciones::getNombre()
{
   return  _Nombre;
}

int combinaciones::getContador()
{
    return _Contador;
}
