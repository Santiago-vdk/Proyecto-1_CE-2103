#ifndef FIGURA_H
#define FIGURA_H
#include <string>
#include <opencv/cv.h>
#include "ListaPuntos.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <assert.h>
#include "opencv2/core/core.hpp"

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
    void setPuntos(ListaPuntos *Puntos);
    ListaPuntos *getPuntos();
    CvSeq *getResult();



private:
    string _Nombre;
    int _Vertices;
    CvSeq *_Config;
    ListaPuntos *_Puntos;
};

#endif // FIGURA_H
