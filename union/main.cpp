#include <iostream>

using namespace std;

union Peso
{
    int     gramos;
    float   kilos;
};

int main()
{
    Peso cantidad;

    cantidad.gramos = 350;
    cout <<"Peso: " <<cantidad.gramos <<" gramos" <<endl;

    cantidad.kilos = 2.5;
    cout <<"Peso: " <<cantidad.kilos <<" kilos" <<endl;

    cantidad.gramos = 500;
    cout <<"Peso: " <<cantidad.gramos <<" ? " <<endl;

    return 0;
}