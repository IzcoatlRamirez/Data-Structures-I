#include <iostream>
#include <string.h>
using namespace std;
const int MAX_INGREDIENTES=10;
const int MAX_PASOS=10;
const int MAX_RECETAS=15;
enum Opciones{OPC_SALIR,OPC_AGREGAR,OPC_CONSULTAR, OPC_BUSCAR,OPC_AGREGAR_PASO,OPC_CONSULTAR_PASO};
union Unidad
{
    int gramo;
    float kilo;
    int mililitro;
    float litro;
};
enum Tipo_Unidad{U_GRAMO = 1,U_KILO,U_MILILITRO,U_LITRO};

struct Ingrediente
{
    string nombre;
    Unidad cantidad;
    int tipoUnidad;
    int contadorIngredientes = 0;
};

struct Pasos
{
string paso;
};

struct Receta
{
 string nombre;
 Pasos pasos[MAX_PASOS];
 Ingrediente ingrediente[MAX_INGREDIENTES];
 int contadorIngredientes=0;
 int contadorPasos=0;
}receta[MAX_RECETAS];
int contadorRecetas=0;

// Declaración de prototipos
// registrarIngrediente recibe un ingrediente como referencia.
void registrarIngrediente(Ingrediente& ingrediente);

// consultarIngrediente recibe un ingrediente como referencia constante.
void consultarIngrediente(const Ingrediente& ingrediente);

// buscarIngrediente realiza la búsqueda de un ingrediente por nombre.
void buscarIngrediente(const Receta& receta);
void menu();
void menuRecetario();
void registrarReceta(Receta& receta);
void consultarReceta(const Receta& receta);
void AgregarPasos(Pasos& pasos);
void consultarPasos(const Pasos& pasos);
void buscarReceta();

int main()
{

    menuRecetario();
    return 0;
}

void menu(Receta& receta)
{
    int opc;
    do
    {
        cout <<"                        Menú de Ingredientes" <<endl <<endl
            <<OPC_AGREGAR <<") Agregar Ingrediente" <<endl
           <<OPC_CONSULTAR <<") Consultar Ingredientes" <<endl
          <<OPC_BUSCAR <<") Buscar Ingrediente" <<endl
          <<OPC_AGREGAR_PASO <<") Agregar paso" <<endl
          <<OPC_CONSULTAR_PASO <<") Consultar pasos" <<endl
         <<OPC_SALIR <<") Salir" <<endl
        <<"Selecciona una opción: ";
        cin >>opc;
        cin.ignore();

        switch (opc)
        {
        case OPC_AGREGAR:
            cout <<"                        Agregar" <<endl;
            if (receta.contadorIngredientes < MAX_INGREDIENTES)
            {
                registrarIngrediente(receta.ingrediente[receta.contadorIngredientes]);
                ++receta.contadorIngredientes;
            }
            else
            {
                cout <<"No hay espacio disponible." <<endl;
            }
            break;
        case OPC_CONSULTAR:
            cout <<"                        Consultar Ingredientes" <<endl;
            if (receta.contadorIngredientes == 0)
            {
                cout <<"No hay ingredientes registrados." <<endl;
            }
            else
            {
                for (int i(0); i < receta.contadorIngredientes; ++i)
                {
                    consultarIngrediente(receta.ingrediente[i]);
                    cout <<"-----------------------------" <<endl;
                }
            }
            break;
        case OPC_BUSCAR:
            cout <<"                        Buscar" <<endl;
            if (receta.contadorIngredientes == 0)
            {
                cout <<"No hay ingredientes registrados." <<endl;
            }
            else
            {
                buscarIngrediente(receta);
            }
            break;

        case OPC_AGREGAR_PASO:   
        if(receta.contadorPasos<MAX_PASOS)
        {
            AgregarPasos(receta.pasos[receta.contadorPasos]);  
            ++receta.contadorPasos;
        }
        else
        {
            cout<<"No hay espacio disponible."<<endl;
        }
        
         break;
        
        

        case OPC_CONSULTAR_PASO:  
       cout <<"                        Consultar Pasos" <<endl;
            if (receta.contadorPasos == 0)
            {
                cout <<"No hay pasos registrados." <<endl;
            }
            else
            {
                cout<<"Pasos de la receta-->"<<endl;
                for (int i(0); i < receta.contadorPasos;++i)
                {
                    consultarPasos(receta.pasos[i]);
                    
                }
            }
        break;

        case OPC_SALIR:
            cout <<"Receta registrada con éxito"<<endl<<"Saliendo del menú de ingredientes" <<endl;
            break;
        default:
            cout <<"Opción no válida" <<endl;
            break;
        }
    }
    while(opc != OPC_SALIR);
}

