#include <iostream>
#include <cstdlib>
#include "clases.h"

using namespace std;

int main()
{
    cout << "Programa para crear montones/heaps" << endl << endl << endl << endl;

    monton a;

    a.agregar(4);
    a.agregar(8);
    a.agregar(10);
    a.agregar(6);
    a.agregar(21);
    a.pintar();


    system("pause");
    return 0;
}
