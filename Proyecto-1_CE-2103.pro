#-------------------------------------------------
#
# Project created by QtCreator 2014-09-23T13:21:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto-1_CE-2103
TEMPLATE = app


INCLUDEPATH += C:\QtSDK\opencv\opencv-build\install\include
#LIBS += "C:\QtSDK\opencv\opencv-build\bin\*.dll"
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

SOURCES += main.cpp \
    ventanaPrincipal.cpp \
    reconstructorImagen.cpp \
    pixel.cpp \
    matrizPixeles.cpp \
    nodoPixel.cpp \
    listaPixel.cpp

HEADERS  += \
    ventanaPrincipal.h \
    reconstructorImagen.h \
    pixel.h \
    matrizPixeles.h \
    nodoPixel.h \
    listaPixel.h \
    CVImageWidget.h

FORMS    += \
    ventanaPrincipal.ui \
    reconstructorImagen.ui

CONFIG += console

RESOURCES += \
    recursos.qrc
