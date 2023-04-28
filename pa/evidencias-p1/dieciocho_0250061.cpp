// Creación de una biblioteca con una función llamada indexof
// que retorna el índice donde se encuentra un carácter en una
//  cadena de máximo cien caracteres

#include <iostream>
#include "indexOf_0250061.h"

int main(){
    char* str;
    char ch;

    std::cout << "Escribe un texto" << std::endl;

    std::cin >> str;

    std::cout << "Escribe un caracter para buscar en el texto" << std::endl;

    std::cin >> ch;

    std::cout << lib::indexOf(str, ch) << " es el index del caracter en el texto (-1 indica que no se encontró)" << std::endl; 

    return 0;
}
