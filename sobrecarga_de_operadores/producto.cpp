#include "producto.h"

Producto::Producto()
{
    nombre = "-";
    precio = 0.0;
    existencia = 0;
}

string Producto::getNombre() const
{
    return nombre;
}

void Producto::setNombre(const string &valor)
{
    nombre = valor;
}

float Producto::getPrecio() const
{
    return precio;
}

void Producto::setPrecio(float valor)
{
    precio = valor;
}

int Producto::getExistencia() const
{
    return existencia;
}

void Producto::setExistencia(int valor)
{
    existencia = valor;
}

ostream& operator << (ostream& os, const Producto& obj)
{
    os <<"Nombre: " <<obj.getNombre() <<endl
      <<"Predio: " <<obj.getPrecio() <<endl
     <<"Existencia: " <<obj.getExistencia() <<endl;

    return os;
}

istream& operator >> (istream& is, Producto& obj)
{
    getline(is, obj.nombre);
    is >> obj.precio;
    is >> obj.existencia;

    return is;
}

bool Producto::operator < (const Producto& obj) const
{
    return nombre < obj.nombre;
}
