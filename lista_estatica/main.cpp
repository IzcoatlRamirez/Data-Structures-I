#include <iostream>
#include "lista_estatica.h"

using namespace std;

int main()
{
    ListaEstatica<int> enteros;
    // Una lista de caracteres ASCII de tamaño 50
    ListaEstatica<char> simbolos(50);

    enteros.push_front(1);
    enteros.push_front(3);
    enteros.push_front(5);
    enteros.push_front(10);
    enteros.push_back(13);
    enteros.pop_front();
    enteros.pop_back();
    enteros.insert(1, 33);
    enteros.erase(1);
    enteros.insert(1, 3);
    enteros.push_front(3);
    enteros.remove(3);
    cout <<"enteros.empty(): " <<enteros.empty() <<endl
        <<"enteros.full(): " <<(enteros.full() ? "verdadero" : "falso") <<endl
       <<"enteros.size(): " <<enteros.size() <<endl
      <<"enteros.front(): " <<enteros.front() <<endl
     <<"enteros.back(): " <<enteros.back() <<endl
    <<"elements: ";

    enteros[1] = 33;
    for (size_t i(0); i < enteros.size(); ++i)
    {
        cout <<enteros[i] <<" ";
    }
    cout <<endl;
    return 0;
}