#include "vampiro.h"

Vampiro::Vampiro()
{
    setTipo("Vampiro");
    setAtaque("Mordida");
    setFuerza(3);
    setEnergia(15);
    setRecuperacion(4);
}

int Vampiro::getRecuperacion() const
{
    return recuperacion;
}

void Vampiro::setRecuperacion(int value)
{
    recuperacion = value;
}

void Vampiro::atacar()
{
    cout <<getTipo() <<" (" <<getEnergia() <<") ataca con " <<getAtaque() <<" y causa "
        <<getFuerza() <<" de daño ." <<endl
       <<getTipo() <<" recupera " <<getRecuperacion() <<" de energía." <<endl;
    setEnergia(getEnergia() + getRecuperacion());
    cout <<getTipo() <<" (" <<getEnergia() <<")" <<endl;
}