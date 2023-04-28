#include <iostream>

// introducción a punteros

namespace tres{
    int main(){
        int a = 10;
        int *puntero = &a;          
        printf("La dirección de a es: %p\n", puntero);
        printf("El valor del puntero es: %d\n", *puntero);

        int **puntero2 = &puntero;
        printf("La dirección del primer puntero es: %p\n", puntero2);

        return 0;
    }
}