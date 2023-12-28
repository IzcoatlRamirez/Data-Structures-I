#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include "persona.h"

using namespace std;

class Estudiante : public Persona
{
public:
    Estudiante();

    string getCarrera() const;
    void setCarrera(const string &value);

    string getCodigo() const;
    void setCodigo(const string &value);

private:
    string carrera;
    string codigo;
};

#endif // ESTUDIANTE_H