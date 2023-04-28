// Programa que mediante un menú el usuario seleccione
// el número de programa a ejecutar y este a su vez
//  deberá llamar a la función que corresponda a 
// dicho programa en su respectiva biblioteca.

#include <iostream>
#include "uno_0250061.h"
#include "dos_0250061.h"
#include "tres_0250061.h"
#include "cuatro_0250061.h"
#include "cinco_0250061.h"
#include "seis_0250061.h"
#include "siete_0250061.h"
#include "ocho_0250061.h"
#include "nueve_0250061.h"
#include "diez_0250061.h"
#include "once_0250061.h"
#include "doce_0250061.h"
#include "trece_0250061.h"
#include "catorce_0250061.h"

int main(){
    int opc {0};
    do {
        std::cout << std::endl;        
        std::cout << "0  - Salir del programa" << std::endl;
        std::cout << "1  - Aritmética" << std::endl;
        std::cout << "2  - Introducción Estructuras" << std::endl;
        std::cout << "3  - Introducción Punteros" << std::endl;
        std::cout << "4  - Ejercicio con punteros usándolos para crear memoria dinámica" << std::endl;
        std::cout << "5  - Ejercicio de estructura Coche" << std::endl;
        std::cout << "6  - Ejercicio de estructuras y biblioteca de Zoológico" << std::endl;
        std::cout << "7  - Ejercicio de Estructura Escuela, Alumno, Materia y Profesor" << std::endl;
        std::cout << "8  - Ejercicio de estructura Persona y función swap usando punteros" << std::endl;
        std::cout << "9  - Ejemplo paso por referencia" << std::endl;
        std::cout << "10 - Ejemplo paso por puntero" << std::endl;
        std::cout << "11 - Ejercicio de referencia con estructuras" << std::endl;
        std::cout << "12 - Ejercicio de copia de datos de un puntero" << std::endl;
        std::cout << "13 - Introducción a uniones" << std::endl;
        std::cout << "14 - Uniones con diferentes tipos de datos" << std::endl;
        std::cout << "Ingrese la opción que  desee: ";
        std::cin >> opc; std::cout << std::endl;
    	switch (opc){
            case 0:
                printf("Salida del programa\n");
                break;
    		case 1:
                uno::main();
                break;
            case 2:
                dos::main();
                break;
            case 3:
                tres::main();
                break;
            case 4:
                cuatro::main();
                break;
            case 5:
                cinco::main();
                break;
            case 6:
                seis::main();
                break;
            case 7:
                siete::main();
                break;
            case 8:
                ocho::main();
                break;
            case 9:
                nueve::main();
                break;
            case 10:
                diez::main();
                break;
            case 11:
                once::main();
                break;
            case 12:
                doce::main();
                break;
            case 13:
                trece::main();
                break;
            case 14:
                catorce::main();
                break;
    		default:
    			printf("No se ingresó una opción válida\n");
    			break;
    	}
    } while(opc != 0);
    
}

