#include <iostream>

// Ejercicio con punteros usándolos para crear memoria dinámica

namespace cuatro{
    int main(){
        int nNumeros {0};
        printf("Ingrese el número de elementos que desea en el arreglo: ");
        std::cin >> nNumeros; std::cout << std::endl;

        int *arreglo = new int[nNumeros];

        for (int i = 0; i < nNumeros; i++){
            printf("Ingrese el elemento %d: ", i+1);
            std::cin >> arreglo[i]; std::cout << std::endl;
        }

        // suma de los elementos del arreglo
        int suma {0};
        for (int i = 0; i < nNumeros; i++){
            suma += arreglo[i];
        }
        printf("La suma de los elementos del arreglo es: %d\n", suma);

        delete [] arreglo;
        return 0;
    }
}