#pragma once
#include <iostream>
#include "Animal_0250061.h"

class Perro : public Animal {
    private:
    std::string raza;
    void sonido();
    void correr();

    public:
    Perro();
    Perro(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color, std::string raza);
    ~Perro();

    void setPatas(short patas);
    void setOjos(short ojos);
    void setSonido(std::string sonido);
    void setColor(std::string color);
    void setTipo(std::string Tipo);
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

void Perro::setPatas(short patas){
    this->numPatas = patas;
}

void Perro::setOjos(short ojos){
    this->numOjos = ojos;
}

void Perro::setSonido(std::string sonido){
    this->sonido_r = sonido;
}

void Perro::setColor(std::string color){
    this->color = color;
}

void Perro::setTipo(std::string tipo){
    this->tipo= tipo;
}

