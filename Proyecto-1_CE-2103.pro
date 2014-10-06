#-------------------------------------------------
#
# Project created by QtCreator 2014-09-23T13:21:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto-1_CE-2103
TEMPLATE = app

#Santi
INCLUDEPATH += C:\QtSDK\opencv\opencv-build\install\include
LIBS += -LC:\\QtSDK\opencv\\opencv-build\\bin \
    libopencv_videostab249d \
    libopencv_superres249d \
    libopencv_stitching249d \
    libopencv_nonfree249d \
    libopencv_ocl249d \
    libopencv_gpu249d \
    libopencv_photo249d \
    libopencv_objdetect249d \
    libopencv_video249d \
    libopencv_ml249d \
    libopencv_calib3d249d \
    libopencv_features2d249d \
    libopencv_highgui249d \
    libopencv_flann249d \
    libopencv_imgproc249d \
    libopencv_core249d \

#Rafa
#INCLUDEPATH += C:\QtSDK\opencv-build\install\include
#LIBS += -LC:\\QtSDK\\opencv-build\\bin \
#    libopencv_videostab249 \
#    libopencv_superres249 \
#    libopencv_stitching249 \
#    libopencv_nonfree249 \
#    libopencv_ocl249 \
#    libopencv_gpu249 \
#    libopencv_photo249 \
#    libopencv_objdetect249 \
#    libopencv_video249 \
#    libopencv_ml249 \
#    libopencv_calib3d249 \
#    libopencv_features2d249 \
#    libopencv_highgui249 \
#    libopencv_flann249 \
#    libopencv_imgproc249 \
#    libopencv_legacy249 \
#    libopencv_core249 \
#    libopencv_contrib249 \


SOURCES += main.cpp \
    ventanaPrincipal.cpp \
    reconstructorImagen.cpp \
    pixel.cpp \
    matrizPixeles.cpp \
    nodoPixel.cpp \
    listaPixel.cpp \
    figura.cpp \
    listaFigura.cpp \
    nodoFigura.cpp \
    CameraWidget.cpp \
    CameraWindow.cpp \
    ventanaAprendizaje.cpp \
    Facade.cpp \
    combinaciones.cpp \
    listacombinaciones.cpp \
    nodoCombinacion.cpp \
    NodoPunto.cpp \
    ListaPuntos.cpp

HEADERS  += \
    ventanaPrincipal.h \
    reconstructorImagen.h \
    pixel.h \
    matrizPixeles.h \
    nodoPixel.h \
    listaPixel.h \
    CVImageWidget.h \
    figura.h \
    listafigura.h \
    nodoFigura.h \
    CameraWidget.h \
    CameraWindow.h \
    ventanaAprendizaje.h \
    Facade.h \
    combinaciones.h \
    listacombinaciones.h \
    nodoCombinacion.h \
    NodoPunto.h \
    ListaPuntos.h

FORMS    += \
    ventanaPrincipal.ui \
    reconstructorImagen.ui \
    ventanaaprendizaje.ui

CONFIG += console

RESOURCES += \
    recursos.qrc
