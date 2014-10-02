#ifndef FACADE_H
#define FACADE_H
#include "listafigura.h"
#include <string>

using namespace std;

class Facade
{
public:
    Facade();
    ~Facade();
    bool recordar(int vertices);
    void aprender(int vertices,string nombre);
    void reaprender(int vertices,string nombre);


private:
    listaFigura *_memoria;

};

#endif // FACADE_H
