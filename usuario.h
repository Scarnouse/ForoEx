#include <string>
using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
private:
    string nombre;
    string alias;
    string clave;
public:
    Usuario(string nombre, string alias, string clave):nombre(nombre),alias(alias),clave(clave){};
    ~Usuario(){};
    bool validarClave(string clave){return this->clave==clave;};
    void cambiarClave(string nuevaClave){clave = nuevaClave;};
    string getAlias(){return alias;};
    string getNombre(){return nombre;};
};

#endif // USUARIO_H
