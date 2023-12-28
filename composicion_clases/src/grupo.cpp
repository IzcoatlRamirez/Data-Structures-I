#include "grupo.h"

Grupo::Grupo()
{
    // Valor inicial de los atributos de cualquier grupo
    materia = "-";
    clave = "-";
    nrc = "-";
    seccion = "-";
    contadorEstudiantes = 0;
}

string Grupo::getMateria() const
{
    return materia;
}

void Grupo::setMateria(const string& valor)
{
    materia = valor;
}

string Grupo::getClave() const
{
    return clave;
}

void Grupo::setClave(const string& valor)
{
    clave = valor;
}

string Grupo::getNrc() const
{
    return nrc;
}

void Grupo::setNrc(const string& valor)
{
    nrc = valor;
}

string Grupo::getSeccion() const
{
    return seccion;
}

void Grupo::setSeccion(const string& valor)
{
    seccion = valor;
}

void Grupo::menu()
{
    int opc;
    do
    {
        cout <<"                        Menú " <<materia <<" " <<seccion <<endl <<endl
            <<OPC_AGREGAR_ESTUDIANTE <<") Agregar Estudiante" <<endl
           <<OPC_CONSULTAR_LISTA <<") Consultar Estudiantes" <<endl
          <<OPC_BUSCAR_ESTUDIANTE <<") Buscar Estudiante" <<endl
         <<OPC_MODIFICAR_ESTUDIANTE <<") Modificar Estudiante" <<endl
        <<OPC_SALIR <<") Salir" <<endl
        <<"Selecciona una opción: ";
        cin >>opc;
        cin.ignore();

        switch(opc)
        {
        case OPC_AGREGAR_ESTUDIANTE:
            cout <<"                        Agregar Estudiante" <<endl;
            if (contadorEstudiantes < MAX_ESTUDIANTE)
            {
                agregarEstudiante();
            }
            else
            {
                cout <<"No se pueden agregar más estudiantes." <<endl <<endl;
            }
            break;
        case OPC_CONSULTAR_LISTA:
            cout <<"                        Consultar Estudiantes" <<endl;
            if (contadorEstudiantes == 0)
            {
                cout <<"No hay estudiantes registrados." <<endl <<endl;
            }
            else
            {
                consultarLista();
            }
            break;
        case OPC_BUSCAR_ESTUDIANTE:
            cout <<"                        Buscar Estudiante" <<endl;
            if (contadorEstudiantes == 0)
            {
                cout <<"No hay estudiantes registrados." <<endl <<endl;
            }
            else
            {
                buscarEstudiante();
            }
            break;
        case OPC_MODIFICAR_ESTUDIANTE:
            cout <<"                        Modificar Estudiante" <<endl;
            if (contadorEstudiantes == 0)
            {
                cout <<"No hay estudiantes registrados." <<endl <<endl;
            }
            else
            {
                modificarEstudiante();
            }
            break;
        case OPC_SALIR:
            cout <<"Saliendo de " <<materia <<" " <<seccion <<endl;
            break;
        default:
            cout <<"Opción no válida." <<endl;
            break;
        }
    }
    while(opc != OPC_SALIR);
}

void Grupo::agregarEstudiante()
{
    string nombre;
    string carrera;
    string codigo;
    
    cout <<"Ingresa los siguiente los siguiente datos:" <<endl
        <<"Nombre: ";
    getline(cin, nombre);
    cout <<"Carrera: ";
    getline(cin, carrera);
    cout <<"Código: ";
    getline(cin, codigo);
    
    // Asignar valor a los atributos del estudiante a ser registrado.
    estudiantes[contadorEstudiantes].setNombre(nombre);
    estudiantes[contadorEstudiantes].setCarrera(carrera);
    estudiantes[contadorEstudiantes].setCodigo(codigo);
    ++contadorEstudiantes;

    cout <<"Estudiante registrado con éxito." <<endl <<endl;
}

void Grupo::consultarEstudiante(const Estudiante& e) const
{
    cout <<"Nombre: " <<e.getNombre() <<endl
        <<"Carrera: " <<e.getCarrera() <<endl
       <<"Código: " <<e.getCodigo() <<endl;
}

void Grupo::consultarLista() const
{
    for (int i(0); i < contadorEstudiantes; ++i)
    {
        consultarEstudiante(estudiantes[i]);
        cout <<"------------------------------" <<endl;
    }
}

void Grupo::buscarEstudiante() const
{
    string patron;
    int estudiantesEncontrados = 0;

    cout <<"Nombre: ";
    getline(cin, patron);
    for (int i(0); i < contadorEstudiantes; ++i)
    {
        if (estudiantes[i].getNombre().find(patron, 0) < estudiantes[i].getNombre().size())
        {
            consultarEstudiante(estudiantes[i]);
            cout <<"------------------------------" <<endl;
            ++estudiantesEncontrados;
        }
    }

    cout <<estudiantesEncontrados <<" estudiantes encontrados." <<endl <<endl;
}

void Grupo::modificarEstudiante()
{
    string codigo;
    int i;

    cout <<"Código: ";
    getline(cin, codigo);
    for (i = 0; i < contadorEstudiantes; ++i)
    {
        if (estudiantes[i].getCodigo() == codigo)
        {
            string nuevoNombre;
            string nuevoCodigo;
            string nuevoCarrera;

            consultarEstudiante(estudiantes[i]);
            cout <<endl <<"Ingresa los nuevos datos" <<endl
                <<"Nombre: ";
            getline(cin, nuevoNombre);
            cout <<"Carrera: ";
            getline(cin, nuevoCarrera);
            cout <<"Código: ";
            getline(cin, nuevoCodigo);

            // Actualizar datos
            estudiantes[i].setNombre(nuevoNombre);
            estudiantes[i].setCarrera(nuevoCarrera);
            estudiantes[i].setCodigo(nuevoCodigo);

            cout <<"Datos actualizados con éxito." <<endl <<endl;
            break;
        }
    }
    if (i == contadorEstudiantes)
    {
        cout <<"Código no registrado." <<endl <<endl;
    }
}