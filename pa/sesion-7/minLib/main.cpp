/* hacer una bliblioteca que contenga una funcion llanada min, 
La cual recibira como parametro un arreglo de enteros
y retornara el nunero menor del arreglo */

#include <iostream>
#include "lib.hpp"

int getNum(std::string pregunta){
    std::cout << pregunta << std::endl;

    int temp;
    std::cin >> temp;
    return  temp;
}

int main(){
    std::cout << "Dame 5 números enteros" << std::endl;
    int arr[5];
    for (int i = 0; i < 5; i++){
        arr[i] = getNum("Dame el siguiente número");
    }
    std::cout << lib::min(arr, 5) << " es el número más chico" << std::endl;

    return 0;
}


