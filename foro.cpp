#include "foro.h"
#include "tema.h"
#include "usuario.h"
#include <iostream>

Foro::Foro(){
    temas = new vector<Tema>;
    usuarios = new vector<Usuario>;
}

Foro::Foro(string nombre){
    this->nombre = nombre;
    temas = new vector<Tema>;
    usuarios = new vector<Usuario>;
}

void Foro::nuevoUsuario(Usuario* usuario){
    bool repetido;
    if (usuarios->size()==0) repetido=false;
    else {
        for (Usuario & item: *usuarios){
            if (item.getAlias().compare(usuario->getAlias())==0) {
                cout << endl;
                cout << "Este alias ya está siendo utilizado" << endl;
                repetido = true;
                cout << endl;
            }
        }
    }
    if (repetido == false) usuarios->push_back(*usuario);
}

Usuario* Foro::usuarioPorAlias(string alias){
    Usuario* usuario = NULL;
    for (Usuario & item: *usuarios){
        if (item.getAlias().compare(alias)==0) usuario = &item;
    }
    return usuario;
}

Tema* Foro::nuevoTema(string denominacion){
    Tema* tema = new Tema(denominacion);
    temas->push_back(*tema);
    return tema;
}




