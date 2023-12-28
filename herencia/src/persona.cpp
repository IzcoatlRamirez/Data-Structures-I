#include "persona.h"

Persona::Persona()
{
    nombre = "-";
    edad = 0;
    nacionalidad = "-";
}

string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const string &valor)
{
    nombre = valor;
}

int Persona::getEdad() const
{
    return edad;
}

void Persona::setEdad(int valor)
{
    edad = valor;
}

string Persona::getNacionalidad() const
{
    return nacionalidad;
}

void Persona::setNacionalidad(const string &valor)
{
    nacionalidad = valor;
}