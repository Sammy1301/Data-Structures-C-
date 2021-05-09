#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void quicksort(int [], int, int);
int pos_pivote(int [], int, int);

int main()
{
srand(time(NULL));
Nodo *Lista = NULL;
    int n, index = 0, vector[5];

    while(index<5){
        n = 1 + rand() % 200;
        if(n%2==0){
        vector[index] = n;
        index++;
        insertarLista(Lista, n);
        }
    }
    cout << "Lista Segun han sido intriducidos los elementos\n";
    mostrarLista(Lista);
    cout << "\n";
    quicksort(vector, 0, 4);
    Lista = NULL;
    for(int i=0; i<5; i++){
        insertarLista(Lista, vector[i]);
    }
    cout << "\n\nLista Ordenada en Forma Descendente\n";
    mostrarLista(Lista);
    return 0;
}

void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}

void mostrarLista(Nodo *Lista){
    Nodo *actual = new Nodo();
    actual = Lista;

    while(actual != NULL){
        cout << actual->dato << "-->";
        actual = actual->siguiente;
    }
}

int pos_pivote(int array[], int izquierda, int derecha){
 int pivote = array[derecha], i = izquierda;
 for(int j = izquierda; j<derecha; j++){
    if(array[j]<pivote){
        swap(array[i], array[j]);
        i++;
    }
 }
 swap(array[derecha], array[i]);
 return i;
}
void quicksort(int array[], int izquierda, int derecha){
    int i;
    if(izquierda<derecha){
        i = pos_pivote(array, izquierda, derecha);
        quicksort(array, izquierda, i-1);
        quicksort(array, i+1, derecha);
    }
}
