#include <iostream>

using namespace std;

typedef struct{
   char matricula[8],

   nombre[20],

   carrera[3];

   float puntos;

   int creditos;

} EST;
void entrarDatos(){
    bool nuevo = true;
    int index = 0;
    char decision[1];
    while(nuevo == true){
        count << "Ingrese matricula del estudiante: ";
        cin >> EST.matricula[index];
        cout << "Ingrese Nombre del estudiante: ";
        cin >> EST.nombre[index];
        cout << "Ingrese Carrera del estudiante: ";
        cin >> EST.carrera[index];
        cout << "Ingrese Puntos del estudiante: ";
        cin >> EST.puntos[index];
        cout << "Ingrese Creditos del estudiante: ";
        cin >> EST.creditos[index];
        cout << "Desea Registrar otro estudiante? S/N";
        cin >> decision;
        if(decision == "N" || decision == "n"){
            nuevo = false;
        }else if(decision != "S" || decision == "N" || decision == "n" || decision != "s"){
            cout << "Entre S o N\n";
        }
    }
}
int main()
{
    int indice;
    int longitud = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i<longitud; i++){
        if(array[i]=="45"){
            indice = i;
        }
    }

    cout << indice << endl;
    return 0;
}
