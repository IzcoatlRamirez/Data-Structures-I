#ifndef GRUPO_H
#define GRUPO_H
#include <iostream>
#include "estudiante.h"

using namespace std;

class Grupo
{
public:
    Grupo();

    string getMateria() const;
    void setMateria(const string& valor);
    string getClave() const;
    void setClave(const string& valor);
    string getNrc() const;
    void setNrc(const string& valor);
    string getSeccion() const;
    void setSeccion(const string& valor);

    void menu();
    void agregarEstudiante();
    void consultarEstudiante(const Estudiante& e) const;
    void consultarLista() const;
    void buscarEstudiante() const;
    void modificarEstudiante();

private:
    string materia;
    string clave;
    string nrc;
    string seccion;
    //static permite usar la constante sin necesidad de crear un objeto tipo Grupo
    static const int MAX_ESTUDIANTE = 40;
    Estudiante estudiantes[MAX_ESTUDIANTE];
    int contadorEstudiantes;

    enum Opciones
    {
        OPC_SALIR,
        OPC_AGREGAR_ESTUDIANTE,
        OPC_CONSULTAR_LISTA,
        OPC_BUSCAR_ESTUDIANTE,
        OPC_MODIFICAR_ESTUDIANTE
    };

};

#endif // GRUPO_H