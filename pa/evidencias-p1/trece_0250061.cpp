// Programa que imprime el número menor de diez números introducidos
// por el usuario

/* hacer una bliblioteca que contenga una funcion llanada min, 
La cual recibira como parametro un arreglo de enteros
y retornara el nunero menor del arreglo */

#include <iostream>
#include "minLib_0250061.hpp"

int getNum(std::string pregunta){
    std::cout << pregunta << std::endl;

    int temp;
    std::cin >> temp;
    return  temp;
}

int main(){
    std::cout << "Dame 10 números enteros" << std::endl;
    int arr[5];
    for (int i = 0; i < 10; i++){
        arr[i] = getNum("Dame el siguiente número");
    }
    std::cout << lib::min(arr, 10) << " es el número más chico" << std::endl;

    return 0;
}


