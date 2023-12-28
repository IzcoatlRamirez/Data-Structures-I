#include <iostream>
#include "persona.h"
#include "estudiante.h"
#include "empleado.h"

using namespace std;

int main()
{
    Persona persona1;
    Estudiante estudiante1;
    Empleado empleado1;

    cout <<"Datos del estudiante: " <<endl
        <<"Nombre: " <<estudiante1.getNombre() <<endl
       <<"Edad: " <<estudiante1.getEdad() <<endl
      <<"Nacionalidad: " <<estudiante1.getNacionalidad() <<endl
     <<"Carrera: " <<estudiante1.getCarrera() <<endl
    <<"Código: " <<estudiante1.getCodigo() <<endl <<endl;

    return 0;
}
