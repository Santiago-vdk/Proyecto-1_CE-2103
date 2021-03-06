#include "toolbar.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>


Toolbar::Toolbar(QWidget *parent)
    : QMainWindow(parent)
{
  QPixmap newpix("C:/new.png");
  QPixmap openpix("C:/open.png");
  QPixmap quitpix("C:/quit.png");

  QToolBar *toolbar = addToolBar("main toolbar");
  toolbar->addAction(QIcon(newpix), "New File");
  toolbar->addAction(QIcon(openpix), "Open File");
  toolbar->addSeparator();
  QAction *quit = toolbar->addAction(QIcon(quitpix),
      "Quit Application");

  connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
