#include <QApplication>
#include <ventanaPrincipal.h>
#include "pixel.h"
#include <QDebug>
#include "matrizPixeles.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ventanaPrincipal w;
    w.show();
    return a.exec();
}
