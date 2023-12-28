#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H
#include <iostream>
#include <stdexcept> //Permite lanzar excepciones

using namespace std;

template<typename T>//Indicamos que la clase será una plantilla y el tipo de dato es T
class ListaEstatica
{
public:
    ListaEstatica(size_t n=CAPACITY)
    {
        if (n > CAPACITY)
        {
            throw invalid_argument("List size greater than list capacity.");
        }
        index = 0;
        containerSize = n;
    }

    bool empty() const;
    bool full() const;
    size_t size() const; //entero sin signo, se sutiliza para tamaños de colecciones.
    void push_front(const T& element);
    void push_back(const T& element);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& element);
    void erase(size_t position);
    T& operator [](size_t position);
    void clear();
    void remove(const T& value);

private:
    static const size_t CAPACITY = 1000;
    T elements[CAPACITY];
    //index nos va a permitir saber el tamaño de la lista y
    //la posición del siguiente elemento.
    size_t index;
    //containerSize nos indicará el tamaño con el cual se creó la lista.
    size_t containerSize;
};

template<typename T>
bool ListaEstatica<T>::empty() const
{
    return index == 0;
}

template<typename T>
bool ListaEstatica<T>::full() const
{
    return index == containerSize;
}

template<typename T>
size_t ListaEstatica<T>::size() const
{
    return index;
}

template<typename T>
void ListaEstatica<T>::push_front(const T& element)
{
    if (full())
    {
        throw runtime_error("Trying push_front(const T& element) on a full list.");
    }

    // 0    1
    //[55][33]
    //push_front(77)
    //      |
    //      V
    // 0    1   2
    //[77][55][33]

    for (size_t i(index); i > 0; --i)
    {
        elements[i] = elements[i-1];
    }

    elements[0] = element;
    ++index;
}

template<typename T>
void ListaEstatica<T>::push_back(const T& element)
{
    if (full())
    {
        throw runtime_error("Trying push_back(const T& element) on a full list");
    }
    // 0    1
    //[55][33]
    //push_back(77)
    //      |
    //      V
    // 0    1   2
    //[55][33][77]

    elements[index++] = element;
}

template<typename T>
const T& ListaEstatica<T>::front() const
{
    if (empty())
    {
        throw runtime_error("Trying front() from empty list");
    }
    return elements[0];
}

template<typename T>
const T& ListaEstatica<T>::back() const
{
    if (empty())
    {
        throw runtime_error("Trying back() from empty list");
    }
    return elements[index-1];
}

template<typename T>
void ListaEstatica<T>::pop_front()
{
    if (empty())
    {
        throw runtime_error("Trying pop_front() from an empty list.");
    }

    // 0    1   2 index
    //[55][33][77][ ]
    //pop_front()
    //      |
    //      V
    // 0    1 index
    //[33][77][ ]

    for (size_t i(0); i < index-1; ++i)
    {
        elements[i] = elements[i+1];
    }
    --index;
}

template<typename T>
void ListaEstatica<T>::pop_back()
{
    if (empty())
    {
        throw runtime_error("Trying pop_back() from an empty list");
    }

    // 0    1   2 index
    //[55][33][77][ ]
    //pop_back()
    //      |
    //      V
    // 0   index
    //[55][33][77]
    --index;
}

template<typename T>
void ListaEstatica<T>::insert(size_t position, const T& element)
{
    if (full())
    {
        throw runtime_error("Trying insert() in a full list.");
    }
    if (position > size())
    {
        throw runtime_error("Trying insert() in non valid position.");
    }
    if (position == size())
    {
        push_back(element);
    }

    // 0    1   2 index
    //[55][33][77][ ]
    //insert(2, 44)
    //      |
    //      V
    // 0    1   2   3 index
    //[55][33][44][77][ ]
    for (size_t i(index); i > position; --i)
    {
        elements[i] = elements[i-1];
    }
    elements[position] = element;
    ++index;
}

template<typename T>
void ListaEstatica<T>::erase(size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying erase() from an empty list.");
    }
    if (position >= size())
    {
        throw runtime_error("Trying erase() in non valid position.");
    }
    if (position == size()-1)
    {
        pop_back();
    }
    else
    {
        // 0    1   2   3  index
        //[55][33][44][77][ ]
        //erase(1)
        //      |
        //      V
        // 0    1   2 index
        //[55][44][77][ ]
        for (size_t i(position); i < index-1; ++i)
        {
            elements[i] = elements[i+1];
        }
        --index;
    }
}

template<typename T>
T& ListaEstatica<T>::operator [](size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying [] on empty list.");
    }
    if (position >= size())
    {
        throw runtime_error("Trying [] in non valid position.");
    }
    return elements[position];
}

template<typename T>
void ListaEstatica<T>::clear()
{
    index = 0;
}

template<typename T>
void ListaEstatica<T>::remove(const T& value)
{
    if (empty())
    {
        throw runtime_error("Trying remove() from an empty list.");
    }
    // 0    1   2   3   4 index
    //[55][33][77][33][99][ ]
    //remove(33)
    //      |
    //      V
    // 0    1   2 index
    //[55][77][99][ ]
    for (size_t i(0); i < size(); ++i)
    {
        if (elements[i] == value)
        {
            erase(i);
            --i;
        }
    }
}

#endif // LISTA_ESTATICA_H