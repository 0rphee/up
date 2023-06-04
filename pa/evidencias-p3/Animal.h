#pragma once
#include <iostream>
#include <string>

class Animal {
    protected:
    unsigned int numPatas;	
    unsigned int numOjos;
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

Animal::Animal(){}
Animal::Animal(short numPatas, short numOjos, std::string sonido_r, std::string tipo, std::string color){
    this->numPatas = numPatas;
    this->numOjos = numOjos;
    this->sonido_r = sonido_r;
    this->tipo = tipo;
    this->color = color;
}
Animal::~Animal(){}


