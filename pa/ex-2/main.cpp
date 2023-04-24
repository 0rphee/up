//examen segundo parcial
/*
1) Escriba las líneas faltantes en el siguiente código y ejecútelo, indique el resultado.

union Data{
int data[4] = {0x52505345,0x4152474f,0x4f44414d,0x3b52};
char cad[16];
};
int main (int args, const char* argv[]){
Data *data;
std::cout << data->cad;
return 0;
}
2) Indique las maneras en que se puede definir una constante
3) ¿Qué reglas deben de cumplirse para declarar un identificador?
4) Mencione los tipos de datos que utilizan un byte de memoria
5) Escriba un programa que le permita al usuario ingresar n cantidad de elementos del tipo de una estructura país, la cual tiene como elementos nombre, capital, cantidad de estados, que a su vez contiene una estructura anidada de tipo puntero llamada Estado la cual tiene como miembros nombre, coordenadas, cantidad de municipios, capital, fecha de fundación.
5.1) crear funciones para leer e imprimir los datos en la consola
5.2) crear una biblioteca donde estarán las funciones y las estructuras.
5.3) declare una constate con su nombre completo e imprímalo en la consola
*/


// RESPUESTAS EXAMEN =================================================================== 

// 1)

/*
#include <iostream>

union Data{
    int data[4] = {0x52505345,0x4152474f,0x4f44414d,0x3b52};
    char cad[16];
};

int main (int args, const char* argv[]){
    Data *data = new Data;                 // linea corregida, se añadió '= new Data;'
    std::cout << data->cad;

    printf("\nchar %lu", sizeof(char));
    printf("\nint %lu", sizeof(int));
    printf("\nuint %lu", sizeof(unsigned int));
    printf("\nbool%lu", sizeof(bool));
    
    return 0;
}

output: ESPROGRAMADOR;
*/


// 2) Indique las maneras en que se puede definir una constante
/* Se puede definir mediante una directiva del preprocesador, o también con 'const' por ejemplo:
    #define MI_CONSTANTE 1234
    siendo 1234 la constante que reemplazará al texto 'MI_CONSTANTE' a la hora de compilar el código
    const int constante = 1234;
*/

// 3) ¿Qué reglas deben de cumplirse para declarar un identificador?

/* 
    Se debe de declarar de qué tipo es el identificador, y el nombre del identificador debe de consistir de valores alfanuméricos. Tampoco se puede iniciar el nombre del identificador con espacios, y el identificador no debe tener espacios.

    Si el valor se trata de un puntero, se debe indicar con un caracter de asterisco entre el nombre del identificador y el tipo de dato.
    Ej: int * valor;

Ej:
    - valor; // inválido, le falta el tipo del valor
    - int valor; // válido
    - int valor1928; // válido
    - int valor&/)1928; // inválido, tiene caracteres no-alfanuméricos
*/

// 4) Mencione los tipos de datos que utilizan un byte de memoria
/*
    bool
    char
*/


// 5) Escriba un programa que le permita al usuario ingresar n cantidad de elementos del tipo de una estructura país, la cual tiene como elementos nombre, capital, cantidad de estados, que a su vez contiene una estructura anidada de tipo puntero llamada Estado la cual tiene como miembros nombre, coordenadas, cantidad de municipios, capital, fecha de fundación.
// 5.1) crear funciones para leer e imprimir los datos en la consola
// 5.2) crear una biblioteca donde estarán las funciones y las estructuras.
// 5.3) declare una constate con su nombre completo e imprímalo en la consola
#include <iostream>
#include "lib.h"
#define NOMBRE "MAURO ROGELIO GALINDO IBARRA"


int main(){
    int numPaises {0};
    std::cout << "CONSTANTE: " << NOMBRE << "\n\n";

    std::cout << "Ingrese el número de paises que desea ingresar: "; std::cin >> numPaises; std::cout << std::endl;
    Pais* paises = new Pais[numPaises];

    for (int i {0}; i < numPaises; i++){
        std::cout << "\n------------------------\n";
        std::cout << "Pais " << i+1 << std::endl;
        paises[i] = leerPais();
        std::cout << "------------------------\n";
    }

    std::cout << "\n========================================\n";
    std::cout << "Resultados:";
    std::cout << "\n========================================\n";

    for (int i {0}; i < numPaises; i++){
        std::cout << "\n------------------------\n";
        std::cout << "Pais " << i+1 << std::endl;
        printPais(paises[i]);
        std::cout << "------------------------\n";
    }
    

}



