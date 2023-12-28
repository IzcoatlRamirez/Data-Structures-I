#include "book.h"

Book::Book(unsigned int id, const string &title, const string &author, unsigned int editionNumber, unsigned int inventory, unsigned int available) : id(id), title(title), author(author), editionNumber(editionNumber), inventory(inventory), available(available)
{
}

unsigned int Book::getId() const
{
    return id;
}

void Book::setId(const unsigned int &value)
{
    id = value;
}

string Book::getTitle() const
{
    return title;
}

void Book::setTitle(const string &value)
{
    title = value;
}

string Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(const string &value)
{
    author = value;
}

unsigned int Book::getEditionNumber() const
{
    return editionNumber;
}

void Book::setEditionNumber(const unsigned int &value)
{
    editionNumber = value;
}

unsigned int Book::getInventory() const
{
    return inventory;
}

void Book::setInventory(const unsigned int &value)
{
    inventory = value;
}

unsigned int Book::getAvailable() const
{
    return available;
}

void Book::setAvailable(const unsigned int &value)
{
    available = value;
}

ostream &operator<<(ostream &os, const Book &obj)
{
    os << obj.getId() << "|" << obj.getTitle() << "|" << obj.getAuthor() << "|" << obj.getEditionNumber() << "|" << obj.getInventory() << "|" << obj.getAvailable() << endl;
    return os;
}
istream &operator>>(istream &is, Book &obj)
{
    string aux;
    getline(is, aux, '|');
    if (aux.size() > 0)
    {
        obj.setId(stoi(aux));
        getline(is, aux, '|');
        obj.setTitle(aux);
        getline(is, aux, '|');
        obj.setAuthor(aux);
        getline(is, aux, '|');
        obj.setEditionNumber(stoi(aux));
        getline(is, aux, '|');
        obj.setInventory(stoi(aux));
        getline(is, aux);
        obj.setAvailable(stoi(aux));
    }

    return is;
}
