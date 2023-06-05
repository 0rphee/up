#pragma once
#include <iostream>
#include <string>

class Animal {
    protected:
    short numPatas;	
    short numOjos;
    std::string sonido_r;
    std::string tipo;
    std::string color;

    public:
    Animal();
    Animal(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color);
    ~Animal();
    virtual void sonido(){
        std::cout << "Default\n";
    }
};

Animal::Animal(){
    this->numPatas = 0;
    this->numOjos = 0;
    this->sonido_r = "indefinido";
    this->tipo = "indefinido";
    this->color = "indefinido";
}
Animal::Animal(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color){
    this->numPatas = numPatas;
    this->numOjos = numOjos;
    this->sonido_r = sonido_r;
    this->tipo = tipo;
    this->color = color;
}
Animal::~Animal(){}


