#include "estudiante.h"

Estudiante::Estudiante()
{
    nombre = "-";
    codigo = "-";
    carrera = "-";
}

string Estudiante::getNombre() const
{
    return nombre;
}

void Estudiante::setNombre(const string& valor)
{
    nombre = valor;
}

string Estudiante::getCodigo() const
{
    return codigo;
}

void Estudiante::setCodigo(const string& valor)
{
    codigo = valor;
}

string Estudiante::getCarrera() const
{
    return carrera;
}

void Estudiante::setCarrera(const string& valor)
{
    carrera = valor;
}