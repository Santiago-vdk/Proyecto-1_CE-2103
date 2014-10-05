#ifndef FACADE_H
#define FACADE_H
#include "listafigura.h"
#include "listacombinaciones.h"
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
    void agregarEnUltimaCombinacion(CvSeq *pResult,CvPoint *pPuntos);
    bool CombinacionCorrecta(int pPos,CvSeq results[]);



private:
    listaFigura *_memoria;
    listacombinaciones *_combinaciones;


};

#endif // FACADE_H
