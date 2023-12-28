#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <stdexcept>
#include "ldl.h"

using namespace std;

template<typename T>
class Pila  //Stack
{
private:
    LDL<T> list;

public:
    Pila(){}
    ~Pila()
    {
        list.clear();
    }
    bool empty() const;
    size_t size() const;
    const T& top() const;
    void push(const T& element);
    void pop();
};

template<typename T>
bool Pila<T>::empty() const
{
    return list.empty();
}

template<typename T>
size_t Pila<T>::size() const
{
    return list.size();
}

template<typename T>
const T& Pila<T>::top() const
{
    if (empty())
    {
        throw runtime_error("Trying top() from an empty stack.");
    }
    return list.back();
}

template<typename T>
void Pila<T>::push(const T& element)
{
    list.push_back(element);
}

template<typename T>
void Pila<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Trying pop() from an empty stack.");
    }
    list.pop_back();
}
#endif // PILA_H