void registrarIngrediente(Ingrediente& ingrediente)
{
    cout <<"Ingresa los siguientes datos" <<endl
        <<"Nombre: ";
    getline(cin, ingrediente.nombre);
    do
    {
        cout <<"¿En qué unidad se registrará el ingrediente?" <<endl
            <<U_GRAMO <<") Gramos" <<endl
           <<U_KILO <<") Kilos" <<endl
          <<U_MILILITRO <<") Mililitros" <<endl
         <<U_LITRO <<") Litros" <<endl
        <<"Selecciona una opción: ";
        cin >>ingrediente.tipoUnidad;
    }
    while(ingrediente.tipoUnidad < U_GRAMO || ingrediente.tipoUnidad > U_LITRO);
    switch (ingrediente.tipoUnidad)
    {
    case U_GRAMO:
        cout <<"Cantidad en gramos: ";
        cin >>ingrediente.cantidad.gramo;
        break;
    case U_KILO:
        cout <<"Cantidad en kilos: ";
        cin >>ingrediente.cantidad.kilo;
        break;
    case U_MILILITRO:
        cout <<"Cantidad en mililitros: ";
        cin >>ingrediente.cantidad.mililitro;
        break;
    case U_LITRO:
        cout <<"Cantidad en litros: ";
        cin >>ingrediente.cantidad.litro;
        break;
    default:
        break;
    }
    cout <<"Ingrediente registrado con éxito." <<endl;
}

void consultarIngrediente(const Ingrediente& ingrediente)
{
    cout <<"Nombre: " <<ingrediente.nombre <<endl
        <<"Cantidad: ";
    switch (ingrediente.tipoUnidad)
    {
    case U_GRAMO:
        cout <<ingrediente.cantidad.gramo <<" gramos" <<endl;
        break;
    case U_KILO:
        cout <<ingrediente.cantidad.kilo <<" kilogramos" <<endl;
        break;
    case U_MILILITRO:
        cout <<ingrediente.cantidad.mililitro <<" mililitros" <<endl;
        break;
    case U_LITRO:
        cout <<ingrediente.cantidad.litro <<" litros" <<endl;
        break;
    default:
        break;
    }
}

void buscarIngrediente(const Receta& receta)
{
    string patron;
    int encontrados = 0;

    cout <<"Nombre: ";
    getline(cin, patron);

    for (int i(0); i < receta.contadorIngredientes; ++i)
    {
        
        if ( receta.ingrediente[i].nombre.find(patron, 0) < receta.ingrediente[i].nombre.size())
        {
            consultarIngrediente(receta.ingrediente[i]);
            ++encontrados;
            cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        }
    }
    cout <<encontrados <<" ingredientes encontrados." <<endl <<endl;
}

void AgregarPasos(Pasos& pasos)
{
   cout<<"Ingresa los pasos de la receta:"<<endl;
  getline(cin,pasos.paso);
   cout<<"Paso agregado con éxito."<<endl;
}

void consultarPasos(const Pasos& pasos)
{

 
 cout<<pasos.paso<<endl
 <<"------------------------"<<endl;

}

void menuRecetario()
{
  int opc;
  do
  {
      cout <<"                        Menú de recetas" <<endl <<endl
            <<OPC_AGREGAR <<") Agregar receta" <<endl
           <<OPC_CONSULTAR <<") Consultar receta" <<endl
          <<OPC_BUSCAR <<") Buscar receta" <<endl
         <<OPC_SALIR <<") Salir" <<endl
        <<"Selecciona una opción: ";
        cin >>opc;
        cin.ignore();

switch (opc)
{
case OPC_AGREGAR: cout<<"Agregar receta-->"<<endl;
if(contadorRecetas<MAX_RECETAS)
{
   registrarReceta(receta[contadorRecetas]);
   ++contadorRecetas;
}
else
{
    cout<<"No hay espacio disponible"<<endl;
}
break;

case OPC_CONSULTAR: cout<<"Consultar receta-->"<<endl;
if(contadorRecetas==0)
{
  cout<<"Aún no hay recetas."<<endl;
}
else
{
for(int i(0);i<contadorRecetas;i++)
{
consultarReceta(receta[i]);
cout<<endl<<endl;
}
}
break;
case OPC_BUSCAR: cout<<"Buscar receta-->"<<endl;
if(contadorRecetas==0)
{
cout<<"Aún no hay recetas."<<endl;
}
else
{
buscarReceta();
}
break;
case OPC_SALIR: cout <<"Nos vemos." <<endl; break;
default:  cout <<"Opción no válida" <<endl;  break;
}
} while(opc!=OPC_SALIR);
  

}


void registrarReceta(Receta&receta)
{
   cout<<"Ingresa el nombre de la receta:"<<endl;
   getline(cin,receta.nombre);
   menu(receta);
}

void consultarReceta(const Receta &receta)
{
    cout<<"Nombre de la receta:"<<receta.nombre<<endl;
    cout<<"Ingredientes------>"<<endl;
    for(int i(0);i<receta.contadorIngredientes;i++)
    {
        consultarIngrediente(receta.ingrediente[i]);
       cout<<endl;
    }
    cout<<"Pasos de la receta-->"<<endl;
    for(int i(0);i<receta.contadorPasos;i++)
    {
        consultarPasos(receta.pasos[i]);
        
    }
}

void buscarReceta()
{

string patron;
    int encontrados = 0;

    cout <<"Nombre: ";
    getline(cin, patron);

    for (int i(0); i < contadorRecetas; ++i)
    {
        
        if ( receta[i].nombre.find(patron, 0) < receta[i].nombre.size())
        {
            consultarReceta(receta[i]);
            ++encontrados;
        }
    }
    cout <<encontrados <<" recetas encontradas." <<endl <<endl;

}
