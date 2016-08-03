#include "hilo.h"
#include "mensaje.h"
#include "usuario.h"

Mensaje* Hilo::nuevoMensaje(string contenido, Usuario* usuario){
    Mensaje* mensaje = new Mensaje(usuario, contenido);
    mensajes->push_back(*mensaje);
    return mensaje;
}

