// el programa es una demostración de diferentes tipos de herencia

#include <iostream>
#include "A_0250061.h"
#include "B_0250061.h"
#include "C_0250061.h"
#include "D_0250061.h"


int main(){
    A a;
    a.a_dato_publico = 1;
    printf("a.a_dato_publico: %d", a.a_dato_publico);

    B b;
    printf("b.b_dato_publico: %d", b.b_dato_publico);

    C c;
    printf("c.c_dato_publico: %d", c.c_dato_publico);
    
    D d;
    printf("d.a_dato_publico: %d", d.a_dato_publico);
}

