#include <iostream>

typedef struct {
    std::string nombre;
    int edad;
    float altura;
    std::string curp;
    std::string direccion;
    std::string fechaNacimiento;
} Persona ;


int main(){
    Persona *personas, *personasCopia;
    int numPersonas {0};

    std::cout << "¿Cuántas personas ingresarás?\n";

    std::cin >> numPersonas;

    personas = new Persona[numPersonas];
    personasCopia = new Persona[numPersonas];
    
    return 0;
}

