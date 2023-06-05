#pragma once

#include <iostream>

class A {
protected:
    int a_dato_protegido;
    bool setDatoProtegido(int dato);
    int getDatoProtegido();
private:
    int a_dato_privado;
public:
    int a_dato_publico;
    A();
    A(int dato);
    ~A();
    bool setDatoPrivado(int dato);
    int getDatoPrivado();
};

A::A(int dato){
    this->a_dato_privado = dato;
}

bool A::setDatoPrivado(int dato){
    this->a_dato_privado = dato;
}

int A::getDatoPrivado(){
    return this->a_dato_privado;
}
