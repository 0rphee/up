// programa que calcula el promedio de los números
// introducidos en un array de diez números

#include <iostream>

int main(){
    float array[10];
    float sum {0};

    for (int i {0}; i < 10; i++){
        printf("Deme el valor del número %d: ", i + 1);
        float temp;
        std::cin >> temp;
        array[i] = temp;
        sum += temp;
    }

    printf("La suma total de los valores es: %f, y el promedio es: %f", sum, sum / 10 );
    
    return 0;
}




