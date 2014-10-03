#ifndef VENTANAAPRENDIZAJE_H
#define VENTANAAPRENDIZAJE_H

#include <QWidget>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <assert.h>
#include <QTextEdit>
#include <QLineEdit>
#include "CameraWindow.h"
#include "Facade.h"

using namespace std;
namespace Ui {
class ventanaAprendizaje;
}

class ventanaAprendizaje : public QWidget
{
    Q_OBJECT

public:
    explicit ventanaAprendizaje(QWidget *parent = 0, Facade* pFacade = NULL);
    ~ventanaAprendizaje();
    void procesadorImagen(string pUltimaImagen);
    void Aprender();
    void Decision();

public slots:
    void elSlot();


private slots:
    void on_botonEnviar_clicked();
    void interaccionPC();
    void on_botonNo_clicked();
    void on_botonSi_clicked();
    void on_botonRecuerdos_clicked();
    void interpretaImagenCompuesta();

signals:
    void procesamientoFinalizado();



private:
    Ui::ventanaAprendizaje *ui;
    QTextEdit *output;
    QLineEdit *input;
    CvCapture *camera;
    CameraWindow *windowCamara;
    Facade* _facade;
    int _vertices;
    string _figuraNombre;
    string comando;

    bool banderaComando;


};

#endif // VENTANAAPRENDIZAJE_H
