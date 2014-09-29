#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QDir>
#include <QString>
#include <reconstructorImagen.h>


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
    void on_pushButton_2_clicked();

    void popupCancelar();
    void popupCorregir();

private:
    Ui::ventanaPrincipal *ui;
    QDir directory;
    string imagen;
    reconstructorImagen *reconstructor;
    QWidget *popup;



};

#endif // VENTANAPRINCIPAL_H
