//Librerias estandar
#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int tam = 1000; //Tam de los arrays
    int A[tam], B[tam], R[tam];//Arrays de numeros y de resultados
    int i;
    srand(time(0)); 
    for (int i = 0; i < tam; i++) { //llenado de los dos arreglos (A,B)
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

#pragma omp parallel for shared(A,B,R,tam) private(i) schedule(static,tam)
    for (int i = 0; i < tam; i++) { //for de operaciones
        R[i] = A[i] + B[i];
    }

    // Imprimir los primeros 10 elementos de los arreglos
    //Imprimir valores para checar
    cout << "Primeros 10 elementos de los arreglos:" << endl;
    cout << "A: ";
    for (int i = 0; i < 10; i++) cout << A[i] << " ";
    cout << endl;

    cout << "B: ";
    for (int i = 0; i < 10; i++) cout << B[i] << " ";
    cout << endl;

    cout << "R (resultado): ";
    for (int i = 0; i < 10; i++) cout << R[i] << " ";
    cout << endl;

    return 0;
}
