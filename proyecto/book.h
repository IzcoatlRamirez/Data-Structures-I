#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book
{

public:
    Book(unsigned int id = 0, const string &title = "", const string &author = "", unsigned int editionNumber = 0, unsigned int inventory = 0, unsigned int available = 0);

    unsigned int getId() const;
    void setId(const unsigned int &value);

    string getTitle() const;
    void setTitle(const string &value);

    string getAuthor() const;
    void setAuthor(const string &value);

    unsigned int getEditionNumber() const;
    void setEditionNumber(const unsigned int &value);

    unsigned int getInventory() const;
    void setInventory(const unsigned int &value);

    unsigned int getAvailable() const;
    void setAvailable(const unsigned int &value);

    friend ostream &operator<<(ostream &os, const Book &obj);
    friend istream &operator>>(istream &is, Book &obj);

private:
    unsigned int id;
    string title;
    string author;
    unsigned int editionNumber;
    unsigned int inventory;
    unsigned int available;
};

#endif // USER_H