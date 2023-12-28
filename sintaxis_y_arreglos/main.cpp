// #include <stdio.h> STanDard Input Output
#include <iostream> // Input Output STREAM <-> Flujo de entrada - salida

using namespace std; // utilizar espacio de nombre estándar. Ahí vamos a encontrar
                    // distintas palabras reservadas del lenguaje.
// Función principal
int main()
{
    int entero;
    float real;
    string cadena; // Arreglo o cadena de caracteres

    entero = 33;
    real = 44.55;

    // Console OUT : Salida a consola
    cout <<"Hello World!\n\n\n\n" <<endl
        <<endl <<endl; // endl : fin de línea o salto de línea.

    //printf("entero: %d", entero);
    cout <<"entero: " <<entero <<endl;
    cout <<"número real: " <<real <<endl;

    cout <<"Ingresa un valor entero: ";
    // Console IN : Entrada desde consola
    cin >>entero;
    cout <<"El valor ingresado es: " <<entero <<endl;

    cout <<"Ingresa una frase o palabra: ";
    //cin >>cadena;
    // getline(de donde se va a leer, en donde se va a guardar la información)
    cin.ignore(); // descarta lo que se encuentre en el buffer de entrada
    getline(cin, cadena); // obtener línea
    cout <<"La frase o palabra es: " <<cadena <<endl;

    const int MAX_ELEM=5; // declaración de una constante entera en C++
    int arregloEnteros[MAX_ELEM];

    arregloEnteros[0] = 3;
    arregloEnteros[1] = 5;
    arregloEnteros[2] = 7;
    arregloEnteros[3] = 9;
    arregloEnteros[4] = 11;

    int variable{5};

    cout <<"variable: " <<variable <<endl;

    for (int i(0); i < MAX_ELEM; ++i)
    {
        cout <<"arregloEnteros[" <<i <<"] = " <<arregloEnteros[i] <<endl;
    }

    const int RENGLONES = 2;
    const int COLUMNAS = 3;
    // Inicialización explícita de un arreglo
    int matriz[RENGLONES][COLUMNAS] = {
        {1, 3, 5},
        {7, 9, 11}
    };

    return 0;
}
