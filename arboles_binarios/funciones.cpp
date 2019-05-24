#include <cstdlib>
#include <iostream>
#include "clases.cpp"

using namespace std;

//////////////////////////////////
arbol::arbol(){
    raiz = NULL;
    principio = NULL;
    Final = NULL;
    donde = NULL;
    encontrado = NO;
    como = RAIZ;
}
///////////////////////////////////
arbol::~arbol(){
    nodo *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
    raiz = NULL;
    principio = NULL;
    Final = NULL;
    donde = NULL;
    encontrado = NO;
    como = RAIZ;
}
/////////////////////////////////////
void arbol::pintar(){
    nodo *p;
    p = principio;

    while(p){
        cout << endl << "Nodo: " << p->valor << endl;
        cout << "Hijo izquierdo: ";
        if(p->h_izq!=NULL) cout << p->h_izq->valor;
        else cout << "NULL";
        cout << endl;
        cout << "Hijo derecho: ";
        if(p->h_der!=NULL) cout << p->h_der->valor;
        else cout << "NULL";
        cout << endl << endl;

        p = p->siguiente;
    }
}
///////////////////////////////////////
void arbol::buscar(int a){
    nodo *p;
    p = raiz;
    if(p == NULL){
        encontrado = NO;
        donde = NULL;
        como = RAIZ;
        return;
    }
    while(p){
        if(p -> valor == a){
            encontrado = SI;
            if(p == raiz){
                donde = NULL;
                como = RAIZ;
                return;
            }
            donde = p -> padre;
            if(donde -> h_der == p){
                como = H_DER;
            }
            else{
                como = H_IZQ;
            }
            return;
        }
        else if(p -> valor > a){
            if(p -> h_izq == NULL){
                encontrado = NO;
                donde = p;
                como = H_IZQ;
                return;
            }
            else{
                donde = p;
                p = p -> h_izq;
            }
        }
        else if(p -> valor < a){
            if(p -> h_der == NULL){
                encontrado = NO;
                donde = p;
                como = H_DER;
                return;
            }
            else{
                donde = p;
                p = p -> h_der;
            }
        }
    }
}
///////////////////////////////
int arbol::agregar(int a){
    nodo *p;
    buscar(a);
    if(encontrado == SI) return 0;
    p = new nodo;
    p -> valor = a;
    p -> padre = NULL;
    p -> h_der = NULL;
    p -> h_izq = NULL;

    if(como == RAIZ){
        raiz = p;
        p -> padre = NULL;
    }
    else if(como == H_DER){
        donde -> h_der = p;
        p -> padre = donde;
    }
    else{
        donde -> h_izq = p;
        p -> padre = donde;
    }                           //Nodo colocado en el arbol

    //LISTA ORDENADA
    if(como == RAIZ){
        p -> anterior = NULL;
        p -> siguiente = NULL;
        principio = p;
        Final = p;
        return 1;
    }
    if(como == H_DER){
        p -> anterior = donde;
        p -> siguiente = donde -> siguiente;
        donde -> siguiente = p;
        if(p -> siguiente == NULL){
            Final = p;
        }
        else{
            p -> siguiente -> anterior = p;
        }
    }
    else{
        p -> siguiente = donde;
        p -> anterior = donde -> anterior;
        p->siguiente->anterior = p;

        if(p -> anterior == NULL){
            principio = p;
        }
        else{
            p -> anterior -> siguiente = p;
        }
    }
    return 1;
}
///////////////////////////////
void arbol::borrar1(nodo *p){                                         //Borrar nodos con 1 o ningun hijo solamente

    nodo *p1;
    p1 = p;

    //Primero borramos el nodo en el arbol
    if(como==RAIZ){

        if(p1->h_der == NULL && p1->h_izq == NULL){
            delete p1;
        }
        else if(p1->h_izq == NULL){
            (p1->h_der)->padre = NULL;
            raiz = p1->h_der;
        }
        else if(p1->h_der== NULL){
            (p1->h_izq)->padre = NULL;
            raiz = p1->h_izq;
        }
    }
    else if(como == H_DER){
        if(p1->h_der == NULL && p1->h_izq == NULL){
            donde ->h_der = NULL;
        }
        else if(p1->h_izq == NULL){
            donde ->h_der = p1->h_der;
            (p1->h_der)->padre = donde;
        }
        else if(p1->h_der == NULL){
            donde->h_der = p1->h_izq;
            (p1->h_izq)->padre = donde;
        }
    }
    else{
        if(p1->h_der == NULL && p1->h_izq == NULL){
            donde ->h_izq = NULL;
        }
        else if(p1->h_izq == NULL){
            donde->h_izq = p1->h_der;
            (p1->h_der)->padre = donde;
        }
        else if(p1->h_der == NULL){
            donde->h_izq = p1->h_izq;
            (p1->h_izq)->padre = donde;
        }
    }


    //Ahora eliminamos el nodo de la lista ordenada doblemente ligada
    if(p1 == principio){
        if(principio == Final){
            principio = NULL;
            Final = NULL;
        }
        else{
            principio = principio->siguiente;
            principio->anterior = NULL;
        }
    }
    else if(p1 == Final){

        p1->anterior->siguiente = NULL;
        Final = p1->anterior;
    }
    //AHORA CASO GENERAL (NO ESTA EN FINAL NI PRINCIPIO)
    else{
        p1->anterior->siguiente = p1->siguiente;
        p1->siguiente->anterior = p1->anterior;
    }


    delete p1;
    return;
}
///////////////////////////////
int arbol::borrar(int a){
    nodo *p;
    buscar(a);
    if(encontrado == NO) return 0;

    if(como == RAIZ){
        p = raiz;
    }
    else if(como == H_DER){
        p = donde->h_der;
    }
    else{
        p = donde->h_izq;
    }


    if(p->h_der != NULL && p->h_izq != NULL){
        if(p->anterior == NULL){
            intercambiar(p, p->siguiente);
            donde = p->padre;
            if(p->padre->h_izq == p) como = H_IZQ;
            else como = H_DER;
        }
        else{
            intercambiar(p, p->anterior);
            donde = p->padre;
            if(p->padre->h_izq == p) como = H_IZQ;
            else como = H_DER;
        }
    }
    borrar1(p);
    return 1;
}
////////////////////////////////////
void arbol::intercambiar(nodo *p, nodo *q){
    nodo *r;

    if(q->padre == p){          //Caso en el que los nodos están juntos
        if(p->h_der == q){

            r = p->padre;
            p->padre = q->padre;
            q->padre = r;

            r = p->h_der;
            p->h_der = q->h_der;
            q->h_der = r;

            r = p->h_izq;
            p->h_izq = q->h_izq;
            q->h_izq = r;

            q->h_der = p;
            p->padre = q;
        }
        else{

            r = p->padre;
            p->padre = q->padre;
            q->padre = r;

            r = p->h_der;
            p->h_der = q->h_der;
            q->h_der = r;

            r = p->h_izq;
            p->h_izq = q->h_izq;
            q->h_izq = r;

            q->h_izq = p;
            p->padre = q;
        }

    }
    else if(p->padre == q){     //Otro caso en el que los nodos están juntos
        if(q->h_der == p){

            r = p->padre;
            p->padre = q->padre;
            q->padre = r;

            r = p->h_der;
            p->h_der = q->h_der;
            q->h_der = r;

            r = p->h_izq;
            p->h_izq = q->h_izq;
            q->h_izq = r;

            p->h_der = q;
            q->padre = p;
        }
        else{

            r = p->padre;
            p->padre = q->padre;
            q->padre = r;

            r = p->h_der;
            p->h_der = q->h_der;
            q->h_der = r;

            r = p->h_izq;
            p->h_izq = q->h_izq;
            q->h_izq = r;


            p->h_izq = q;
            q->padre = p;
        }

    }
    else{                   //Los casos en los que los nodos no están juntos
        nodo *r;

        r = p->padre;
        p->padre = q->padre;
        q->padre = r;

        r = p->h_der;
        p->h_der = q->h_der;
        q->h_der = r;

        r = p->h_izq;
        p->h_izq = q->h_izq;
        q->h_izq = r;

    }

        if(q->padre == NULL){   //Conectar nodo q con su padre
            raiz = q;
        }
        else{
            if((q->padre)->h_der == p){
                (q->padre)->h_der = q;
            }
            else{
                (q->padre)->h_izq = q;
            }
        }
        if(p->padre == NULL){                //Conectar nodo p con su padre
            raiz = p;
        }
        else{
            if((p->padre)->h_der == q){
                (p->padre)->h_der = p;
                como = H_DER;
            }
            else{
                (p->padre)->h_izq = p;
                como = H_IZQ;
            }
        }


        if(q->h_der !=NULL){                //Conectar hijos con q
            (q->h_der)->padre = q;
        }
        if(q->h_izq !=NULL){
            (q->h_izq)->padre = q;
        }
        if(p->h_der != NULL){             //Conectar hijos con q
            (p->h_der)->padre = p;
        }
        if(p->h_izq !=NULL){
            (p->h_izq)->padre = p;
        }
}
/////////////////////////////////////
