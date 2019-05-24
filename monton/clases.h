#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

//-----------------------------------------------------------
struct nodo{
    nodo *padre, *h_der, *h_izq, *anterior, *siguiente;
    int valor;
};
//---------------------------------------------------------
class monton{

    nodo *raiz, *principio, *Final, *donde;
    enum _como{H_DER, H_IZQ};
    enum _como como;

    public:
    monton();
    ~monton();
    void agregar(int a);
    int sacar();
    void pintar();
    void subir(nodo *p);
    void bajar(nodo *p);
    void intercambiar(nodo *p, nodo *q);

};
//------------------------------------------------------------

#endif // CLASES_H_INCLUDED
