#pragma once
#include "A_0250061.h"

class C : protected A{
private:
    int c_dato_privado;  
protected:
    int c_dato_protegido;
public:
    int c_dato_publico;
    C();
    ~C();
};

C::C(){}

C::~C(){}
