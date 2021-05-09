#include <iostream>

using namespace std;

struct{
    int vector[5] = {60,50,26,24,56};
}MiVector;
int calculaVector(int num1, int num2, int vector1[]){
    for(int i=0; i<5; i++){
        if(vector1[i]==num1){
            if(vector1[i+1]==num2){
                return num1 + num2;
            }else if(vector1[i-1]==num2){return num1 + num2;}
        }else{}
    }
    return 0;
}
int main()
{
    cout << "----VERIFICAR LA SUMA DE DOS NUMEROS SI ESTOS SON CONSECUTIVOS----\n\n";
    int num1 = 0, num2 = 0, resultado = 0;
    cout << "Por favor insertar primer numero: ";
    cin >> num1;
    cout << "Por favor insertar Segundo numero numero: ";
    cin >> num2;
    resultado = calculaVector(num1, num2, MiVector.vector);
    cout << "Resultado: "<< resultado << endl;
    cout << "\n\n0 = No Son Consecutivos\nSuma de los Numero = Son Consecutivos";
    return 0;
}
