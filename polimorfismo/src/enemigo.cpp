#include "enemigo.h"

Enemigo::Enemigo()
{

}

string Enemigo::getAtaque() const
{
    return ataque;
}

void Enemigo::setAtaque(const string &value)
{
    ataque = value;
}

string Enemigo::getTipo() const
{
    return tipo;
}

void Enemigo::setTipo(const string &value)
{
    tipo = value;
}

int Enemigo::getEnergia() const
{
    return energia;
}

void Enemigo::setEnergia(int value)
{
    energia = value;
}

int Enemigo::getFuerza() const
{
    return fuerza;
}

void Enemigo::setFuerza(int value)
{
    fuerza = value;
}