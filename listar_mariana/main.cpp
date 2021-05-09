#include<stdlib.h>

#include<stdio.h>

#include <iostream>



using namespace std;



struct Nodo

{

    int dato;

    Nodo *derecho;

    Nodo *izquierdo;



};



Nodo *Crear(int);

void Insertar(Nodo *&, int);

void Mostrar(Nodo*, int);

Nodo *Arbol_binario = NULL;

bool Sacar_igual(int, int);







int inf, opcion=0, contador = 0, cont,elemento[15];

int Vect[] = {14,15,4,9,7,18,3,5,16,4,20,17,9,14,5};

int aOrdenar[15];



int main() {



    cout << "---------------------------------------------------------------------------------------------|\n";

    cout << "|...ESTA MOSTRADO DE MANERA HORIZONTAL.......................................................|\n";

    cout << "|...LOS ELEMENTOS QUE ESTAN SEGUIDOS POR LA MISMA LINEA DE PUNTOS VERTICAL QUIERE DECIR QUE..|\n";

    cout << "|...ESTAN EN EL MISMO NIVEL Y SEA AMAS FACIL DE COMPRENDER LA VISIALIZACION DEL ARBOL BINARIO|\n";

    cout << "|--------------------------------------------------------------------------------------------|\n";



            bool repetido = false;



  while(opcion!=4){



    cout << "\n";

    cout << "------------------------------------------ \n";

    cout << "\t          ::::::: Menu:::::::::" << endl;

    cout << " \t 1. LLenar Elementos" << endl;

    cout << " \t 2. Mostrar Arbol con elementos originales" << endl;

    cout << " \t 3. Mostrar Elementos ordenados" << endl;

    cout << " \t 4. Salir \n" << endl;

    cout << "------------------------------------------ \n";

    cout << " opcion: " << endl;

    cin >> opcion;



   switch (opcion)

    {



    case 1:cout << "\n ELEMENTOS INSERTADOS\n";



        for(int m = 0; m<15; m++){
            if(m == 0){
                aOrdenar[m] = Vect[m];
            }else{
                for(int n = 0; n<m; n++){

                    aOrdenar[m] = Vect[m];

                    if(Vect[n] == Vect[m]){

                        aOrdenar[n] = 0;

                    }
                }
            }
                Insertar(Arbol_binario, aOrdenar[m]);

            }

    break;



    case 2:

         if(Arbol_binario== NULL){



    cout << "..................................................................................................\n";

    cout << " \t ESTE ARBOL SE GENERA DE MANERA AUTOMATICA AL ELEGIR OPCION 1 (MOSTRAR ELEMENTOS), \n";

    cout << "\t SI TE HAS TOPADO CON ESTE MENSAJE ES POR QUE AUN NO HAS DECIDIDO QUE SE LLENE :( \n";

    cout << "..................................................................................................\n";

       }

         Mostrar(Arbol_binario, cont);

         cout << "\n";

         break;



        case 3:

               cout<<"ELEMENTOS ORDENADOS\n";

               int auxiliar;

                for(int m = 0; m<15; m++){

                    for(int i = 0; i<m; i++){

                    if(aOrdenar[i] < aOrdenar[m]){



                    auxiliar = aOrdenar[m];

                    aOrdenar[m] = aOrdenar[i];

                    aOrdenar[i] = auxiliar;

                        }

                    }

                }

                cout << "<--- ELEMENTOS ORDENADOS DE MANERA DESCENDENTE\n";

                  for(int m = 0; m<11; m++){

                       cout << aOrdenar[m] << ", ";

                  }

               break;

            }

        }

    }





Nodo* Crear(int inf) {



    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->dato = inf;

    nuevo_nodo->derecho = NULL;

    nuevo_nodo->izquierdo = NULL;

    return nuevo_nodo;



}



void Insertar(Nodo*& Arbol_binario, int inf) {



    if (Arbol_binario == NULL) {

        Nodo* nuevo_nodo = Crear(inf);

        Arbol_binario = nuevo_nodo;

    }



    else {



        int raiz = Arbol_binario->dato;



        if (inf < raiz and inf!=raiz) {

            Insertar(Arbol_binario->izquierdo, inf);



        }

        else if(inf > raiz and inf!=raiz){



            Insertar(Arbol_binario->derecho, inf);



        }

    }

}



void Mostrar(Nodo *Arbol_binario, int cont) {



    if(Arbol_binario!=NULL){



    Mostrar(Arbol_binario->derecho, cont + 1);



    for (int i = 0; i < cont; i++) {

        cout << ".   ";



    }

        cout << Arbol_binario->dato << endl;

        Mostrar(Arbol_binario->izquierdo, cont + 1);



    }



}



