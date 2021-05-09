#include <iostream>
#include <time.h>
using namespace std;

struct Nodo{
    int numero;
    Nodo *siguiente;
};

void insertarNodos(Nodo *&);
void mostrarNodos(Nodo *);
void suma(Nodo *);
void eliminar(Nodo *&, int);
void menu(Nodo *, int);
int main()
{
    int num;
    Nodo *lista = NULL;
    int respuesta = 0;
    insertarNodos(lista);
    do{
        cout << "\n<----¿QUE DESEA HACER?---->\n 1-Imprimir\n 2-Suma de Nodos\n 3-Eliminar\n 4-Salir\n";
        cin >> respuesta;
        menu(lista, respuesta);
    }while(respuesta != 4);
    return 0;
}

void menu(Nodo *lista, int respuesta){

    switch(respuesta){
    case 1: mostrarNodos(lista);
        break;
    case 2: suma(lista);
        break;
    case 3: int num; cout << "\nCual desea eliminar?\n"; cin >> num; eliminar(lista, num);
        break;
    case 4: cout << "\n\nGracias por usar mi programa!!!\n";exit(0);
        break;
    default: cout << "\nIngrese Una respuesta Valida\n";
    }

}



void insertarNodos(Nodo *&lista){
    int num, cont = 0;
    srand(time(NULL));
        do{
        Nodo *nuevo_nodo = new Nodo();
            num = 1 + rand() % 300;
            Nodo *primero = lista;
            nuevo_nodo->numero = num;
            if(lista == primero){
            lista = nuevo_nodo;
            }
            nuevo_nodo->siguiente = primero;
            cont++;
    }while(cont!=4);

}

void mostrarNodos(Nodo *lista){
    Nodo *nodo = new Nodo();
    nodo = lista;

    while(nodo != NULL){
        cout << nodo->numero << "--";
        nodo = nodo->siguiente;
    }
}

void suma(Nodo *lista){
    Nodo *nodo = new Nodo();
    nodo = lista;
    int suma = 0;
    while(nodo != NULL){
        suma += nodo->numero;
        nodo = nodo->siguiente;
    }
    cout << "La suma de nos Nodos es:\n" << suma;

}

void eliminar(Nodo *&lista, int num){
    if(lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;
        while(aux_borrar != NULL && aux_borrar->numero != num){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if(aux_borrar == NULL){
            cout << "\nElemento no encontrado\n";
        }else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
            cout << "\nElemento eliminado\n";
        }else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            cout << "\nElemento eliminado\n";
        }
    }
}
