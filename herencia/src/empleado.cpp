#include "empleado.h"

Empleado::Empleado()
{
    puesto = "-";
    antiguedad = 0;
}

string Empleado::getPuesto() const
{
    return puesto;
}

void Empleado::setPuesto(const string &value)
{
    puesto = value;
}

int Empleado::getAntiguedad() const
{
    return antiguedad;
}

void Empleado::setAntiguedad(int value)
{
    antiguedad = value;
}
