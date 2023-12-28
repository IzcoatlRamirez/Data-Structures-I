#ifndef VAMPIRO_H
#define VAMPIRO_H
#include "enemigo.h"

using namespace std;

class Vampiro : public Enemigo
{
public:
    Vampiro();

    void atacar() override;

    int getRecuperacion() const;
    void setRecuperacion(int value);

private:
    int recuperacion;
};

#endif // VAMPIRO_H