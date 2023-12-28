#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <stdexcept>
#include "ldl.h"

using namespace std;

template<typename T>
class Cola // Queue
{
private:
    LDL<T> list;

public:
    Cola(){}
    ~Cola()
    {
        list.clear();
    }

    bool empty() const;
    size_t size() const;
    const T& front() const;
    const T& back() const;
    void push(const T& element);
    void pop();
};

template<typename T>
bool Cola<T>::empty() const
{
    return list.empty();
}

template<typename T>
size_t Cola<T>::size() const
{
    return list.size();
}

template<typename T>
const T& Cola<T>::front() const
{
    if (empty())
    {
        throw runtime_error("Trying front() from an empty queue.");
    }
    return list.front();
}

template<typename T>
const T& Cola<T>::back() const
{
    if (empty())
    {
        throw runtime_error("Trying back() from an empty queue.");
    }
    return list.back();
}

template<typename T>
void Cola<T>::push(const T& element)
{
    list.push_back(element);
}

template<typename T>
void Cola<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Trying pop() from an empty queue.");
    }
    list.pop_front();
}
#endif // COLA_H