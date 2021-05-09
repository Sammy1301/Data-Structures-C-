#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <conio.h>
using namespace std;

struct numeros{
    string numero;
    int longitud;
};

int main()
{
    numeros *numeross = new numeros[2];
    for(int i=0; i<2; i++){
        cout << "Ingrese su numero: ";
        cin >> numeross[i].numero;
        numeross[i].longitud = strlen(numeross[i].numero);
    }
    for(int i=0; i<2; i++){
        cout << "Ingrese su numero: ";
        cin >> numeross[i].numero;
        ongitud = strlen(numeross[i].numero);
    }
        cout <<
        cout << ;
    return 0;
}
