#ifndef POSTFIJO_H
#define POSTFIJO_H

#include <iostream>
#include "Pila.h"

using namespace std;

class Postfijo
{
private:
    bool esOperador(char);
    int precedencia(char);

public:
    Postfijo() {}
    string infijoAPostfijo(const string &);
};

string Postfijo::infijoAPostfijo(const string &cadena)
{
    string postfijo;
    Pila<char> operadores;
    char operador;

    for (char c : cadena)
    {
        try
        {
            if (esOperador(c))
            {

                while (!operadores.empty() &&
                       (operador = operadores.top()) != '(' &&
                       precedencia(c) <= precedencia(operador))
                {
                    postfijo += operador;
                    operadores.pop();
                }
                operadores.push(c);
            }
            else if (c == '(')
            {

                operadores.push(c);
            }
            else if (c == ')')
            {

                while ((operador = operadores.top()) != '(')
                {
                    postfijo += operador;
                    operadores.pop();
                }
                operadores.pop();
            }
            else
            {
                postfijo += c;
            }
        }
        catch (...)
        {
            cout << "El input no es en notación infija..." << endl;
            return "";
        }
    }

    while (!operadores.empty())
    {
        postfijo += operadores.top();
        operadores.pop();
    }
    return postfijo;
}

bool Postfijo::esOperador(char c)
{
    return precedencia(c) != 0;
}

int Postfijo::precedencia(char c)
{
    return (c == '+' || c == '-') ? 1 : (c == '*' || c == '/') ? 2
                                    : (c == '^')               ? 3
                                                               : 0;
}

#endif // POSTFIJO_H