#pragma once
#include <iostream>
#include "Animal.h"


class Pez : Animal {
    bool escamas;
    unsigned int aletas;
    void nadar();

    public:
    Pez();
    ~Pez();
    
};

Pez::Pez(){}
Pez::~Pez(){}


