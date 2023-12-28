#include "momia.h"

Momia::Momia()
{
    setTipo("Momia");
    setAtaque("Bendaje Salvaje");
    setFuerza(4);
    setEnergia(20);
}

void Momia::atacar()
{
    cout <<getTipo() <<" (" <<getEnergia() <<") ataca con " <<getAtaque() <<" y causa "
        <<getFuerza() <<" de daño." <<endl;
}