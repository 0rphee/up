#pragma once
#include <iostream>
#include "Animal.h"

class Perro : public Animal {
    std::string raza;
    void sonido();
    void correr();

    public:
    Perro();
    Perro(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, std::string raza);
    ~Perro();
};
Perro::Perro(){
    this->raza = "indefinido";
}

Perro::Perro(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, std::string raza) : Animal(numPatas, numOjos, sonido_r, tipo, color){
    this->raza = raza;
}

Perro::~Perro(){}

