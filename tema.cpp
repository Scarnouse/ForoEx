#include "tema.h"
#include "hilo.h"
#include "mensaje.h"

Hilo* Tema::nuevoHilo(string titulo, Mensaje* mensajeInicial){
    Hilo* hilo = new Hilo(titulo);
    hilo->nuevoMensaje(mensajeInicial->getContenido(), mensajeInicial->verAutor());
    hilos->push_back(*hilo);
    return hilo;
}

int Tema::numMensajes(){
    int suma = 0;
    for (Hilo & item : *hilos){
        suma += item.numeroMensajes();
    }
    return suma;
}

vector<Hilo>* Tema::buscaHilos(string termino){
    vector<Hilo>* hilosResultado = new vector<Hilo>;
    for(Hilo & item : *hilos){
        string str = item.getTitulo();
        if(str.find(termino)<str.length()) hilosResultado->push_back(item);
    }
    return hilosResultado;
}
