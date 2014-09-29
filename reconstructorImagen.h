#ifndef RECONSTRUCTORIMAGEN_H
#define RECONSTRUCTORIMAGEN_H

#include <QWidget>
#include <string>
#include <cstdlib>
#include "pixel.h"
#include <matrizPixeles.h>



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
    void detectorFallos();

private:
    Ui::reconstructorImagen *ui;
    string _imagen;
    matrizPixeles *matrizLectura;


};

#endif // RECONSTRUCTORIMAGEN_H
