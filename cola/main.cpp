#include <iostream>
#include "cola.h"

using namespace std;

int main()
{
    Cola<int> enteros;

    enteros.push(7);
    enteros.push(5);
    enteros.push(3);
    enteros.push(1);

    cout <<"Vacía: " <<enteros.empty() <<endl
        <<"Tamaño: " <<enteros.size() <<endl
       <<"Frente: " <<enteros.front() <<endl
      <<"Final: " <<enteros.back() <<endl
     <<"Elementos: ";

    while(!enteros.empty())
    {
        cout <<enteros.front() <<" ";
        enteros.pop();
    }
    return 0;
}