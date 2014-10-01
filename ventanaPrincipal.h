#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QDir>
#include <QString>
#include <reconstructorImagen.h>
#include <QPushButton>


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

private slots:
    void on_pushButton_clicked();
    void ventanaRevisado();
    void ventanaMostrado();
    void on_pushButton_2_clicked();

    void popupCancelar();
    void popupCorregir();

    void guardarImagen();

private:
    Ui::ventanaPrincipal *ui;
    QDir directory;
    string imagen;
    reconstructorImagen *reconstructor;
    QDialog *popupDialogReconstruir;
    QPushButton *botonCorregir;
    Mat _image;


};

#endif // VENTANAPRINCIPAL_H
