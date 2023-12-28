#include <iostream>
#include "algorithms.h"

using namespace std;

int main()
{
    //bubble sort
    ListaEstatica<int> l;

    for (int i(10); i > 0; --i)
        l.push_back(i);

    cout <<"Inicial: " <<endl;
    for (size_t i(0); i < l.size(); ++i)
        cout <<l[i] <<" ";
    cout <<endl;

    bubbleSort(l);

    cout <<"Final: " <<endl;
    for (size_t i(0); i < l.size(); ++i)
        cout <<l[i] <<" ";

    cout <<endl <<endl;

 ListaEstatica<char> caracter;

        caracter.push_back('a');
        caracter.push_back('b');
        caracter.push_back('f');
        caracter.push_back('a');
        caracter.push_back('c');

    cout <<"Inicial: " <<endl;
    for (size_t i(0); i < caracter.size(); ++i)
        cout <<caracter[i] <<" ";
    cout <<endl;

    bubbleSort(caracter);

    cout <<"Final: " <<endl;
    for (size_t i(0); i < caracter.size(); ++i)
        cout <<caracter[i] <<" ";
        cout<<endl;

//insertion sort 

ListaEstatica<float> flotantes;
for (int i(10); i > 0; --i)
        flotantes.push_back(i);

    cout <<"Inicial: " <<endl;
    for (size_t i(0); i < flotantes.size(); ++i)
        cout <<flotantes[i] <<" ";
    cout <<endl;

    insertionSort(flotantes);

    cout <<"Final: " <<endl;
    for (size_t i(0); i < flotantes.size(); ++i)
        cout <<flotantes[i] <<" ";

    cout <<endl <<endl;

ListaEstatica<char> caracter2;

        caracter2.push_back('a');
        caracter2.push_back('b');
        caracter2.push_back('f');
        caracter2.push_back('a');
        caracter2.push_back('c');

    cout <<"Inicial: " <<endl;
    for (size_t i(0); i < caracter2.size(); ++i)
        cout <<caracter2[i] <<" ";
    cout <<endl;

   insertionSort(caracter2);

    cout <<"Final sh: " <<endl;
    for (size_t i(0); i < caracter2.size(); ++i)
        cout <<caracter2[i] <<" ";
        cout<<endl;




// shelll sort
ListaEstatica<int> lola;

  for (int i(10); i > 0; --i)
        lola.push_back(i);

    cout <<"Inicial: " <<endl;
    for (size_t i(0); i < lola.size(); ++i)
        cout <<lola[i] <<" ";
    cout <<endl;

  shellSort(lola,lola.size());

    cout <<"Final: " <<endl;
    for (size_t i(0); i < lola.size(); ++i)
        cout <<lola[i] <<" ";

    cout <<endl <<endl;


//selection sort

ListaEstatica<int>seleccion;

for (int i(10); i > 0; --i)
        seleccion.push_back(i);

    cout <<"Inicial: " <<endl;
    for (size_t i(0); i < seleccion.size(); ++i)
        cout <<seleccion[i] <<" ";
    cout <<endl;

selectionSort(seleccion);

    cout <<"Final Selection sort: " <<endl;
    for (size_t i(0); i < seleccion.size(); ++i)
        cout <<seleccion[i] <<" ";

    cout <<endl <<endl;


//quick sort

ListaEstatica<int>quick;

for (int i(10); i > 0; --i)
       quick.push_back(i);

    cout <<"Inicial: " <<endl;
    for (size_t i(0); i < quick.size(); ++i)
        cout <<quick[i] <<" ";
    cout <<endl;

quickSort(quick,0,quick.size()-1);

    cout <<"Final quick sort: " <<endl;
    for (size_t i(0); i < quick.size(); ++i)
        cout <<quick[i] <<" ";

    cout <<endl <<endl;


//merge sort
ListaEstatica<char> merge;

        merge.push_back('a');
        merge.push_back('b');
        merge.push_back('f');
        merge.push_back('a');
        merge.push_back('c');

    cout <<"Inicial: " <<endl;
    for (size_t i(0); i < merge.size(); ++i)
        cout <<merge[i] <<" ";
    cout <<endl;

  mergeSort(merge,0,merge.size()-1);

    cout <<"Final merge: " <<endl;
    for (size_t i(0); i < merge.size(); ++i)
        cout <<merge[i] <<" ";
        cout<<endl;

//busqueda secuencial
cout<<"Encontrado en la posicion ss-->"<<sequentialSearch(merge,'a')<<endl;
// busqueda binaria
cout<<"Encontrado en la posicion bs-->"<<binarySearch(merge,'z');














    return 0;
}