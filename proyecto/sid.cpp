#include "sid.h"

Sid::Sid()
{
    loadDB();
}

void Sid::menu()
{
    int opt;
    do
    {
        system(CLEAR);
        cout << "                Menú" << endl
             << endl
             << OPT_EXIT << ") Salir" << endl
             << OPT_LOGIN << ") Login" << endl
             << OPT_SIGNUP << ") SignUp" << endl;
        cin >> opt;
        cin.ignore();
        system(CLEAR);
        switch (opt)
        {
        case OPT_LOGIN:
            login();
            break;

        case OPT_SIGNUP:
            signUp();
            break;

        case OPT_EXIT:
            cout << "Nos vemos..." << endl;
            break;

        default:
            cout << "Sorry, try again" << endl;
            break;
        }
    } while (opt != OPT_EXIT);
}

void Sid::login()
{
    string userName;
    string password;
    vector<User>::iterator it;
    cout << " Log In" << endl
         << "Username: ";
    getline(cin, userName);
    cout << "Password: ";
    getline(cin, password);
    it = find_if(usuarios.begin(), usuarios.end(), [&userName, &password](const User &u) -> bool
                 { return userName == u.getName() && password == u.getPassword(); });
    if (it == usuarios.end())
    {
        cout << "Invalid credentials. Please try again." << endl;
    }
    else
    {
        UserMenu();
    }
    cout << "Presione enter para continuar...";
    getchar();
}

void Sid::signUp()
{
    string userName;
    string password;
    vector<User>::iterator it;
    cout << "                SignUp" << endl
         << "username: ";
    getline(cin, userName);
    it = find_if(usuarios.begin(), usuarios.end(), [&userName](const User &u) -> bool
                 { return userName == u.getName(); });
    if (it != usuarios.end())
    {
        cout << "The username" << userName
             << " is already taken. Please try another one." << endl;
    }
    else
    {
        cout << "Password: ";
        getline(cin, password);
        User u(usuarios.size() + 1, userName, password);
        usuarios.push_back(u);
        cout << "User registered with id" << u.getId() << endl;
        file.open(USERS_FILE, ios::app);
        file << u;
        file.close();
    }

    cout << "Presione enter para continuar...";
    getchar();
}

void Sid::loadBooks()
{
    // lectura
    file.open(BOOK_FILE, ios::in);
    if (!file.is_open())
    {
        cout << "Unable to open books database." << endl;
        cin.get();
    }
    else
    {
        Book b;
        while (file >> b)
        {
            libros.push_back(b);
        }
        file.close();
    }
}

void Sid::UserMenu()
{

    int opt;
    do
    {
        system(CLEAR);

        cout << "          welcome to Sid" << endl
             << USER_SHOW_CATALOGUE << ")show catalogue" << endl
             << USER_SEARH_BOOK << ")searh book" << endl
             << USER_EXIT << ")Log out" << endl
             << "Choose an option";
        cin >> opt;
        cin.ignore();
        switch (opt)
        {

        case USER_SHOW_CATALOGUE:
            ShowCatalogue();
            cout << "Presiona enter para continuar..." << endl;
            cin.get();
            break;

        case USER_SEARH_BOOK:
            searchMenu();
            cout << "Presiona enter para continuar..." << endl;
            cin.get();
            break;

        case USER_EXIT:
            cout << "Loggin out" << endl;
            break;

        default:
            cout << "Invalid option. Try again..." << endl;
            cout << "Presiona enter para continuar..." << endl;
            cin.get();
            break;
        }

    } while (opt != USER_EXIT);
}

void Sid::ShowCatalogue() const
{

    cout << "                 Sid catalogue" << endl;
    for (Book b : libros)
    {
        cout << b;
    }
}

void Sid::searchMenu() const
{

    int opt;
    do
    {
        system(CLEAR);

        cout << "          Search a book" << endl
             << SEARCH_BY_ID << ")Search by id" << endl
             << SEARCH_BY_TITLE << ")search by title" << endl
             << SEARCH_EXIT << ")Return to main menu" << endl
             << "Choose an option";
        cin >> opt;
        cin.ignore();
        switch (opt)
        {

        case SEARCH_BY_ID:
            SearchbyId();
            cout << "Presiona enter para continuar..." << endl;
            cin.get();
            break;

        case SEARCH_BY_TITLE:
            searchbyTitle();
            cout << "Presiona enter para continuar..." << endl;
            cin.get();
            break;

        case SEARCH_EXIT:
            cout << "Returning to main menu" << endl;
            break;

        default:
            cout << "Invalid option. Try again..." << endl;
            cout << "Presiona enter para continuar..." << endl;
            cin.get();
            break;
        }

    } while (opt != SEARCH_EXIT);
}

void Sid::SearchbyId() const
{
    unsigned int id;
    list<Book>::const_iterator it;

    cout << "    Search by id" << endl;
    cin >> id;
    cin.ignore();

    it = find_if(libros.begin(), libros.end(), [&id](const Book &b) -> bool
                 { return id == b.getId(); }

    );
    if (it == libros.end())
    {
        cout << "The book was not found." << endl;
    }
    else
    {

        cout << *it;
    }
}

void Sid::searchbyTitle() const
{
    string title;
    list<Book>::const_iterator it = libros.begin();
    unsigned int found = 0;

    cout << "    Search by Title" << endl
         << "Title:";
    getline(cin, title);
    cin.ignore();

    while (it != libros.end())
    {
        it = find_if(it, libros.end(), [&title](const Book &b) -> bool
                     {
        string pattern=b.getTitle();
        return pattern.find(title,0) < pattern.size(); });
        if (it != libros.end())
        {
            cout << (*it);
            ++found;
            ++it;
        }
    }

    if (found)
    {
        cout << found << "Book" << (found > 1 ? "s" : "") << "found" << endl;
    }
    else
    {
        cout << "No books found." << endl;
    }
}

void Sid::loadUsers()
{

    file.open(USERS_FILE, ios::in);
    if (!file.is_open())
    {
        cout << "Unable to open Users database." << endl;
        cin.get();
    }
    else
    {
        User u;
        while (file >> u)
        {
            usuarios.push_back(u);
        }
        file.close();
    }
}

void Sid::loadDB()
{
    loadUsers();
    loadBooks();
}