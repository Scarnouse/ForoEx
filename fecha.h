#include <string>
using namespace std;

#ifndef FECHA_H
#define FECHA_H

class Fecha{
private:
    string fecha;
public:
    Fecha();
    ~Fecha(){};
    string getFecha(){return this->fecha;};
private:
    string obtenerFecha();
};

#endif // FECHA_H
