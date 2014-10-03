#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QDir>
#include <QString>
#include <reconstructorImagen.h>
#include <QPushButton>

#include <Facade.h>


using namespace std;

namespace Ui {
class ventanaPrincipal;
}

class ventanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaPrincipal(QWidget *parent = 0);
    ~ventanaPrincipal();
    void nuevaReconstruccion();

private slots:
    void on_pushButton_clicked();
    void ventanaRevisado();
    void ventanaMostrado();
    void on_pushButton_2_clicked();

    void popupCancelar();
    void popupCorregir();

    void guardarImagen();

    void on_buttonAprendizaje_clicked();

    void nuevaImagen();



private:
    Ui::ventanaPrincipal *ui;
    QDir directory;
    string imagen;
    reconstructorImagen *reconstructor;
    QDialog *popupDialogReconstruir;
    QPushButton *botonCorregir;
    Mat _image;
    QMainWindow *ventanaReconstructor;
    bool banderaPrimeraCorrida;
    bool banderaGuardado;
    Facade *facade;


};

#endif // VENTANAPRINCIPAL_H
