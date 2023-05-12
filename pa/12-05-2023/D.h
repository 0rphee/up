#pragma once
#include "C.h"

class D : public A{
private:
    int d_dato_privado;
protected:
    int d_dato_protected;
public:
    int d_dato_publico;
    D();
    D(int dato);
    ~D();
};
D::D(){}

D::D(int dato):A(dato){
    this->setDatoProtegido(dato);
    
}

D::~D(){}

