#pragma once
#include <iostream>
#include "Animal.h"

class Rana : Animal {
    bool veneno;
    void saltar();
    void sondo();

    public:
    Rana();
    ~Rana();
};
Rana::Rana(){}
Rana::~Rana(){}

