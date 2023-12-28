#include <iostream>

using namespace std;

struct Persona
{
    string nombre;
    int edad;
    float estatura;
};

int main()
{
    Persona persona1;
    Persona persona2;
    Persona persona3 = {"Susana Distancia", 3, 1.5};
    int numeros[] = {2, 3, 4, 5}; //Inicialización explícita de un arreglo.

    persona1.nombre = "Pedro";
    persona1.edad = 99;
    persona1.estatura = 1.88;

    persona2 = persona1;

    cout <<"Datos de la persona 1: " <<endl
        <<"Nombre: " <<persona1.nombre <<endl
       <<"Edad: " <<persona1.edad <<endl
      <<"Estatura: " <<persona1.estatura <<endl;

    cout <<"Ingresa los datos de una persona: " <<endl
        <<"Nombre: ";
    getline(cin, persona2.nombre);
    cout <<"Edad: ";
    cin >>persona2.edad;
    cout <<"Estatura: ";
    cin >>persona2.estatura;

    cout <<"Nombre persona 2: " <<persona2.nombre <<endl;

    if (persona1.nombre == persona2.nombre)
    {
        cout <<"Ambas personas tienen el mismo nombre." <<endl;
    }
    else
    {
        cout <<"Son personas distintas." <<endl;
    }

    return 0;
}