#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

class Persona
{
public:
    Persona();

    string getNombre() const;
    void setNombre(const string& valor);
    int getEdad() const;
    void setEdad(int valor);
    string getNacionalidad() const;
    void setNacionalidad(const string& valor);

private:
    string nombre;
    int edad;
    string nacionalidad;
};

#endif // PERSONA_H
