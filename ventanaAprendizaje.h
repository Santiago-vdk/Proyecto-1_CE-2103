#ifndef VENTANAAPRENDIZAJE_H
#define VENTANAAPRENDIZAJE_H

#include <QWidget>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <assert.h>
#include <QTextEdit>
#include <QLineEdit>
#include "CameraWindow.h"

using namespace std;
namespace Ui {
class ventanaAprendizaje;
}

class ventanaAprendizaje : public QWidget
{
    Q_OBJECT

public:
    explicit ventanaAprendizaje(QWidget *parent = 0);
    ~ventanaAprendizaje();
    void procesadorImagen(string pUltimaImagen);

public slots:
    void elSlot();

private slots:
    void on_botonEnviar_clicked();


private:
    Ui::ventanaAprendizaje *ui;
    QTextEdit *output;
    QLineEdit *input;
    CvCapture *camera;
    CameraWindow *windowCamara;


};

#endif // VENTANAAPRENDIZAJE_H
