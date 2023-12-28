#include <iostream>

using namespace std;

enum Opciones
{
    OPC_SALIR = 1,
    OPC_REGISTRAR,
    OPC_CONSULTAR,
    OPC_BUSCAR
};

int main()
{
    int opc;
    do
    {
        cout <<"                        Menú de opciones" <<endl <<endl
            <<OPC_REGISTRAR <<") Registrar" <<endl
           <<OPC_CONSULTAR <<") Consultar" <<endl
          <<OPC_BUSCAR <<") Buscar" <<endl
         <<OPC_SALIR <<") Salir" <<endl
        <<"Selecciona una opción: ";
        cin >>opc;

        switch (opc)
        {
        case OPC_REGISTRAR:
            cout <<"Registrar" <<endl;
            break;
        case OPC_CONSULTAR:
            cout <<"Consultar" <<endl;
            break;
        case OPC_BUSCAR:
            cout <<"Buscar" <<endl;
            break;
        case OPC_SALIR:
            cout <<"Nos vemos" <<endl;
            break;
        default:
            cout <<"Opción no válida" <<endl;
            break;
        }
    }
    while(opc != OPC_SALIR);
    return 0;
}