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
    void setPatas(short patas);
    void setOjos(short ojos);
    void setSonido(std::string sonido);
    void setColor(std::string color);
    void setTipo(std::string Tipo);

    short getPatas();
    short getOjos();
    std::string getSonido();
    std::string getColor();
    std::string getTipo();
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

void Animal::setPatas(short patas){
    this->numPatas = patas;
}
short Animal::getPatas(){
    return  this->numPatas;
}

void Animal::setOjos(short ojos){
    this->numOjos = ojos;
}
short Animal::getOjos(){
    return  this->numOjos;
}

void Animal::setSonido(std::string sonido){
    this->sonido_r = sonido;
}
std::string Animal::getSonido(){
    return  this->sonido_r;
}

void Animal::setColor(std::string color){
    this->color = color;
}
std::string Animal::getColor(){
    return  this->color;
}

void Animal::setTipo(std::string tipo){
    this->tipo = tipo;
}
std::string Animal::getTipo(){
    return  this->tipo;
}

