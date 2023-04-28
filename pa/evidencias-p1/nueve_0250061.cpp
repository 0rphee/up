#include <iostream>

// Estructura de control for, while, do-while

int main(){
    /// Estructura de control for
    std::cout << "Estructura de control for" << std::endl;
    for (int i = 0; i < 10; i++){
        std::cout << i << std::endl;
    }
    // estructura de control while
    std::cout << "Estructura de control while" << std::endl;
    int operacion{1};
    while (operacion < 0){
        std::cout << "introduce un numero entero" << std::endl;
        std::cin >> operacion;
    }
    // estructura de control do while
    do {
        std::cout << "introduce un numero entero" << std::endl;
        std::cin >> operacion;
    } while (operacion != 0);

    return 0;
}