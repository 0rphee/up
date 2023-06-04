#pragma once
#include <iostream>
#include "Animal.h"

class Rana : Animal {
    bool veneno;
    void saltar();
    void sonido();

    public:
    Rana();
    Rana(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, bool veneno);
    ~Rana();
};
Rana::Rana(){}
Rana::~Rana(){}

Rana::Rana(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, bool veneno) : Animal(numPatas, numOjos, sonido_r, tipo, color){
    this->veneno = veneno;
}

void Rana::saltar(){
    std::cout << "Rana salta\n";
}

void Rana::sonido(){
    std::cout << sonido_r << "\n";
}
