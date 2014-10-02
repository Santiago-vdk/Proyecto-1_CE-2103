#ifndef VENTANAAPRENDIZAJE_H
#define VENTANAAPRENDIZAJE_H

#include <QWidget>

namespace Ui {
class ventanaAprendizaje;
}

class ventanaAprendizaje : public QWidget
{
    Q_OBJECT

public:
    explicit ventanaAprendizaje(QWidget *parent = 0);
    ~ventanaAprendizaje();

private:
    Ui::ventanaAprendizaje *ui;
};

#endif // VENTANAAPRENDIZAJE_H
