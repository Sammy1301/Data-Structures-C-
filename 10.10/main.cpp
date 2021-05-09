#include <iostream>
#include <string.h>
using namespace std;
struct Nodo{
    string nombre;
    int edad;
    string sexo;
    Nodo *siguiente;
};

void insertarNodo(Nodo *&, string, int, int);
void mostrarLista(Nodo *);
void ordenar_t(Nodo *&);
int main()
{
    Nodo *lista = NULL;
    int cantidad, sexo, edad;
    string nombre;
    cout << "¿Cuantos estudiantes quiere introducir?\n";
    cin >> cantidad;
    for(int i=0; i<cantidad; i++){
        cout << "introduzca Nombre del estudiante\n";
        cin >> nombre;
        cout << "introduzca la Edad del estudiante\n";
        cin >> edad;
        cout << "introduzca el Sexo del estudiante\n 1-Femenino\n 2-Masculino\n";
        cin >> sexo;
        insertarNodo(lista, nombre, edad, sexo);
    }
    cout << "Lista Normal" << endl;
    mostrarLista(lista);
    ordenar_t(lista);
    cout << "Lista Ordenada" << endl;
    mostrarLista(lista);
    return 0;
}




void insertarNodo(Nodo *&lista, string nombre, int edad, int sexo){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre = nombre;
    nuevo_nodo->edad = edad;
    if(sexo == 1){
        nuevo_nodo->sexo = "Femenino";
    }else{
        nuevo_nodo->sexo = "Masculino";
    }
    Nodo *aux1 = lista;
    Nodo *aux2;

    /*while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }*/

    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}

void ordenar_t(Nodo *&lista){
 Nodo *p = lista;
 string aux_nom, aux_sexo;
 int aux_edad;
 bool verificacion = false;
 while(p != NULL){
    Nodo *j = p->siguiente;
    while(j != NULL){
        //int cont = strcmp(p->sexo, j->sexo);
        if(verificacion == false && j->sexo == "Femenino"){

            //asignacion auxiliar
            aux_nom = j->nombre;
            aux_edad = j->edad;
            aux_sexo = j->sexo;

            //cambio de lista
            j->nombre = p->nombre;
            j->edad = p->edad;
            j->sexo = p->sexo;

            //asignacion aux a lista
            p->nombre = aux_nom;
            p->edad = aux_edad;
            p->sexo = aux_sexo;
            verificacion = true;
            break;
        }else if (verificacion == true && j->sexo == "Masculino"){
            //asignacion auxiliar
            aux_nom = j->nombre;
            aux_edad = j->edad;
            aux_sexo = j->sexo;

            //cambio de lista
            j->nombre = p->nombre;
            j->edad = p->edad;
            j->sexo = p->sexo;

            //asignacion aux a lista
            p->nombre = aux_nom;
            p->edad = aux_edad;
            p->sexo = aux_sexo;
            verificacion = false;
            break;
        }
    j = j->siguiente;
    }
 p = p->siguiente;
 }
}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();

    actual = lista;

    while(actual != NULL){
        cout << "Nombre... " << actual->nombre << "\n";
        cout << "Edad..... " << actual->edad << "\n";
        cout << "Sexo..... " << actual->sexo << "\n";
        cout << "<---------------->\n";
        actual = actual->siguiente;
    }
}
