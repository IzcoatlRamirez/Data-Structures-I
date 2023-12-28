#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // stl_vector es una plantilla que nos permite tener colecciones de datos del
    // mismo tipo. Es una colección dinámica, es decir, su tamaño puede cambiar
    // en tiempo de ejecución según sea necesario.
    // Para declarar un vector se sigue el patrón:
    // vector<tipoDato> <identificador> ;

    vector<int> enteros; // vector de enteros
    vector< vector<int> > matriz; // matriz de enteros
    vector<string> cadenas; // vector de cadenas de caracteres
    int miEntero;

    // Push back nos permite agregar un elemento al final de la colección.
    enteros.push_back(11);
    enteros.push_back(33);
    enteros.push_back(55);
    cadenas.push_back("Hola");
    cadenas.push_back("mundo");

    matriz.push_back(enteros); // Agregar dato a la matriz de enteros

    cout <<"Ingresa un entero a ser almacenado: ";
    cin >>miEntero;
    enteros.push_back(miEntero); // Agregamos el dato almacenado en una variable.

    cout <<enteros[0] <<endl;
    cout <<enteros.at(2) <<endl; // .at(<posición>) consulta ell dato del vector.
    cout <<cadenas[0] <<endl;

    enteros[0] = 1; // Asignamos valor a la posición 0
    enteros.at(1) = 3; // Asignamos valor a la posición 1;
    cadenas[1] = "Mundo";

    // Consultar los datos de un vector
    // size_t es un tipo de dato, es un entero sin signo que se utiliza comúnmente para
    // tamaños de colecciones
    for (size_t i(0); i < enteros.size(); ++i) // .size() regresa el tamaño del vector
    {
        cout <<"enteros[" <<i <<"]: " <<enteros[i] <<endl;
    }
    // Consume cada elemento de la colección y lo almacena en la variable cadena
    for (string cadena : cadenas)
    {
        cadena += "08954eujfghklop9go857tyughnlkñjogl6v7tgk.nljlhibtg";
        cout <<cadena <<endl;
    }
    cout <<cadenas[0] <<endl;

    // iterador. Variable que permite acceder a los elementos de una colección.
    // Funciona como un apuntador.
    vector<int>::iterator it;
    // .begin() regresa la dirección o posición inicial del vector
    // .end() regresa la dirección o posición posterior al último elemento.
    for (it = enteros.begin(); it != enteros.end(); ++it)
    {
        // con * accedemos al dato almacenado en la posición indicada por it.
        cout <<*it <<endl;
    }

    // Inserciones en posición
    // .insert(<posición>, <valor>)
    enteros.insert(enteros.begin()+2, 66);
    cout <<"Tamaño del vector: " <<enteros.size() <<endl
        <<enteros[2] <<endl;
    it = enteros.begin();
    enteros.insert(it+3, 44);

    // Eliminaciones
    // .pop_back() elimina el último elemento de la colección.
    enteros.pop_back();

    enteros.erase(enteros.begin()+1); // Eliminar la posición 1 del vector
    enteros.clear(); // borra todos los elementos del vector

    cout <<"Frente de las cadenas: " <<cadenas.front() <<endl
        <<"Último de las cadenas: " <<cadenas.back() <<endl;

    return 0;
}