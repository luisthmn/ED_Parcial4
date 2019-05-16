#include <cstdlib>
#include <iostream>


using namespace std;


//////////////////////////////////
struct nodo{                                                    //Nodos del arbol
    nodo *padre, *h_der, *h_izq, *anterior, *siguiente;
    int valor;
};
///////////////////////////////////
class arbol{
    nodo *raiz, *principio, *Final;
    nodo *donde;
    enum _encontrado{SI, NO}; enum _encontrado encontrado;
    enum _como{VACIO, H_DER, H_IZQ, RAIZ}; enum _como como;     //Variable para saber de que manera está colgando el nodo
                                                                //en el arbol

    public:
    arbol();
    ~arbol();
    void buscar(int a);
    int agregar(int a);
    void pintar();
    int borrar(int a);                            //Borrar nodos con ayuda de la función borrar1
    void borrar1(nodo *p);                        //Borrar nodos con 1 o ningun hijo solamente
    void intercambiar(nodo *p, nodo *q);          //Intercambiar dos nodos en el arbol

};
/////////////////////////////////////////////////
