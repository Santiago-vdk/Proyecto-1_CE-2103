#include "Facade.h"
#include "listafigura.h"

#include <QDebug>

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
   qDebug() << QString::fromStdString (nombre) ;
    figura *forma=new figura(vertices,nombre);
    _memoria->insertarFinal(forma);
}

void Facade::reaprender(int vertices, string nombre)
{
    _memoria->buscarIndice(vertices)->getFigura()->setNombre(nombre);
}

string Facade::nombreRecuerdo(int posicion)
{
    return _memoria->getPos(posicion)->getFigura()->getNombre();
}

int Facade::verticesRecuerdo(int posicion)
{
    return _memoria->getPos(posicion)->getFigura()->getVertices();
}

int Facade::cantidadRecuerdos()
{
    return _memoria->getTamanio();
}

void Facade::nuevaCombinacion()
{
    _combinaciones->insertarFinal(new combinaciones());
}

void Facade::agregarEnUltimaCombinacion(CvSeq *pResult, CvPoint *pPuntos)
{
    _combinaciones->getTail()->getCombinaciones()->insertarFigura(new figura(pResult->total,""));
    _combinaciones->getTail()->getCombinaciones()->getListaElementos().getTail()->getFigura()->setConfig(pResult);
    _combinaciones->getTail()->getCombinaciones()->getListaElementos().getTail()->getFigura()->setPuntos(pPuntos);
}

bool Facade::CombinacionCorrecta(int pPos)//modificar
{
    int cantidad=_combinaciones->getPos(pPos)->getCombinaciones()->getCantidad();

    return true;
}

int Facade::getTamanioCombinaciones()
{
 _combinaciones->getTamanio();
}

