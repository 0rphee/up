#pragma once
#include <iostream>
#include "Animal_0250061.h"

class Perro : public Animal {
private:
    std::string raza;

    public:
    Perro();
    Perro(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, std::string raza);
    ~Perro();

    void sonido();
    void correr();

    void setRaza(std::string raza);
    std::string getRaza();
};
Perro::Perro(){
    this->raza = "indefinido";
}

Perro::Perro(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, std::string raza) : Animal(numPatas, numOjos, sonido_r, tipo, color){
    this->raza = raza;
}

Perro::~Perro(){}

void Perro::sonido(){
    std::cout << sonido_r << "\n";
}

void Perro::correr(){
    std::cout << "Perro corre\n";
}

void Perro::setRaza(std::string raza){
    this->raza = raza;
}

std::string Perro::getRaza(){
    return this->raza;
}
