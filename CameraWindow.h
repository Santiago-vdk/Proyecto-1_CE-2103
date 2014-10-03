#ifndef CAMERAWINDOW_H
#define CAMERAWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <CameraWidget.h>


using namespace std;
class CameraWindow : public QWidget
{
    Q_OBJECT
public:
    CameraWindow(CvCapture *camera, QWidget *parent=0);
    std::string getultimaImagen();
    bool getBanderaTomada();

private:
    CameraWidget *m_cvwidget;
    CvCapture *m_camera;
    int m_photoCounter;
    std::string _ultimaImagen;

    QPushButton *botonInterpretar;

    bool imagenTomada;

signals:
    void guardeImagen();
    void interpretaImagen();


protected:
    void timerEvent(QTimerEvent*);

public slots:
    void savePicture(void);
    void interpretarImagen(void);

};

#endif
