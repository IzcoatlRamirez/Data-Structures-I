#include <iostream>
#include "ldl.h"

using namespace std;

int main()
{
    LDL<int> enteros;
    enteros.push_front(7);
    enteros.push_front(5);
    enteros.push_back(9);
    enteros.pop_front();
    enteros.pop_back();
    enteros.insert(2, 8);
    enteros.erase(2);
    enteros.insert(2, 33);
    enteros.insert(2, 33);
    enteros.push_back(33);
    enteros.push_front(33);
    enteros.remove(33);
    //enteros.clear();

    cout <<"Vacía: " <<enteros.empty() <<endl
        <<"Tamaño: " <<enteros.size() <<endl
       <<"Frente: " <<enteros.front() <<endl
      <<"Final: " <<enteros.back() <<endl;

    cout <<"Datos: ";
    for (size_t i(0); i < enteros.size(); ++i)
    {
        cout <<enteros[i] <<(i + 1 == enteros.size() ? "\n" : " ");
    }

    return 0;
}