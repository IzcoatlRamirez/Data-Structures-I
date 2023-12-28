#ifndef SID_H
#define SID_H
#include <iostream>
#include <vector>
#include "user.h"
#include <algorithm>
#include <list>
#include <fstream>
#include "book.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
using namespace std;
class Sid
{

public:
    Sid();
    void menu();

private:
    vector<User> usuarios;
    list<Book> libros;
    fstream file;
    const string USERS_FILE = "C://Users//user//Desktop//Universidad//segundo semestre//seminario estructuras de datos//Ramirez_Cortes_p3//users.txt";
    const string BOOK_FILE = "C://Users//user//Desktop//Universidad//segundo semestre//seminario estructuras de datos//Ramirez_Cortes_p3//books.txt"; // escribir ruta
    enum Opciones
    {
        OPT_EXIT = 0,
        OPT_SIGNUP,
        OPT_LOGIN
    };
    enum UserOptions
    {
        USER_EXIT,
        USER_SHOW_CATALOGUE,
        USER_SEARH_BOOK
    };
    enum SeachOptions
    {
        SEARCH_EXIT,
        SEARCH_BY_ID,
        SEARCH_BY_TITLE
    };
    void signUp();
    void login();
    void loadBooks();
    void UserMenu();
    void ShowCatalogue() const;
    void searchMenu() const;
    void SearchbyId() const;
    void searchbyTitle() const;
    void loadDB();
    void loadUsers();
};

#endif // SID_H