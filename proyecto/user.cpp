#include "user.h"

User::User(unsigned int id, const string &userName, const string password) : id(id), name(userName), password(password)
{
}

unsigned int User::getId() const
{
    return id;
}

void User::setId(const unsigned int &value)
{
    id = value;
}

string User::getName() const
{
    return name;
}

void User::setName(const string &value)
{
    name = value;
}

string User::getPassword() const
{
    return password;
}

void User::setPassword(const string &value)
{
    password = value;
}

ostream &operator<<(ostream &os, const User &obj)
{
    os << obj.getId() << "|" << obj.getName() << "|" << obj.getPassword() << endl;

    return os;
}

istream &operator>>(istream &is, User &obj)
{
    string aux;
    getline(is, aux, '|');
    if (aux.size() > 0)
    {
        obj.setId(stoi(aux));
        getline(is, aux, '|');
        obj.setName(aux);
        getline(is, aux);
        obj.setPassword(aux);
    }
    return is;
}