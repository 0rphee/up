#include "Ejemplo.h"
#include <clocale>

Ejemplo::Ejemplo(){} 

Ejemplo::~Ejemplo(){}

void Ejemplo::Mostrar(){
    cout << "\n\n\n\t\t\tMi primera Línea" << endl;
    cout << "\n\n\n\t\t\tHola mundo" << endl << endl;
}

int Ejemplo::Sumar(int x, int y){
    return x + y;
}
