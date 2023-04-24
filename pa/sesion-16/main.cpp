#include <iostream>
#include <ostream>
#include <string>
#include "lib.h"
/*

1) Escriba correctamente el siguiente código y ejecútelo, indique el resultado.

union Data{
    int data {0x214b4f}:
    char cad[4]:
};
char main (int 12args, cost char argv[6]){
    Data 14data int;
    cut >> data->cad;
    return 4.0;
}

2) ¿Qué es y para que se utiliza #define?
3) ¿Qué es un puntero?
4) ¿Qué es una estructura?
5) Escriba un programa que le permita al usuario ingresar n cantidad de elementos del tipo de una estructura Alumno, la cual tiene como elementos nombre, edad, curp, fecha de nacimiento, carrera, universidad.
5.1) crear funciones para leer e imprimir los datos en la consola
5.2) crear una biblioteca donde estarán las funciones.
*/


// 1)
// union Data{
//     int data {0x214b4f};
//     char cad[4];
// };

// int main (int arg, const char* argv[]){
//     Data* dataa = new Data;
//     std::cout << dataa->cad;
//     return 4.0;
// }
// imprime: OK!


// 2) el #define se utliiza para para definir macros, que se pueden utilizr en el código y que al compilarse se substituyen por su definición.

// 3) un puntero es una variable que almacena una dirección de memoria.
// 4) es un tipo de dato creado por el programador que puede agrupar múltiples tipos de datos
// 5) 



int main(){
    int numAlums {0};

    std::cout << "Ingrese el número de alumnos a ingresar" << std::endl;
    std::cin >> numAlums;
    
    Alumno* arrAlumnos = new Alumno[numAlums];

    for (int i {0}; i < numAlums; i++ ){
        std::cout << std::endl << "Ingrese la información del alumno " << i+1;
        arrAlumnos[i] = getAlumno();
    }

    for (int i {0}; i < numAlums; i++){
        std::cout << std::endl << "Información del alumno " << i+1;
        printAlumno(arrAlumnos[i]);
    }

    return 0;
}

