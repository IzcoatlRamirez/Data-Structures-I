#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <iostream>
#include "lista_estatica.h"

using namespace std;

template<typename T>
void bubbleSort(ListaEstatica<T>& lista)
{
    for (size_t i(0); i < lista.size()-1; ++i)
    {
        for (size_t j(0); j < lista.size()-1; ++j)
        {
            if (lista[j+1] < lista[j])
            {
                T aux;
                aux = lista[j+1];
                lista[j+1] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

template<typename T>
void insertionSort(ListaEstatica<T>& lista)
{
T aux;
int j;
for(int i(1);i<=lista.size()-1;i++)
{

    aux=lista[i];
    j=i-1;

    while(j>=0 && lista[j]>aux)
         {

         lista[j+1]=lista[j];
         j=j-1;
         }

    lista[j+1]=aux;
}
}

template<typename T>
void shellSort(ListaEstatica<T>& lista,int n )
{
for (int brecha = n/2; brecha > 0; brecha/= 2)
    {
        for (int i = brecha; i < n; i += 1)
        {
            T temp = lista[i];
 
            
            int j;           
            for (j = i; j >= brecha && lista[j - brecha] > temp; j -= brecha)
            {
                lista[j] = lista[j - brecha];
            }
         
            lista[j] = temp;
        }
    }
   
}

template <typename T>
void selectionSort(ListaEstatica<T>& lista)
{
T aux;
for(int i(0);i<lista.size();i++ )
{
int min=i;
for(int j(i+1);j<lista.size();j++)
{
  if (lista[j]<lista[min])
  {
      min=j;
  }

}
aux=lista[i];
lista[i]=lista[min];
lista[min]=aux;
}
}


template<typename T>
void swap(T *a , T *b) {
  T t = *a;
  *a = *b;
  *b = t;
}


template<typename T>
int particion(ListaEstatica<T>& lista, int low, int high) {
    
  T pivote = lista[high];
  
  int i = (low - 1);

 
  for (int j = low; j < high; j++) {
    if (lista[j] <= pivote) {
      i++;

      swap(&lista[i], &lista[j]);
    }
  }
  swap(&lista[i + 1], &lista[high]);
  return (i + 1);
}

template <typename T>
void quickSort(ListaEstatica<T>& lista, int low, int high)
{

if (low < high) {
      
    int piv = particion(lista, low, high);
    quickSort(lista, low, piv - 1);
    quickSort(lista, piv + 1, high);
  }
}

template<typename T>
void merge(ListaEstatica<T>& lista, int p, int q, int r) {
  
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = lista[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = lista[q + 1 + j];

 
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      lista[k] = L[i];
      i++;
    } else {
      lista[k] = M[j];
      j++;
    }
    k++;
  }


  while (i < n1) {
    lista[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    lista[k] = M[j];
    j++;
    k++;
  }
}


template<typename T>
void mergeSort(ListaEstatica<T>& lista, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(lista, l, m);
    mergeSort(lista, m + 1, r);
    // Merge the sorted sublistaays
    merge(lista, l, m, r);
  }
}


template<typename T>
int sequentialSearch(ListaEstatica<T>& lista, T value)
{
bool encontrado= false;
int i=0;
while(encontrado==false && i<lista.size())
{
if(lista[i]==value)
{
    encontrado=true;
}
++i;
}
if(encontrado==false)
{
 return lista.size();
}
else 
{
    return i-1;
}
}

template<typename T>
int binarySearch(ListaEstatica<T>& lista, T value)
{
  quickSort(lista,0,lista.size()-1);
  int inf,sup,mitad;
  bool encontrado=false;
  inf=0;
  sup=lista.size();

  while(inf<=sup)
  {
    mitad=(inf+sup)/2;
    if(lista[mitad]==value)
    {
    encontrado=true;
    break;
    }
    if(lista[mitad]>value)
    {
      sup=mitad;
      mitad=(inf+sup)/2;
    }
    if(lista[mitad]<value)
    {
      inf=mitad;
      mitad=(inf+sup)/2;
    }
  }
  if(encontrado==true)
  {
    return mitad;
  }
  else
  {
     return lista.size();
  }
}





#endif // ALGORITHMS_H