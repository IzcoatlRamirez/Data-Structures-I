#include <iostream>
#include "enemigo.h"
#include "momia.h"
#include "vampiro.h"
#include <time.h>

using namespace std;

int main()
{
    const int MAX_ENEMIGOS = 10;
    Enemigo* enemigos[MAX_ENEMIGOS];
    srand(time(NULL));
    int personaje = 50;
    int derrotados = 0;
    int fuerza = 6;

    for (int i(0); i < MAX_ENEMIGOS; ++i)
    {
        if (rand() % 2 == 0)
        {
            // Apuntador a objeto tipo momia.
            Momia* m = new Momia();
            enemigos[i] = m;
        }
        else
        {
            Vampiro* v = new Vampiro();
            enemigos[i] = v;
        }
    }

    /*for (int i(0); i < MAX_ENEMIGOS; ++i)
    {
        enemigos[i]->atacar();
    }*/

    while(personaje > 0 && derrotados < MAX_ENEMIGOS)
    {
        while(enemigos[derrotados]->getEnergia() > 0 &&
              personaje > 0)
        {
            cout <<"Tu energía: " <<personaje <<endl;
            personaje -= enemigos[derrotados]->getFuerza();
            enemigos[derrotados]->atacar();
            enemigos[derrotados]->setEnergia(enemigos[derrotados]->getEnergia() - fuerza);
            cout <<"Has atacado a " <<enemigos[derrotados]->getTipo() <<endl
                <<" Le causas " <<fuerza <<" de daño." <<endl;
            cout <<"Presiona <Enter> para continuar..." <<endl;
            cin.get();
        }
        if (personaje > 0)
        {
            cout <<"Has derrotado a " <<enemigos[derrotados]->getTipo() <<endl
                <<"ganas experiencia y salud." <<endl;
            personaje += 5;
        }
        else
        {
            cout <<"Fuiste derrotado." <<endl;
        }
        ++derrotados;
    }
    /*Momia m;
    Vampiro v;

    m.atacar();
    v.atacar();*/

    return 0;
}