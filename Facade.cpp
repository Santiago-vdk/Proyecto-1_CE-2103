#include "Facade.h"
#include "listafigura.h"

Facade::Facade()
{
    _memoria=new listaFigura();
}

Facade::~Facade()
{
    delete _memoria;
}

bool Facade::recordar(int vertices)
{
    if(_memoria->buscarIndice(vertices)!=NULL){
        return true;
    }
    else{
        return false;
    }
}

void Facade::aprender(int vertices, string nombre)
{
    figura *forma=new figura(nombre,vertices);
    _memoria->insertarFinal(forma);
}

void Facade::reaprender(int vertices, string nombre)
{
    _memoria->buscarIndice(vertices)->getFigura()->setNombre(nombre);
}

