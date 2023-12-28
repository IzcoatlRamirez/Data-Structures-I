#ifndef MOMIA_H
#define MOMIA_H
#include <iostream>
#include "enemigo.h"

using namespace std;

class Momia : public Enemigo
{
public:
    Momia();

    void atacar() override;
};

#endif // MOMIA_H