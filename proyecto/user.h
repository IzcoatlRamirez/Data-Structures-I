#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User
{

public:
    // constructor con parametros
    User(unsigned int id = 0, const string &userName = "", const string password = "");

    unsigned int getId() const;
    void setId(const unsigned int &value);

    string getName() const;
    void setName(const string &value);

    string getPassword() const;
    void setPassword(const string &value);

    friend ostream &operator<<(ostream &os, const User &obj);
    friend istream &operator>>(istream &os, User &obj);

private:
    unsigned int id;
    string name;
    string password;
};

#endif // USER_H