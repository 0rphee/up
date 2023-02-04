
#include <iostream>

int main(){
    std:: cout << "número" << std::endl;

    unsigned char numero{3};
    unsigned char numeroDos{5};

    std::cout << "corrimiento derececha: " << (numero >> 1) << std::endl;
    std::cout << "complemento a uno : " << ((int) (unsigned char) numero ) << std::endl;

    int numeroUno;
    std::cout << "introduzca el número a convertir" << std::endl;
    std::cin >> numeroUno;
    std::cout << "Tamaño de memoria: " << sizeof(numeroUno) << std::endl;

    std::cout << "Tamaño de memoria int : " << sizeof(int) << std::endl;
    std::cout << "Tamaño de memoria char: " << sizeof(char) << std::endl;

    
}
