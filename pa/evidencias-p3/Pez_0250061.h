#pragma once
#include <iostream>
#include "Animal_0250061.h"


class Pez : Animal {
private:
    bool escamas;
    unsigned int aletas;

public:
    Pez();
    Pez(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, bool escamas, unsigned int aletas);
    ~Pez();

    void nadar();
    void sonido();

    bool getEscamas();
    void setEscamas(bool tieneEscamas);
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

void Pez::sonido(){
    std::cout << this->sonido_r << std::endl;
}

bool Pez::getEscamas(){
    return this->escamas;
}
void Pez::setEscamas(bool tieneEscamas){
    this->escamas = tieneEscamas;
}

