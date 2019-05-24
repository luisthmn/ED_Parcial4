#include <cstdlib>
#include <iostream>
#include "clases.cpp"

using namespace std;

int main()
{
    cout << "Este programa crea un arbol binario" << endl;

    arbol a;

    a.agregar(10);
    a.agregar(3);
    a.agregar(4);
    a.agregar(8);
    a.agregar(12);
    a.agregar(15);
    a.pintar();
    cout << endl << endl << endl << endl;
    a.borrar(8);
    a.pintar();

    system("pause");
    return 0;
}
