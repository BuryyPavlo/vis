QT += core
QT -= gui

CONFIG += c++11

TARGET = 12
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -O3

LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_viz -lopencv_core -lopencv_hal

SOURCES += main.cpp \
    compas.cpp \
    readlogfile.cpp \
    errormessage.cpp \
    orientation.cpp


HEADERS += \
    compas.h \
    readlogfile.h \
    errormessage.h \
    orientation.h
