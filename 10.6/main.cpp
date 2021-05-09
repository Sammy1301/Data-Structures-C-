#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Nodo{
    char caracter[5];
    Nodo *siguiente, *anterior;
}*primero, *ultimo;

void insertarNodo(char);
void mostrarLista();
void ordenar_t();
int main()
{
    char palabra[20];
    char klk[1];
    Nodo *lista = NULL;
    cout << "Inserte Su palabra" << endl;
    cin >> palabra;
    for(int i=0; i<strlen(palabra); i++){
        klk[0] = palabra[i];
        insertarNodo(klk[0]);
    }
    cout << "Lista desordenada\n";
    mostrarLista();

    cout<<"\nLista Ordenada\n";
    ordenar_t();
    mostrarLista();
    return 0;
}


void insertarNodo(char palabra){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->caracter[0]=palabra;
    if(primero==NULL){
        primero = nuevo_nodo;
        primero->siguiente = NULL;
        primero->anterior = NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = NULL;
        nuevo_nodo->anterior = ultimo;
        ultimo = nuevo_nodo;
    }
}

void mostrarLista(){
    Nodo *actual = new Nodo();

    actual = primero;
    if(primero!=NULL){

        while(actual != NULL){
            cout << actual->caracter[0] << "-->";
            actual = actual->siguiente;
        }
    }else{
        cout << "La lista esta vacia\n";
    }
}
void ordenar_t(){
 Nodo *p = primero;
 char aux[1];
 while(p != NULL){
    Nodo *j = p->siguiente;
    while(j != NULL){
        int cont = strcmp(p->caracter, j->caracter);
        if(cont > 0){
            aux[0] = j->caracter[0];
            j->caracter[0] = p->caracter[0];
            p->caracter[0] = aux[0];
        }
    j = j->siguiente;
    }
 p = p->siguiente;
 }
}
