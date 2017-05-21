TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Exception.cpp

HEADERS += \
    Singleton.h \
    SmartPointer.h \
    Exception.h
