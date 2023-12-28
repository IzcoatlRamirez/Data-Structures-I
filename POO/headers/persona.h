#ifndef PERSONA_H // Si no está definido PERSONA_H
#define PERSONA_H // Define PERSONA_H
#include <iostream>

using namespace std;

// Declaración de la clase Persona
// class <Identificador>
class Persona
{
    // Comportamientos o procedimientos. Generalmente serán públicos.
    // public indica que la información sí es visible desde fuera de la clase.
public:
    // Constructor de clase. Es un procedimiento especial que tiene el mismo nombre
    // que la clase, no tiene tipo de retorno y se ejecuta justo cuando se crea
    // una instancia o "variable" u "objeto" de la clase.
    Persona();

    // Destructor de clase. Es un procedimiento especial que tiene el mismo nombre
    // que la clase, es precedido por una tilde (~), no tiene tipo de retorno y
    // se ejecuta justo antes de que el objeto es borrado de la memoria.
    virtual ~Persona();

    // Métodos de interfaz. Permiten obtener y asignar valor de los atributos privados.
    // Por cada atributo debe haber un método para obtener valor, comúnmente utilizando
    // el prefijo get y debe haber otro método para asignar valor al atributo comúnmente
    // utilizando el prefijo set.

    // getter, sirve para obtener valor del atributo.
    string getNombre();

    // setter, sirve para asignar valor al atributo.
    void setNombre(const string& valor);

    int getEdad();
    void setEdad(int valor);

    float getPeso();
    void setPeso(float valor);

    void hablar(const string& mensaje);
    void comer(const string& alimento);

    // Atributos o características. Generalmente serán privados.
    // private indica que la información no es visible desde fuera de la clase.
    private:
    string nombre;
    int edad;
    float peso;
};

#endif // PERSONA_H