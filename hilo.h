#include "mensaje.h"
#include <string>
#include <vector>
#include "usuario.h"
using namespace std;

#ifndef HILO_H
#define HILO_H

class Hilo{
private:
    string titulo;
    vector<Mensaje> *mensajes;
public:
    Hilo(string titulo):titulo(titulo) {mensajes = new vector<Mensaje>;};
    ~Hilo(){};
    Mensaje* nuevoMensaje(string contenido, Usuario* usuario);
    int numeroMensajes(){return mensajes->size();};
    Mensaje verMensaje(int numMensaje){return mensajes->at(numMensaje);};
    string getTitulo(){return titulo;};
    vector<Mensaje> getVectorMensajes(){return *mensajes;};
};

#endif // HILO_H
