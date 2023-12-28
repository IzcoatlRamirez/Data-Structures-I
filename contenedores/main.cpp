#include <iostream>

using namespace std;

enum Opciones
{
    OPC_SALIR,
    OPC_AGREGAR,
    OPC_CONSULTAR,
    OPC_BUSCAR
};

union Unidad
{
    int gramo;
    float kilo;
    int mililitro;
    float litro;
};

enum Tipo_Unidad
{
    U_GRAMO = 1,
    U_KILO,
    U_MILILITRO,
    U_LITRO
};

struct Ingrediente
{
    string nombre;
    Unidad cantidad;
    int tipoUnidad;
};

// Constantes y variables globales
const int MAX_INGREDIENTE = 10;
Ingrediente ingredientes[MAX_INGREDIENTE];
int contador = 0;

// Declaración de prototipos
// menú principal
void menu();

// registrarIngrediente recibe un ingrediente como referencia.
void registrarIngrediente(Ingrediente& ingrediente);

// consultarIngrediente recibe un ingrediente como referencia constante.
void consultarIngrediente(const Ingrediente& ingrediente);

// buscarIngrediente realiza la búsqueda de un ingrediente por nombre.
void buscarIngrediente();

int main()
{
    menu();

    return 0;
}

void menu()
{
    int opc;
    do
    {
        cout <<"                        Menú de Ingredientes" <<endl <<endl
            <<OPC_AGREGAR <<") Agregar Ingrediente" <<endl
           <<OPC_CONSULTAR <<") Consultar Ingredientes" <<endl
          <<OPC_BUSCAR <<") Buscar Ingrediente" <<endl
         <<OPC_SALIR <<") Salir" <<endl
        <<"Selecciona una opción: ";
        cin >>opc;
        cin.ignore();

        switch (opc)
        {
        case OPC_AGREGAR:
            cout <<"                        Agregar" <<endl;
            if (contador < MAX_INGREDIENTE)
            {
                registrarIngrediente(ingredientes[contador]);
                ++contador;
            }
            else
            {
                cout <<"No hay espacio disponible." <<endl;
            }
            break;
        case OPC_CONSULTAR:
            cout <<"                        Consultar" <<endl;
            if (contador == 0)
            {
                cout <<"No hay ingredientes registrados." <<endl;
            }
            else
            {
                for (int i(0); i < contador; ++i)
                {
                    consultarIngrediente(ingredientes[i]);
                    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
                }
            }
            break;
        case OPC_BUSCAR:
            cout <<"                        Buscar" <<endl;
            if (contador == 0)
            {
                cout <<"No hay ingredientes registrados." <<endl;
            }
            else
            {
                buscarIngrediente();
            }
            break;
        case OPC_SALIR:
            cout <<"Saliendo del menú de ingredientes" <<endl;
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

void buscarIngrediente()
{
    string patron;
    int encontrados = 0;

    cout <<"Nombre: ";
    getline(cin, patron);

    for (int i(0); i < contador; ++i)
    {
        // find(<cadenaBuscada>, <posicionInicial>)
        // patron: "in"
        // nombre: Harina
        //
        //    in
        // Harina
        // 0123456
        if ( ingredientes[i].nombre.find(patron, 0) < ingredientes[i].nombre.size())
        {
            consultarIngrediente(ingredientes[i]);
            ++encontrados;
            cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        }
    }
    cout <<encontrados <<" ingredientes encontrados." <<endl <<endl;
}