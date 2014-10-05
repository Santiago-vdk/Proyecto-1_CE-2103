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
    combinaciones(string pNombre,int pContador);
    void insertarFigura(figura *nFigura);
    string getNombre();
    int getContador();
private:
    string _Nombre;
    listaFigura *listaElementos; // guarda todas las figuras que contiene la combinacion
    int _Contador;


};

#endif // COMBINACIONES_H
