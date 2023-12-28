#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>

using namespace std;

class Producto
{
public:
    Producto();

    string getNombre() const;
    void setNombre(const string& valor);
    float getPrecio() const;
    void setPrecio(float valor);
    int getExistencia() const;
    void setExistencia(int valor);

    // friend: permite acceso a los atributos de la clase
    // ostream: Output STREAM <-> Flujo de salida
    friend ostream& operator << (ostream& os, const Producto& obj);

    // istream: Input STREAM <-> Flujo de entrada
    friend istream& operator >> (istream& is, Producto& obj);

    bool operator < (const Producto& obj) const;

private:
    string nombre;
    float precio;
    int existencia;
};

#endif // PRODUCTO_H