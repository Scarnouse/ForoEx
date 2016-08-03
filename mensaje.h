#include "usuario.h"
#include <string>
#include "fecha.h"
using namespace std;


#ifndef MENSAJE_H
#define MENSAJE_H

class Mensaje{
private:
    Fecha* fecha;
    string contenido;
    Usuario* autor;
public:
    Mensaje(Usuario *autor, string contenido):autor(autor),contenido(contenido){this->fecha=new Fecha();};
    ~Mensaje(){};
    Usuario* verAutor(){return autor;};
    string getContenido(){return contenido;}; //para poder acceder al contenido de los mensajes hay que usar el getter
    Fecha* getFecha(){return fecha;};
};

#endif // MENSAJE_H
