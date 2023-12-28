#include <iostream>
#include "lsl.h"

using namespace std;

int main()
{
    LSL<char> simbolos;

    simbolos.push_front('A');
    simbolos.push_front('A');
    simbolos.push_front('z');
    simbolos.push_back('B');
    simbolos.pop_front();
    simbolos.pop_back();
    simbolos.insert(2, 'a');
    simbolos.erase(2);
    simbolos.clear();
    simbolos.remove('A');


    cout <<"Vacía: " <<(simbolos.empty() ? "Verdadero" : "Falso") <<endl
        <<"Tamaño: " <<simbolos.size() <<endl
       <<"Frente: " <<simbolos.front() <<endl
      <<"Final: " <<simbolos.back() <<endl;

    for (size_t i(0); i < simbolos.size(); ++i)
    {
        cout <<simbolos[i] <<" ";
    }
    cout <<endl;
    return 0;
}