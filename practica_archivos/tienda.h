#ifndef TIENDA_H
#define TIENDA_H
#include <iostream>
#include "algorithms.h"
#include "producto.h"
#include <fstream>
using namespace std;
class Tienda
{

public:

Tienda();
void menu();
void agregarProducto();
void consultarProductos(ListaEstatica<Producto>& lista) const;
void buscarProducto(ListaEstatica<Producto>& lista) const;
void ordenarProducto(); 
void guardarProductos(ListaEstatica<Producto>& lista)const;
void cargarProductos(ListaEstatica<Producto>& lista);

private:
ListaEstatica<Producto> productos;
//int contadorProductos;

enum OPCIONES
{
OPC_AGREGAR=1,
OPC_CONSULTAR,
OPC_BUSCAR,
OPC_ORDENAR,
OPC_GUARDAR,
OPC_CARGAR,
OPC_SALIR
};



};


#endif  //TIENDA_H