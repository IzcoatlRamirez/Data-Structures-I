#ifndef LDL_H
#define LDL_H
#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

template<typename T>
class LDL
{
private:
    struct NodeLDL
    {
        T data;
        shared_ptr<NodeLDL> prev;
        shared_ptr<NodeLDL> next;
        NodeLDL(const T& element, shared_ptr<NodeLDL> p=nullptr,
                shared_ptr<NodeLDL> n=nullptr) :
            data(element), prev(p), next(n)
        {}
    };
    size_t listSize;
    shared_ptr<NodeLDL> listFront;
    shared_ptr<NodeLDL> listBack;

public:
    LDL()
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;
    }
    ~LDL()
    {
        clear();
    }

    bool empty() const;
    size_t size() const;
    void push_front(const T& element);
    void push_back(const T& element);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& element);
    void erase(size_t position);
    void clear();
    void remove(const T& element);
    T& operator [] (size_t position);
};

template<typename T>
bool LDL<T>::empty() const
{
    return listSize == 0;
}

template<typename T>
size_t LDL<T>::size() const
{
    return listSize;
}

template<typename T>
void LDL<T>::push_front(const T& element)
{
    if (empty())
    {
        listFront = make_shared<NodeLDL>(element);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodeLDL> newNode = make_shared<NodeLDL>(element, nullptr, listFront);
        listFront->prev = newNode;
        listFront = newNode;
    }
    ++listSize;
}

template<typename T>
void LDL<T>::push_back(const T& element)
{
    if (empty())
    {
        listFront = make_shared<NodeLDL>(element);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodeLDL> newNode = make_shared<NodeLDL>(element, listBack);
        listBack->next = newNode;
        listBack = newNode;
    }
    ++listSize;
}

template<typename T>
const T& LDL<T>::front() const
{
    if (empty())
    {
        throw runtime_error("Trying front() from an empty list.");
    }
    return listFront->data;
}

template<typename T>
const T& LDL<T>::back() const
{
    if (empty())
    {
        throw runtime_error("Trying back() from an empty list.");
    }
    return listBack->data;
}

template<typename T>
void LDL<T>::pop_front()
{
    if (empty())
    {
        throw runtime_error("Trying pop_front() from an empty list.");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        listFront = listFront->next;
        listFront->prev = nullptr;
    }
    --listSize;
}

template<typename T>
void LDL<T>::pop_back()
{
    if (empty())
    {
        throw runtime_error("Trying pop_back() from an empty list.");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        listBack = listBack->prev;
        listBack->next = nullptr;
    }
    --listSize;
}

template<typename T>
void LDL<T>::insert(size_t position, const T& element)
{
    if (empty())
    {
        throw runtime_error("Trying insert() in empty list.");
    }
    if (position > size())
    {
        throw runtime_error("Trying insert() in non valid position.");
    }
    else if (position == 0)
    {
        push_front(element);
    }
    else if (position == size())
    {
        push_back(element);
    }
    else
    {
        shared_ptr<NodeLDL> temp = listFront;
        for (size_t i(0); i < position - 1; ++i)
        {
            temp = temp->next;
        }
        shared_ptr<NodeLDL> newNode = make_shared<NodeLDL>(element, temp, temp->next);
        temp->next->prev = newNode;
        temp->next = newNode;
        ++listSize;
    }
}

template<typename T>
void LDL<T>::erase(size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying erase from an empty list.");
    }
    if (position >= size())
    {
        throw runtime_error("Trying erase from non valid position.");
    }
    else if (position == 0)
    {
        pop_front();
    }
    else if (position == size() - 1)
    {
        pop_back();
    }
    else
    {
        shared_ptr<NodeLDL> temp = listFront;
        for (size_t i(0); i < position - 1; ++i)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
        --listSize;
    }
}

template<typename T>
void LDL<T>::clear()
{
    while(!empty())
    {
        pop_front();
    }
}

template<typename T>
void LDL<T>::remove(const T& element)
{
    if (empty())
    {
        throw runtime_error("Trying remove() from an empty list.");
    }
    else
    {
        T data;
        shared_ptr<NodeLDL> temp = listFront;
        for (size_t i(0); i < size(); ++i)
        {
            data = temp->data;
            temp = temp->next;
            if (data == element)
            {
                erase(i);
                --i;
            }
        }
    }
}

template<typename T>
T& LDL<T>::operator[](size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying [] from an empty list.");
    }

    shared_ptr<NodeLDL> temp = listFront;
    for (size_t i(0); i < position; ++i)
    {
        temp = temp->next;
    }

    return temp->data;
}
#endif // LDL_H