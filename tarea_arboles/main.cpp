#include <iostream>

using namespace std;
struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};

int numeros[15] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5};

/*Prototipos de funciones*/
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void imprimir(Nodo *arbol, int);
Nodo *espejo(Nodo *);

int main()
{
    int raiz = 0;
    Nodo *arbol = NULL;
    cout << "-----Arbol Normal-----" << endl;
    for(int i = 0; i<15; i++){
        insertarNodo(arbol, numeros[i]);
    }
    imprimir(arbol, raiz);
    Nodo *espejito;
    espejito = NULL;
    cout << "-----Arbol Espejo-----" << endl;
    espejito = espejo(arbol);
    imprimir(espejito, raiz);
    return 0;
}

Nodo *crearNodo(int n){
    Nodo *nodo = new Nodo();
    nodo->dato = n;
    nodo->der = NULL;
    nodo->izq = NULL;
    return nodo;
}

void insertarNodo(Nodo *&arbol, int n){
    if(arbol == NULL){
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }else{
        int raiz = arbol->dato;
        if(n < raiz){
            insertarNodo(arbol->izq, n);
        }else{
            insertarNodo(arbol->der, n);
        }
    }
}

Nodo *espejo(Nodo *arbol){
    Nodo *cambio;
    if(arbol!=NULL)
    {
          cambio = arbol->izq;
          arbol->izq = espejo(arbol->der);
          arbol->der = espejo(cambio);
    }
    return arbol;
}


void imprimir(Nodo *arbol, int raiz){
    if(arbol != NULL){
        imprimir(arbol->der, raiz+1);
        for(int i=0; i<raiz; i++){
            cout << "  ";
        }
        cout << arbol->dato << endl;
        imprimir(arbol->izq, raiz+1);
    }
}
