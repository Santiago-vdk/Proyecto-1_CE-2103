#ifndef RECONSTRUCTORIMAGEN_H
#define RECONSTRUCTORIMAGEN_H

#include <QWidget>
#include <string>
#include <cstdlib>
#include "pixel.h"
#include <matrizPixeles.h>
#include <QProgressBar>



using namespace std;

namespace Ui {
class reconstructorImagen;
}

class reconstructorImagen : public QWidget
{
    Q_OBJECT

public:
    explicit reconstructorImagen(QWidget *parent = 0, string pImagen = "");
    ~reconstructorImagen();
    void descomponerImagen();
    bool detectorFallos();
    int getErrores();
    bool arreglarImagen();



private:
    Ui::reconstructorImagen *ui;
    string _imagen;
    matrizPixeles *matrizLectura;
    int _errores = 0;



};

#endif // RECONSTRUCTORIMAGEN_H
