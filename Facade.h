#ifndef FACADE_H
#define FACADE_H
#include "listafigura.h"
#include "listaCombinaciones.h"
#include <string>
#include <opencv/cv.h>

using namespace std;

class Facade
{
public:
    Facade();
    ~Facade();
    bool recordar(int vertices);
    void aprender(int vertices,string nombre);
    void reaprender(int vertices,string nombre);
    string nombreRecuerdo(int posicion);
    int verticesRecuerdo(int posicion);
    int cantidadRecuerdos();
    void nuevaCombinacion();
    void agregarEnUltimaCombinacion(CvSeq *pResult, ListaPuntos *pPuntos);
    bool CombinacionCorrecta(int pPos);
    int getTamanioCombinaciones();
    listaFigura *getListaTemporal();
    void insertarListaTemporal(int vertices);
    combinaciones *getCombinacionEnPos(int pPos);



private:
    listaFigura *_memoria;
    listaCombinaciones *_combinaciones;
    listaFigura *_listaTemporal;


};

#endif // FACADE_H
