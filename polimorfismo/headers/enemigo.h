#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <iostream>

using namespace std;

class Enemigo
{
public:
    Enemigo();

    // Función virtual pura. Convierte a la clase en abstracta.
    // No podemos crear instancias de esta clase.
    virtual void atacar() = 0;

    string getAtaque() const;
    void setAtaque(const string &value);

    string getTipo() const;
    void setTipo(const string &value);

    int getEnergia() const;
    void setEnergia(int value);

    int getFuerza() const;
    void setFuerza(int value);

private:
    string ataque;
    string tipo;
    int energia;
    int fuerza;
};

#endif // ENEMIGO_H