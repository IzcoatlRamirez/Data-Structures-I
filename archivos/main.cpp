#include <iostream>
#include <fstream> // File STREAM <-> Flujo de archivos
#include "producto.h"
#include "algoritmos.h"

using namespace std;

int main()
{
    //fstream nos permite manejar archivos de entrada/salida
    fstream archivo;
    //Abrimos el archivo.
    //open(<nombre de archivo>, <modo de apertura>)
    //<modo de apertura>: ios::in (lectura)
    //                    ios::out (escritura) reemplazo
    //                    ios::app (agregación)
    archivo.open("productos.txt", ios::app);

    if (!archivo.is_open())
    {
        cout <<"Error al abrir el archivo de escritura." <<endl;
    }
    else
    {
        Producto prod;
        prod.setNombre("Cigarros");
        prod.setExistencia(50);
        prod.setPrecio(70);
        archivo <<prod;
        archivo.close(); //Cerrar el archivo.
    }
    archivo.open("productos.txt", ios::in);
    if (!archivo.is_open())
    {
        cout <<"Error al abrir el archivo de lectura." <<endl;
    }
    else
    {
        Producto prod;
        while(archivo >>prod)
        {
            cout <<prod <<endl;
        }
        archivo.close();
    }

    return 0;
}