#include <string>
#include <vector>
#include "tema.h"
#include "usuario.h"
using namespace std;

#ifndef FORO_H
#define FORO_H

class Foro{
private:
    string nombre;
    vector<Tema>* temas;
    vector<Usuario>* usuarios;
public:
    Foro();
    Foro(string nombre);
    ~Foro(){};
    int numTemas(){return temas->size();};
    Tema verTema(int numTema){return temas->at(numTema);};
    void nuevoUsuario(Usuario* usuario);
    Usuario* usuarioPorAlias(string alias);
    Tema* nuevoTema(string denominacion);
    vector<Usuario>* getVectorUsuario(){return usuarios;};
    vector<Tema>* getVectorTema(){return temas;};
};

#endif // FORO_H

