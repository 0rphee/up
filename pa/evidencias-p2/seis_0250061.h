#include <iostream>

// Ejercicio de estructuras y bibliotecas del zoológico
namespace seis{

    struct Animal {
        int ojos {0};
        int patas {0};
        char color [30] {'\0'};
        char tipo [50] {'\0'};
        char nombre [50] {'\0'};
        bool alas = false;
        bool pelo = false;
    };

    struct Zoo {
        Animal * animales{NULL};
        char nombreZoo [50] {'\0'};
        char domicilio [50] {'\0'};
        int cantAnimales {0};
    };

    int main () {
        struct Zoo * zoo;
        zoo = new Zoo;

        std::cout << "Ingrese el nombre del Zoo: ";
        std::cin >> zoo->nombreZoo; //"->" se utiliza para acceder a la dirección de...
        std::cout << "\nIngrese la dirección: ";
        std::cin >> zoo->domicilio;
        std::cout << "\nIngrese la cantidad de animales: ";
        std::cin >> zoo->cantAnimales;
        zoo->animales = new Animal{zoo->cantAnimales};

        for (int i = 0; i < zoo->cantAnimales; i++){
            std::cout << "\nIngrese el nombre del animal: ";
            std::cin >> (zoo->animales + i)->nombre;
            std::cout << "\nIngrese el tipo de animal: ";
            std::cin >> (zoo->animales + i)->tipo;
            std::cout << "\nEl animal tiene alas? ";
            std::cin >> (zoo->animales + i)->alas;
            std::cout << "\nEl animal tiene pelo?";
            std::cin >> (zoo->animales + i)->pelo;
            std::cout << "\nIngrese el número de patas: ";
            std::cin >> (zoo->animales + i)->patas;
        }
        std::cout << "=================================================" << std::endl;
        std::cout << "NOMBRE DEL ZOO: " << zoo->nombreZoo << std::endl;
        std::cout << "DOMICILIO DEL ZOO: " << zoo->domicilio << std::endl << std::endl;

        for (int i = 0; i < zoo->cantAnimales; i++) {
            std::cout << "- Nombre del animal: " << (zoo->animales + i)->nombre << std::endl;
            std::cout << "- Tipo del animal: " << (zoo->animales + i)->tipo << std::endl;
            std::cout << "- Alas: " << (zoo->animales + i)->alas << std::endl;
            std::cout << "- Pelo: " << (zoo->animales + i)->pelo << std::endl;
            std::cout << "- Número de patas: " << (zoo->animales + i)->patas << std::endl;
        }

        delete[] zoo->animales;
        delete zoo;
    }
}




