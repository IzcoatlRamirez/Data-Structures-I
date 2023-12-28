#include <iostream>
#include "producto.h"

using namespace std;

int main()
{
    Producto prod1;
    Producto prod2;

    prod1.setNombre("Coca");
    prod1.setPrecio(15.0);
    prod1.setExistencia(20);
    cout << prod1 << endl;

    cout <<"Ingresa los datos de un producto (nombre, precio, existencia)." <<endl
        <<"Por cada valor presiona <ENTER>." <<endl;

    cin >>prod2;
    cout <<prod2 <<endl;

    if (prod1 < prod2)
    {
        cout <<prod1.getNombre() <<" es menor que " <<prod2.getNombre() <<endl;
    }
    return 0;
}
