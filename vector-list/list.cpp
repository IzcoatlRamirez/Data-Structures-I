#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> enteros; // Una lista de tipo int
    list<int>::iterator it;
    list<char> simbolos; // Una lista de símbolos o caracteres

    // push_back() agrega un elemento al final de la colección
    enteros.push_back(99); // |<-[99]->|
    enteros.push_back(111); // |<-[99]<->[111]->|
    enteros.push_front(77); // |<-[77]<->[99]<->[111]->|

    it = enteros.begin();
    //Agregar elemento en la posición 1
    advance(it, 1);
    enteros.insert(it, 88);

    // Eliminar el último dato de la lista
    enteros.pop_back();
    //Eliminar el primero de la lista
    enteros.pop_front();

    it = enteros.begin();
    advance(it, 1);
    enteros.erase(it);

    enteros.push_front(24);
    enteros.push_back(24);
    enteros.remove(24);

    enteros.push_back(3);
    enteros.push_back(7);
    enteros.push_back(2);

    cout <<"Lista de enteros:" <<endl
        <<"enteros.empty(): " <<enteros.empty() <<endl
       <<"enteros.size(): " <<enteros.size() <<endl
      <<"enteros.front(): " <<enteros.front() <<endl
     <<"enteros.back(): " <<enteros.back() <<endl <<endl;

    enteros.sort();

    for (it = enteros.begin(); it != enteros.end(); ++it)
    {
        cout <<*it <<endl;
    }
    for (int entero : enteros)
    {
        cout <<entero <<endl;
    }
    return 0;
}