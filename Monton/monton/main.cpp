#include <iostream>
#include <cstdlib>
#include "clases.h"

using namespace std;

int main()
{
    cout << "Programa para crear montones/heaps" << endl << endl << endl << endl;

    monton a;

    a.agregar(10);
    a.agregar(48);
    a.agregar(71);
    a.agregar(100);
    a.agregar(0);
    a.agregar(3);
    a.agregar(12);
    a.agregar(1);
    a.agregar(15);
    a.agregar(17);
    a.agregar(96);
    a.agregar(14);
    a.agregar(2);
    a.agregar(7);
    a.agregar(8);
    a.agregar(9);
    a.agregar(14);
    a.agregar(27);
    a.agregar(24);
    a.agregar(21);
    a.pintar();
    cout << endl;

    for(int i = 0 ; i < 20 ; i++){
        cout << "BORRE EL NODO: " << a.sacar() << endl;
        a.pintar();
        cout  << endl;
    }
    system("pause");
    return 0;
}
