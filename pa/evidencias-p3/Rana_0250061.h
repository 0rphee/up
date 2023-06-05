#pragma once
#include <iostream>
#include "Animal_0250061.h"

class Rana : Animal {
private:
    bool veneno;

public:
    Rana();
    Rana(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, bool veneno);
    ~Rana();

    void saltar();
    void sonido();

    bool getVeneno();
    void setVeneno(bool tieneVeneno);
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

bool Rana::getVeneno(){
    return this->veneno;
}
void Rana::setVeneno(bool tieneVeneno){
    this->veneno = tieneVeneno;
}
