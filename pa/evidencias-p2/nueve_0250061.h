#include <iostream>

// Ejemplo paso por referencia

namespace nueve{
    void cuadradoReferencia(int &x){
        x = x * x;
    }
    
    int main(){
        int a {0};

        std::cout << "Ingrese un número: ";
        std::cin >> a;

        cuadradoReferencia(a);

        std::cout << "El cuadrado del número es: " << a << std::endl;

        return 0;
    }
}