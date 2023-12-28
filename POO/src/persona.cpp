#include "persona.h"

// Persona.cpp contiene la definición o implementación de cada uno de los
// procedimientos de la clase Persona. La implementación de cada uno de los
// métodos o procedimientos seguirá el patrón:
// <tipoRetorno> <nombreClase>::<nombreProcedimiento>

// Constructor de clase
Persona::Persona()
{
    cout <<"Hola mundo :D" <<endl;
    nombre = "-";
    edad = 0;
    peso = 0.0;
}

// Destructor de clase
Persona::~Persona()
{
    cout <<nombre <<": Adiós mundo!!!!! ;(" <<endl;
}

string Persona::getNombre()
{
    return nombre;
}

void Persona::setNombre(const string &valor)
{
    nombre = valor;
}

int Persona::getEdad()
{
    return edad;
}

void Persona::setEdad(int valor)
{
    edad = valor;
}

float Persona::getPeso()
{
    return peso;
}

void Persona::setPeso(float valor)
{
    peso = valor;
}

void Persona::hablar(const string& mensaje)
{
    cout <<"-" <<nombre <<": " <<mensaje <<endl;
}

void Persona::comer(const string& alimento)
{
    cout <<nombre <<" come " <<alimento <<endl;
}