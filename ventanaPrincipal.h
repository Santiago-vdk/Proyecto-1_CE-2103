#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QDir>
#include <QString>


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



    void on_pushButton_2_clicked();

private:
    Ui::ventanaPrincipal *ui;
    QDir directory;
    string imagen;



};

#endif // VENTANAPRINCIPAL_H
