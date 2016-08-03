#include "fecha.h"
#include <time.h>
#include <stdio.h>

Fecha::Fecha(){
    this->fecha = obtenerFecha();
}

string Fecha::obtenerFecha(){
    time_t hoy = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&hoy);

    strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &tstruct);
    return buf;
}
