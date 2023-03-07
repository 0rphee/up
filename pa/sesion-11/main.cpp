#include <iostream>

#define MAX 100

struct Vehiculo {
    char  marca[MAX]  = {'\0'};
    char  modelo[MAX] = {'\0'};
    int   anio          {0};
    int   ruedas        {0};
    float kilometraje   {0};
    char  color[MAX]  = {'\0'};
    char  placa[MAX]  = {'\0'};
};

int main(){
    struct Vehiculo vehiculo [10];

    for (int i {0}; i < 10; i++){
        printf("Ingresa la marca del auto: %d", i + 1 );
        std::cin >> vehiculo[i].marca; 

        printf("Ingresa el modelo del auto: %d", i + 1 );
        std::cin >> vehiculo[i].modelo; 

        printf("Ingresa el año del auto: %d", i + 1 );
        std::cin >> vehiculo[i].anio; 

        printf("Ingresa el número de ruedas del auto: %d", i + 1 );
        std::cin >> vehiculo[i].ruedas; 

        printf("Ingresa kilometraje del auto: %d", i + 1 );
        std::cin >> vehiculo[i].kilometraje; 

        printf("Ingresa el color del auto: %d", i + 1 );
        std::cin >> vehiculo[i].color; 

        printf("Ingresa la placa del auto: %d", i + 1 );
        std::cin >> vehiculo[i].placa; 
    }
}





