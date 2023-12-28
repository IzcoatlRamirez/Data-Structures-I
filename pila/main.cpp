#include <iostream>
#include "pila.h"

using namespace std;

int main()
{
    Pila<int> pila;

    pila.push(7);
    pila.push(5);
    pila.push(3);
    pila.push(1);

    cout <<"Vacía: " <<pila.empty() <<endl
        <<"Tamaño: " <<pila.size() <<endl
       <<"Cima: " <<pila.top() <<endl
      <<"Elementos: ";

    while(!pila.empty())
    {
        cout <<pila.top() <<" ";
        pila.pop();
    }

    return 0;
}