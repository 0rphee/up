#pragma once
#include <iostream>
#include "Animal.h"


class Pez : Animal {
    bool escamas;
    unsigned int aletas;
    void nadar();

    public:
    Pez();
    Pez(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, bool escamas, unsigned int aletas);
    ~Pez();
    
};

Pez::Pez(){}
Pez::~Pez(){}

Pez::Pez(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, bool escamas, unsigned int aletas) : Animal(numPatas, numOjos, sonido_r, tipo, color){
    this->escamas = escamas;
    this->aletas = aletas;
}

void Pez::nadar(){
    std::cout << "Pez nada\n";
}

