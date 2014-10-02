#ifndef FIGURA_H
#define FIGURA_H
#include <string>

using namespace std;
class figura
{
public:
    figura(string pNombre, int pVertices);
    int getVertices();
    string getNombre();
    void setVertices(int vertices);
    void setNombre(string nombre);



private:
    string _Nombre;
    int _Vertices;
};

#endif // FIGURA_H
