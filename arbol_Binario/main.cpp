#include <iostream>
#include "arbolbinario.h"

using namespace std;

int main()
{
    /*
     *        +
     *       / \
     *      A   B
     */

    ArbolBinario<char> left('A');
    ArbolBinario<char> right('B');
    ArbolBinario<char> tree('+', left, right);

    cout <<"pre-orden: ";
    tree.preOrder();
    cout <<endl <<"en-orden: ";
    tree.inOrder();
    cout <<endl <<"post-orden: ";
    tree.postOrder();
    cout <<endl <<endl;

    return 0;
}
