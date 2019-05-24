#include <iostream>
#include <cstdlib>
#include "clases.h"

using namespace std;


//-------------------------------------------
monton::monton(){
    raiz = NULL;
    principio = NULL;
    Final = NULL;
    donde = NULL;
}
//------------------------------------------
monton::~monton(){

    nodo *p;

    while(principio){
        p = principio;
        principio = p->siguiente;
        delete p;

    }
        raiz = NULL;
        principio = NULL;
        Final = NULL;
        donde = NULL;
}
//-------------------------------------------------
void monton::agregar(int a){

    nodo *p;
    p = new nodo;
    p->valor = a;
    p->h_izq = NULL;
    p ->h_der = NULL;
    p->siguiente = NULL;
    p->anterior = NULL;

    if(raiz == NULL){
        raiz = p;
        principio = p;
        donde = p;
        Final = p;
        como = H_IZQ;
        p->padre = NULL;
        return;
    }
    else if(como == H_IZQ){
        donde->h_izq = p;
        p->padre = donde;
        como = H_DER;
    }
    else{
        donde->h_der = p;
        p->padre = donde;
        como = H_IZQ;
        donde = donde->siguiente;
    }
    //Agregamos a la lista ordenada
    p->anterior = Final;
    Final->siguiente = p;
    p->siguiente = NULL;
    Final = p;
    subir(p);
}
//-----------------------------------------------------
void monton::subir(nodo *p){

    while(p->padre!=NULL && (p->valor < (p->padre)->valor)){
        intercambiar(p, p->padre);
    }
}
//-----------------------------------------------------------
void monton::bajar(nodo *p){
    nodo *q;

    while(p->h_der !=NULL || p->h_izq!=NULL){

            if(p->h_der!=NULL && p->h_izq == NULL){

                q =p->h_der;
            }
            else if(p->h_der ==NULL && p->h_izq !=NULL){
                q = p->h_izq;
            }

            else{
                if((p->h_der)->valor < (p->h_izq)->valor){
                    q = p->h_der;
                }
                else{
                    q = p->h_izq;
                }
            }

            if(p->valor < q->valor){
                return;
            }
            else{
                intercambiar(p,q);
            }
        }
        return;
}
//-------------------------------------------------------------
void monton::intercambiar(nodo *p, nodo *q){

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
        if(p->padre == NULL){//Conectar nodo p con su padre
            raiz = p;
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

        if(q->padre == NULL){   //Conectar nodo q con su padre
            raiz = q;
        }

        if(p->padre == NULL){                //Conectar nodo p con su padre
            raiz = p;
        }
        else{
            if((p->padre)->h_der == q){
                (p->padre)->h_der = p;
            }
            else{
                (p->padre)->h_izq = p;
            }
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
            }
            else{
                (p->padre)->h_izq = p;
            }
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
    //Fin de codigo intercambiar de arbol binario

    //Intercambiamos ahora en la lista doblemente ligada
    if(p->anterior == q){
        r = q->anterior;
        p->anterior = r;
        q->anterior = p;
        r = p->siguiente;
        q->siguiente = r;
        p->siguiente = q;

        //Checamos los vecinos
        if(p->anterior == NULL){
            principio = p;
        }
        else{
            (p->anterior)->siguiente = p;
        }
        if(q->siguiente==NULL){
            Final = q;
        }
        else{
            (q->siguiente)->anterior = q;
        }
    }
    else if(q->anterior == p){
        //Otro Caso en el que están pegados
        r = p->anterior;
        q->anterior = r;
        p->anterior = q;
        r = q->siguiente;
        p->siguiente = r;
        q->siguiente = p;

        //Checamos los vecinos
        if(q->anterior == NULL){
            principio = q;
        }
        else{
            (q->anterior)->siguiente = q;
        }

        if(p->siguiente==NULL){
            Final = p;
        }
        else{
            (p->siguiente)->anterior = p;
        }
    }
    else{
        //Caso general: Los nodos no están juntos
        nodo *r;
        r = p->siguiente;
        p->siguiente = q->siguiente;
        q->siguiente = r;
        r = p->anterior;
        p->anterior = q->anterior;
        q->anterior = r;

        if(q->anterior == NULL){            //CAMBIAR VECINOS DE P EN LA LISTA DOBLE
            principio = q;
        }
        else{
            q->anterior->siguiente =q;
        }
        if(q->siguiente == NULL){
            Final = q;
        }
        else{
            q->siguiente->anterior = q;
        }


        if(p->anterior == NULL){            //CAMBIAR VECINOS DE P EN LA LISTA DOBLE
            principio = p;
        }
        else{
            p->anterior->siguiente = p;
        }
        if(p->siguiente == NULL){
            Final = p;
        }
        else{
            p->siguiente->anterior = p;
        }
    }

    //Finalmente actualizamos la variable donde
    if(donde == p){
        donde = q;
        return;
    }
    if(donde == q){
        donde = p;
        return;
    }
    return;
}
//-------------------------------------------------------
void monton::pintar(){

    nodo *p;
    p = principio;

    while(p){
        cout << endl << "Nodo: " << p->valor << endl;
        cout << "Su papa es: ";
        if(p->padre==NULL) cout << "NULL" << endl;
        else cout << p->padre->valor<<endl;
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
//----------------------------------------------------------
int monton::sacar(){
    nodo *p;

    int valor = 0;
    if(raiz == NULL) return (999);

    if(principio == Final){

        p = principio;
        valor = p->valor;
        principio ->siguiente = NULL;
        principio =  NULL;
        Final = NULL;
        delete p;
        return valor;

    }
    else{

        intercambiar(principio, Final);

        p = Final;
        valor = p->valor;

        //Desconectamos del arbol
        if(p->padre->h_der == p){
            p->padre->h_der = NULL;
            donde = donde->anterior;
        }
        if(p->padre->h_izq == p){
            p->padre->h_izq = NULL;
        }
        //Terminamos de desconectar del arbol

        //FALTA DESCONECTAR DE LA LISTA LIGADA
        Final = p->anterior;
        p->anterior ->siguiente = NULL;


        delete p;

        p = raiz;
        bajar(p);
        return valor;
    }

}
//-------------------------------------------------------------
