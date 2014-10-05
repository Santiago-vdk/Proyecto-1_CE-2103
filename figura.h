#ifndef FIGURA_H
#define FIGURA_H
#include <string>
#include <opencv/cv.h>

using namespace std;
class figura
{
public:
    figura(int pVertices,string pNombre);
    int getVertices();
    string getNombre();
    void setVertices(int vertices);
    void setNombre(string nombre);
    void setConfig(CvSeq *Config);
    void setPuntos(CvPoint *Puntos);
    CvPoint getPuntos();
    CvSeq getResult();



private:
    string _Nombre;
    int _Vertices;
    CvSeq *_Config;
    CvPoint *_Puntos;
};

#endif // FIGURA_H
