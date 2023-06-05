// instanciación de clase Conceptos con diferentes constructores

#include <iostream>
#include "conceptos_0250061.h"

int main(){
    Conceptos * a = new Conceptos(500);
    std::cout << "dato (constructor 'Conceptos(int a)'): " << a->leerDato() << "\n";

    Conceptos * b = new Conceptos(*a);
    std::cout << "dato (constructor 'Conceptos(Conceptos &a)'): " << b->leerDato() << "\n";

    Conceptos * c = new Conceptos();
    std::cout << "dato (constructor 'Conceptos()'): " << c->leerDato() << "\n";
    return 0;
}
