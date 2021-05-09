#include <iostream>
#include <string.h>

using namespace std;

struct Nodo{
    string cadenas;
    Nodo *siguiente;
}*primero, *ultimo;

void insertarNodo(string);
void mostrarLista();
void eliminar(string);
int main()
{

    int decision = 1;
    string cadena, aEliminar;

    while(decision != 4){
        cout << "¿Que desea hacer?\n 1-Insertar Cadena\n 2-Imprimir\n 3-Eliminar\n 4-Salir\n";
        cin >> decision;
        if(decision == 1){
            cout << "Inserte Cadena\n";
            cin >> cadena;
            insertarNodo(cadena);
        }else if(decision == 2){
            mostrarLista();
        }else if(decision == 3){
            cout << "Digite el que desea eliminar";
            cin >> aEliminar;
            eliminar(aEliminar);
        }else{
            break;
        }
    }
    return 0;
}

void insertarNodo(string cadena){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->cadenas = cadena;

    if(primero == NULL){
        primero = nuevo_nodo;
        primero->siguiente = primero;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = primero;
        ultimo = nuevo_nodo;
    }
   cout << "Nodo Ingresado \n";
}

void mostrarLista(){
    Nodo *actual = new Nodo();

    actual = primero;
    if(primero != NULL){
        do{
            cout << actual->cadenas << "-->";
            actual = actual->siguiente;
        }while(actual != primero);
    }else{
        cout << "Lista Vacia\n";
    }
    cout << "\n\n";
}

//10.12 ELIMINAR UNA PALABRA DADA DE LA LISTA

void eliminar(string aEliminar){
    Nodo *eliminar = new Nodo();
    Nodo *aux;
    eliminar = primero;
    bool eliminado = false;
    if(primero != NULL){
    do{
        if(eliminar->cadenas == aEliminar){
          aux = eliminar->siguiente;
          delete eliminar;
          eliminar->siguiente = aux;
          cout << "Nodo Eliminado";
          eliminado = true;
          break;
        }
        eliminar = eliminar->siguiente;
    }while(eliminar != primero || eliminado == true);
    if(eliminado == false){
        cout << "Cadena no encontrada\n";
    }
    }else{
        cout << "Lista Vacia\n";
    }
}


/*void ordenar_t(){
 Nodo *p = primero;
 string aux;
 while(p != NULL){
    Nodo *j = p->siguiente;
    while(j != NULL){
        int cont = strcmp(p->cadenas, j->cadenas);
        if(cont > 0){
            aux = j->cadenas;
            j->cadenas = p->cadenas;
            p->cadenas = aux;
        }
    j = j->siguiente;
    }
 p = p->siguiente;
 }
}*/
