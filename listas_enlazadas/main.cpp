#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *);
void eliminarNodo(Nodo *&);


int main()
{
    Nodo *lista = NULL;
    int numero;

    cout << "\t Inserte Su Numero\n";
    cin >> numero;
    insertarLista(lista, numero);
    cout << "\t Inserte Su Numero\n";
    cin >> numero;
    insertarLista(lista, numero);
    cout << "\t Inserte Su Numero\n";
    cin >> numero;
    insertarLista(lista, numero);

    mostrarLista(lista);
    buscarLista(lista);
    eliminarNodo(lista);
    mostrarLista(lista);
    return 0;
}

void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();

    actual = lista;

    while(actual != NULL){
        cout << actual->dato << "-->";
        actual = actual->siguiente;
    }
}

void buscarLista(Nodo *lista){
    int n;
    cout << "\nBusque su nodo\n";
    cin >> n;

    bool band = false;

    Nodo *actual = lista;

    while(actual != NULL && actual->dato<=n){
        if(actual->dato == n){
            band = true;
        }
        actual = actual->siguiente;
    }
    if(band == true){
        cout << "Se ha encontrado su nodo\n";
    }else{
        cout << "No se ha encontrado su nodo\n";
    }
}

void eliminarNodo(Nodo *&lista){
    int n;
    cout << "\n Introduzca el valor que quiere eliminar  ";
    cin >> n;
    if(lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;

        while(aux_borrar != NULL && aux_borrar->dato != n){
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
