#include <iostream>
#include "abb.h"
#include <memory>
using namespace std;

int main()
{
    ABB<int> arbolEnteros;
    arbolEnteros.insert(52);
    arbolEnteros.insert(28);
    arbolEnteros.insert(74);
    arbolEnteros.insert(13);
    arbolEnteros.insert(40);
    arbolEnteros.insert(63);
    arbolEnteros.insert(86);
    arbolEnteros.insert(4);
    arbolEnteros.insert(21);
    arbolEnteros.insert(32);
    arbolEnteros.insert(46);
    arbolEnteros.insert(57);
    arbolEnteros.insert(71);
    arbolEnteros.insert(93);
    arbolEnteros.insert(86);
    arbolEnteros.insert(2);
    arbolEnteros.insert(7);
    arbolEnteros.insert(16);
    arbolEnteros.insert(24);
    arbolEnteros.insert(29);
    arbolEnteros.insert(37);
    arbolEnteros.insert(50);
    arbolEnteros.erase(40);

    cout <<"Dirección del 71: " <<arbolEnteros.find(71) <<endl;
    arbolEnteros.inOrder();
    cout <<endl <<"La raíz es: " <<arbolEnteros.getValue() <<endl;
}