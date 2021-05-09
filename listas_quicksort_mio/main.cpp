#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct nodo{
    int numero;
    nodo *siguiente;
};

void insertarNodo(nodo *&);
void mostrarNodos(nodo *);
int pivote(int [], int, int);
void quicksort(int [], int, int);
void ordenando(nodo *);

int main()
{
    nodo *lista = NULL;
    insertarNodo(lista);
    cout << "\n\n <------Ordenamiento Completado!!------>" << endl;
    return 0;
}

void insertarNodo(nodo *&lista){
    int num, cont = 0;
    srand(time(NULL));
        while(cont!=5){
        num = 1+ rand() % 100;
        if(num%2==0){
            nodo *nuevo = new nodo();
            nodo *fijo = lista;
            nuevo->numero = num;
            if(lista == fijo){
            lista = nuevo;
            }
            nuevo->siguiente = fijo;
            cont++;
        }
    }
    cout << "EN EL ORDEN QUE FUERON INTRODUCIDOS:\n";
    mostrarNodos(lista);
    ordenando(lista);
}

void mostrarNodos(nodo *lista){
    nodo *Nodo = new nodo();
    Nodo = lista;

    while(Nodo != NULL){
        cout << Nodo->numero << "==>";
        Nodo = Nodo->siguiente;
    }
}

int pivote(int lista[], int inicio, int fin){
 int pivote = lista[fin], i = inicio, j=inicio, temp;
    do{
        if(lista[j]<pivote){
            temp = lista[j];
            lista[j] = lista[i];
            lista[i] = temp;
            i++;
        }
        j++;
    }while(j<fin);
    temp = lista[fin];
    lista[fin] = lista[i];
    lista[i] = temp;
    return i;
 }

void quicksort(int lista[], int inicio, int fin){
    int i;
    if(inicio<fin){
        i = pivote(lista, inicio, fin);
        quicksort(lista, inicio, i-1);
        quicksort(lista, i+1, fin);
    }
}

void ordenando(nodo *lista){
    int list[5], i=0;
    nodo *Nodo = new nodo();
    Nodo = lista;

    while(Nodo!=NULL){
        list[i] = Nodo->numero;
        Nodo = Nodo->siguiente;
        i++;
    }
    cout << "\n";
    quicksort(list, 0, 4);
    lista = NULL;
    Nodo = lista;
    for(i=0; i<5; i++){
        nodo *nuevo = new nodo();
        nodo *fijo = lista;
        nuevo->numero = list[i];
        if(lista == fijo){
        lista = nuevo;
        }
        nuevo->siguiente = fijo;
    }
    cout << "LISTA ORDENADA DESCENDENTEMENTE:\n";
    mostrarNodos(lista);
}
