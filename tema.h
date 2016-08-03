#include <string>
#include <vector>
#include "hilo.h"
#include "mensaje.h"
using namespace std;

#ifndef TEMA_H
#define TEMA_H

class Tema{
private:
    string denominacion;
    vector<Hilo>* hilos;
public:
    Tema(string denominacion):denominacion(denominacion){hilos = new vector<Hilo>;};
    ~Tema(){};
    int numHilos(){return hilos->size();};
    Hilo verHilo(int numHilo){return hilos->at(numHilo);};
    Hilo* nuevoHilo(string titulo, Mensaje* mensajeInicial);
    int numMensajes();
    vector<Hilo>* buscaHilos(string termino);
    vector<Hilo>* getVectorHilos(){return hilos;};
    string getDenominacion(){return denominacion;};
};

#endif // TEMA_H
