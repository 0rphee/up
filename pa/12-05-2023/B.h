#pragma once
#include "A.h"

class B : private A{
protected:
    int b_dato_protegido;
private:
    int b_dato_privado;
public:
    int b_dato_publico;
    B();
    ~B();
};

B::B(){}

B::~B(){}
