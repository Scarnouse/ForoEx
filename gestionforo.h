#include <iostream>
//#include "usuario.h"
//using namespace std;

#ifndef GESTIONFORO_H
#define GESTIONFORO_H


class GestionForo
{
public:
    GestionForo();
    void devolverForo();
    void devolverTema(int tema);
    void devolverHilo(int hilo);
};

#endif // GESTIONFORO_H
