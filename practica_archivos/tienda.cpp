#include "tienda.h"

Tienda::Tienda()
{
 //contadorProductos=0;
}

void Tienda::agregarProducto()
{
  Producto p;
  string nombre;
   int existencia;
   float precio;
  cout<<"--Agregando producto--"<<endl<<endl
   <<"Nombre del producto:"<<endl;
   getline(cin,nombre);
cout<<"Existencia del producto:"<<endl;
   cin>>existencia;
cout<<"Precio del producto:"<<endl;
   cin>>precio;

   p.setNombre(nombre);
   p.setExistencia(existencia);
   p.setPrecio(precio);

productos.push_back(p);

cout<<"Producto agregado con éxito."<<endl<<endl;
//contadorProductos++;
}

void Tienda::consultarProductos(ListaEstatica<Producto>& lista) const
{
cout<<"--Consultando productos--"<<endl<<endl;
 for(size_t i(0); i<lista.size();++i)
 {
  cout<<lista[i]<<endl
  <<"---------------------------"<<endl;
 }
}

void Tienda::buscarProducto(ListaEstatica<Producto>& lista)const
{
Producto pr;   
string p;
cout<<"--Buscando producto--"<<endl<<endl;

    cout<<"Ingrese el nombre del producto"<<endl;
    getline(cin,p);
    pr.setNombre(p);
    
    if(sequentialSearch(lista,pr)<lista.size())
    {
        cout<<"Producto encontrado-->"<<endl;
        cout<<lista[sequentialSearch(lista,pr)]<<endl;
    }
    else
    {
      cout<<"No se pudo encontrar el producto."<<endl;
    }
}

void Tienda::ordenarProducto()
{
    quickSort(productos,0,productos.size()-1);
    cout<<"Productos ordenados con éxito."<<endl<<endl;
}

void Tienda::guardarProductos(ListaEstatica<Producto>& lista) const
{
   cout<<"--Guardando productos en txt--"<<endl<<endl; 
fstream archivo;
archivo.open("productos.txt",ios::app);
if(!archivo.is_open())
{
    cout<<"Error al abrir el archivo."<<endl;
}
else
{
    for(size_t i(0);i<lista.size();i++)
    {
        archivo<<lista[i];
    }
        archivo.close();

    cout<<"Guardado con éxito."<<endl;
}



}

void Tienda::cargarProductos(ListaEstatica<Producto>& lista)
{
 cout<<"--Cargando productos--"<<endl<<endl;
 fstream archivo;
 archivo.open("productos.txt",ios::in);
if(!archivo.is_open())
{
    cout<<"Error al abrir el archivo."<<endl;
}
else
{
 Producto p;
 while(archivo>>p)
 {
     lista.push_back(p);
 }
archivo.close();
}
cout<<"Productos cargados con éxito."<<endl;
}


void Tienda::menu()
{
int opc;
do
{
   cout<<"                 Menu tienda"<<endl<<endl
      <<OPC_AGREGAR<<") Agregar producto"<<endl
     <<OPC_CONSULTAR<<") Consultar producto"<<endl
    <<OPC_BUSCAR<<") Buscar producto"<<endl
   <<OPC_ORDENAR<<") Ordenar productos"<<endl
  <<OPC_GUARDAR<<") Guardar productos"<<endl
 <<OPC_CARGAR<<") Cargar productos"<<endl  
<<OPC_SALIR<<") Salir"<<endl<<endl;
cin>>opc;
cin.ignore();

switch (opc)
{
case OPC_AGREGAR:
if(productos.full()==true)
{
    cout <<"No hay espacio disponible." <<endl <<endl;
}
else
{
    agregarProducto();
}
break;

case OPC_CONSULTAR:
if(productos.empty()==true)
{
    cout<<"No hay productos que consultar."<<endl<<endl;
}
else
{
consultarProductos(productos);
}
break;

case OPC_BUSCAR:
if(productos.empty()==true)
{
    cout<<"No hay productos que buscar."<<endl<<endl;
}
else
{
    buscarProducto(productos);
}

break;

case OPC_ORDENAR:
if(productos.empty()==true)
{
cout<<"Aún no hay elementos para ordenar."<<endl<<endl;
}
else
{
    ordenarProducto();
}
break;

case OPC_GUARDAR:
 if(productos.empty()==true)
{
cout<<"Aún no hay productos que guardar."<<endl<<endl;
}
else
{
    guardarProductos(productos);
}
break;

case OPC_CARGAR:
if(productos.full()==true)
{
    cout<<"No hay espacio disponible."<<endl<<endl;
}
else
{
    cargarProductos(productos);
}
break;

case OPC_SALIR:
cout <<"Saliendo del menú" <<endl;
break;
       
default:
cout <<"Opción no válida" <<endl;
break;
}
} while (opc!=OPC_SALIR);

}