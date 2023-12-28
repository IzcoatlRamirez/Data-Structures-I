#include "estudiante.h"

Estudiante::Estudiante()
{
    carrera = "-";
    codigo = "-";
}

string Estudiante::getCarrera() const
{
    return carrera;
}

void Estudiante::setCarrera(const string &value)
{
    carrera = value;
}

string Estudiante::getCodigo() const
{
    return codigo;
}

void Estudiante::setCodigo(const string &value)
{
    codigo = value;
}
