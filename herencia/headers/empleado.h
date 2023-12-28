#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include "persona.h"

using namespace std;

class Empleado : public Persona
{
public:
    Empleado();

    string getPuesto() const;
    void setPuesto(const string &value);

    int getAntiguedad() const;
    void setAntiguedad(int value);

private:
    string puesto;
    int antiguedad;
};

#endif // EMPLEADO_H