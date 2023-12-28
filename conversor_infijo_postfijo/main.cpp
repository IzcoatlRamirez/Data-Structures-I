#include <iostream>
#include "postfijo.h"
using namespace std;

int main()
{
    Postfijo p;
    string cadena;
    do
    {
        cout << "Conversor Infija2postfija" << endl;
        cout << "Ingrese la expresión:" << endl
             << "->";
        getline(cin, cadena);
        cin.ignore();

        cout << "Postfijo -> " << p.infijoAPostfijo(cadena) << endl;

        cout << "1) Hacer de nuevo." << endl;
        getline(cin, cadena);
    } while (cadena == "1");

    return 0;
}