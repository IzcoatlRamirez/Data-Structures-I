#include <iostream>
#include "persona.h"

using namespace std;

int main()
{
    // Instancia de la clase Persona, también conocido como objeto o variable
    Persona persona1;
    Persona persona2;

    persona1.setNombre("Susana Distancia");
    persona1.setEdad(3);
    persona1.setPeso(33.44);
    persona2.setNombre("Juan sin miedo");

    cout <<"Nombre: " <<persona1.getNombre() <<endl
        <<"Edad: " <<persona1.getEdad() <<endl
       <<"Peso: " <<persona1.getPeso() <<endl;

    if (persona2.getEdad() == 0)
    {
        cout <<"Edad no definida para la persona 2" <<endl;
    }
    else
    {
        cout <<"Edad de la persona 2: " <<persona2.getEdad() <<endl;
    }

    persona1.hablar("Lávate las manos por 20 segundos y usa cubrebocas.");
    persona2.hablar("Al que le toca le toca. Lo único seguro es la muerte.");

    persona1.comer("frutas y verduras.");
    persona2.comer("tacos los grasosos.");

    return 0;
}