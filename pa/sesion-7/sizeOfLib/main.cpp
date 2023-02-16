#include <iostream>
#include "bib.h"

int main(){
    std::string str;
    char ch;

    std::cout << "Escribe un texto" << std::endl;

    std::cin >> str;

    std::cout << "Escribe un caracter para buscar en el texto" << std::endl;

    std::cin >> ch;

    std::cout << lib::indexOf(str, ch) << " es el index del caracter en el texto (-1 indica que no se encontró)" << std::endl; 

    return 0;
}
