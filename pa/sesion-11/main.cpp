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

    int n {0};

    printf("Ingresa el número de vehículos que registrarás: ");
    std::cin >> n;    

    struct Vehiculo * vehiculo = new Vehiculo [n];

    for (int i {0}; i < n; i++){
        printf("Ingresa la marca del auto %d: ", i + 1 );
        std::cin >> (vehiculo + 1) -> marca;

        printf("Ingresa el modelo del auto %d: ", i + 1 );
        std::cin >> (vehiculo + 1) -> modelo;

        printf("Ingresa el año del auto %d: ", i + 1 );
        std::cin >> (vehiculo + 1) -> anio;

        printf("Ingresa el número de ruedas del auto %d: ", i + 1 );
        std::cin >> (vehiculo + 1) -> ruedas;

        printf("Ingresa kilometraje del auto %d: ", i + 1 );
        std::cin >> (vehiculo + 1) -> kilometraje;

        printf("Ingresa el color del auto %d: ", i + 1 );
        std::cin >> (vehiculo + 1) -> color;

        printf("Ingresa la placa del auto %d: ", i + 1 );
        std::cin >> (vehiculo + 1) -> placa;
    }
}





