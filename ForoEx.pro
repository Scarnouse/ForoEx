TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fecha.cpp \
    hilo.cpp \
    tema.cpp \
    foro.cpp \
    gestionforo.cpp

HEADERS += \
    mensaje.h \
    usuario.h \
    fecha.h \
    hilo.h \
    tema.h \
    foro.h \
    gestionforo.h
