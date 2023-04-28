#include <iostream>
//Estructura condicional if/else

int main(int args, const char* argv[]) {
    int numeroUno{ 0 }, numeroDos{ 0 };

    std::cout << "introduce un numero entero" << std::endl; //salida
    std::cin >> numeroUno ;//entrada
    std::cout << "introduce un numero entero" << std::endl;//salida
    std::cin >> numeroDos; //entrada
    if (numeroUno > numeroDos) {
        std:: cout << "Numero uno es mavor" << std::endl;
    } else{}
        std::cout << "Numero dos es mayor" << std::endl;
    return 0;
}

