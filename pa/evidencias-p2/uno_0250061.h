#include <iostream>
#include "aritmetica_0250061.h"

// Ejercicio de aritmética creando funciones en una biblioteca
// menu para elegir entre operaciones aritméticas y mensajes

namespace uno{

int main(){
    int opc {0};
    do {
    	opc = aritmetica::enterInt("1 - Aritmética\n2 - Hola\n3 - Salir\nIngrese la opción que desee: ");
    	switch (opc){
    		case 1:
                aritmetica::aritmetica();
    			break;
    		case 2:
    			printf("¡Hola!\n");
    			break;
    		case 3:
    			printf("Salida\n");
    			break;
    		default:
    			printf("No se ingresó una opción válida\n");
    			break;
    	}
    } while(opc != 3);
	return 0;
}

}