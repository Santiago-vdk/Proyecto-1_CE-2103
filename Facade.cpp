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
    figura *forma=new figura(nombre,vertices);
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
    //combinaciones.insertarFigura();
}

void Facade::agregarEnUltimaCombinacion(CvSeq *pResult, CvPoint *pPuntos)
{

}

bool Facade::CombinacionCorrecta(int pPos, CvSeq results[])
{

}

