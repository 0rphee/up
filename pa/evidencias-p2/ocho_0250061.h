#include <iostream>

namespace ocho {

typedef struct {
    std::string nombre;
    int edad;
    float altura;
    std::string curp;
    std::string direccion;
    std::string fechaNacimiento;
} Persona ;

void swap(Persona* a, Persona* b) {
    Persona temp = *a;
    *a = *b;
    *b = temp;
}

void printPersonas(Persona* personas, int numPersonas) {
    for (int i = 0; i < numPersonas; i++) {
        std::cout << "Nombre: " << personas[i].nombre << std::endl;
        std::cout << "Edad: " << personas[i].edad << std::endl;
        std::cout << "Altura: " << personas[i].altura << std::endl;
        std::cout << "CURP: " << personas[i].curp << std::endl;
        std::cout << "Dirección: " << personas[i].direccion << std::endl;
        std::cout << "Fecha de nacimiento: " << personas[i].fechaNacimiento << std::endl;
        std::cout << std::endl;
    }
}


int main(){
    Persona *personas, *personasCopia;
    int numPersonas {0};

    std::cout << "¿Cuántas personas ingresarás?\n";

    std::cin >> numPersonas;

    personas = new Persona[numPersonas];
    personasCopia = new Persona[numPersonas];

    for (int i = 0; i < numPersonas; i++) {
        std::cout << "Ingresa el nombre de la persona " << i + 1 << ": ";
        std::cin >> personas[i].nombre; std::cout << std::endl;

        std::cout << "Ingresa la edad de la persona " << i + 1 << ": ";
        std::cin >> personas[i].edad; std::cout << std::endl;

        std::cout << "Ingresa la altura de la persona " << i + 1 << ": ";
        std::cin >> personas[i].altura; std::cout << std::endl;

        std::cout << "Ingresa la curp de la persona " << i + 1 << ": ";
        std::cin >> personas[i].curp; std::cout << std::endl;

        std::cout << "Ingresa la dirección de la persona " << i + 1 << ": ";
        std::cin >> personas[i].direccion; std::cout << std::endl;

        std::cout << "Ingresa la fecha de nacimiento de la persona " << i + 1 << ": ";
        std::cin >> personas[i].fechaNacimiento; std::cout << std::endl;
    }
    printf("Swap\n");
    for (int i {0}; i < numPersonas; i++) {
        swap(&personas[i], &personasCopia[i]);
    }

    printf("Personas copia:\n");
    printPersonas(personasCopia, numPersonas);

    printf("Personas originales:\n");
    printPersonas(personas, numPersonas);
    
    delete [] personas;
    delete [] personasCopia;
    return 0;
}

}

