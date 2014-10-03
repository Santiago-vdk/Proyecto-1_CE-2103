#-------------------------------------------------
#
# Project created by QtCreator 2014-10-02T22:13:20
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Prueba4
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
INCLUDEPATH += C:\QtSDK\opencv-build\install\include
LIBS += -LC:\\QtSDK\\opencv-build\\bin \
    libopencv_videostab249 \
    libopencv_superres249 \
    libopencv_stitching249 \
    libopencv_nonfree249 \
    libopencv_ocl249 \
    libopencv_gpu249 \
    libopencv_photo249 \
    libopencv_objdetect249 \
    libopencv_video249 \
    libopencv_ml249 \
    libopencv_calib3d249 \
    libopencv_features2d249 \
    libopencv_highgui249 \
    libopencv_flann249 \
    libopencv_imgproc249 \
    libopencv_legacy249 \
    libopencv_core249 \
    libopencv_contrib249 \
