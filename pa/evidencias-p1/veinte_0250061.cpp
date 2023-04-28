#include <iostream>
#include "equalsLength_0250061.h"

// Crear biblioteca que contenga una función llamada equalslenght 
// la cual validara si dos cadenas tienen el mismo número de elementos,
//  retorna true o false según sea el caso

void testStrings(int testNum, char x[], char y[]){
    std::printf("Test %d:\n\tString 1: %s\n\tString 2: %s\nResult %d\n\n", testNum, x, y, lib::equalsLength(x, y));
}


int main(){
    char str1[] = "he lo";
    char str2[] = "hello"; 

    testStrings(1, str1, str2);

    char str3[] = "hello";
    char str4[] = "Hello World"; 

    testStrings(2, str3, str4);
    return 0;
}
