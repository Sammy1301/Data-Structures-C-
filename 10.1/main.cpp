#include <iostream>
#include <time.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarNodo(Nodo *&);
void mostrarLista(Nodo *);
void eliminar(Nodo *&, int);
int main()
{
    Nodo *lista = NULL;
    int num;
    insertarNodo(lista);
    cout <<"\nInserte numero menor a los que desea eliminar\n";
    cin >> num;
    eliminar(lista, num);
    cout << "\nListo!" << endl;
    return 0;
}


void insertarNodo(Nodo *&lista){
    int num, cont = 0;
    srand(time(NULL));
    while(cont!=10){
        num = 1+ rand() % 100;
        if(num%2==0){
            Nodo *nuevo = new Nodo();
            Nodo *fijo = lista;
            nuevo->dato = num;
            if(lista == fijo){
            lista = nuevo;
            }
            nuevo->siguiente = fijo;
            cont++;
        }
    }
    cout << "NUMEROS INTRIDUCIDOS INTRODUCIDOS:\n";
    mostrarLista(lista);
}

void mostrarLista(Nodo *lista){
    Nodo *nodo = new Nodo();
    nodo = lista;

    while(nodo != NULL){
        cout << nodo->dato << "==>";
        nodo = nodo->siguiente;
    }
}

void eliminar(Nodo *&lista, int num){
    if(lista != NULL){
        Nodo *aEliminar;
        Nodo *aux = lista;
        while(aux != NULL){
            if(lista->dato > num){
                aEliminar = lista;
                lista = lista->siguiente;
                aux = aux->siguiente;
                delete aEliminar;
            }else{
                if(aux->siguiente !=NULL && aux->siguiente->dato > num){
                    aEliminar = aux->siguiente;
                    aux->siguiente = aux->siguiente->siguiente;
                    delete aEliminar;
                }else{
                    aux = aux->siguiente;
                }
            }
        }
    }
    mostrarLista(lista);
}
