#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#include <iostream>
#include <stdexcept> // Permite lanzar excepciones

using namespace std;

template <typename T>
class ListaEstatica
{
public:
    // El constructor recibirá un posible valor que represente el tamaño
    // de la lista.
    ListaEstatica(size_t n = CAPACITY)
    {
        if (n > CAPACITY)
        {
            throw invalid_argument("list size greater than its capacity");
        }
        index = 0;
        containerSize = n;
    }

    bool empty() const;
    bool full() const;
    size_t size() const;
    void push_front(const T& element);
    void push_back(const T& element);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& element);
    void erase(size_t position);
    T& operator [] (size_t position);
    void clear();
    void remove(const T& value);

private:
    static const size_t CAPACITY = 1000;
    T elements[CAPACITY];
    size_t index;
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
        throw runtime_error("Trying push_front() on a full list");
    }

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
        throw runtime_error("Trying push_back() on a full list");
    }

    elements[index++] = element;
}

template<typename T>
const T& ListaEstatica<T>::front() const
{
    if (empty())
    {
        throw runtime_error("Trying front() from an empty list.");
    }

    return elements[0];
}

template<typename T>
const T& ListaEstatica<T>::back() const
{
    if (empty())
    {
        throw runtime_error("Trying back() from an empty list.");
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
        throw runtime_error("Trying pop_back() from an empty list.");
    }
    --index;
}

template<typename T>
void ListaEstatica<T>::insert(size_t position, const T& element)
{
    if (full())
    {
        throw runtime_error("Trying insert() on a full list.");
    }
    else if (position > size())
    {
        throw runtime_error("Trying insert() in a non valid position.");
    }
    else if (position == size())
    {
        push_back(element);
    }
    else
    {
        for (size_t i(index); i > position; --i)
        {
            elements[i] = elements[i-1];
        }
        elements[position] = element;
        ++index;
    }
}

template<typename T>
void ListaEstatica<T>::erase(size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying erase() from an empty list.");
    }
    else if(position >= size())
    {
        throw runtime_error("Trying erase() from a non valid position.");
    }
    else if (position == size()-1)
    {
        pop_back();
    }
    else
    {
        --index;
        for (size_t i(position); i < size(); ++i)
        {
            elements[i] = elements[i+1];
        }
    }
}

template<typename T>
T& ListaEstatica<T>::operator [] (size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying [] from an empty list.");
    }
    else if(position >= size())
    {
        throw runtime_error("Trying [] from non valid position.");
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