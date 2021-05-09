#include <iostream>
#include <time.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void llenarPila(Nodo *);
void insertarPila(Nodo *&, int);
void extraerPila(Nodo *&pila);
int main()
{
    Nodo *pila = NULL;

    cout << "Elementos En la manera que fueron Introducidos\n" << endl;
    llenarPila(pila);

    return 0;
}


void llenarPila(Nodo *pila){
    int vector[10], i, n;
    srand(time(NULL));
    for(i = 0; i<10; i++){
        n = 100 - (rand()%150);
        vector[i] = n;
        cout << vector[i] << ", ";
        insertarPila(pila, vector[i]);
    }
    cout << "\n\nElementos Sacados de la pila\n\n";
    for(i = 0; i<10; i++){
    extraerPila(pila);
    }

}

void insertarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

void extraerPila(Nodo *&pila){
     Nodo *aux = pila;
     cout<< aux->dato <<  ", ";
     pila = aux->siguiente;
     delete aux;
}
