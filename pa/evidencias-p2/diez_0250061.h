#include <iostream>

// ejemplo paso por puntero

namespace diez{
    void duplicarPuntero(int *x){
        *x = *x * 2;
    }
    int main(){
        int a {0};

        std::cout << "Ingrese un número: ";
        std::cin >> a;

        duplicarPuntero(&a);

        std::cout << "El doble del número es: " << a << std::endl;

        return 0;
    }
}