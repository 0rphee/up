#include <iostream>

// Crear biblioteca que contenga una función llamada equalslenght 
// la cual validara si dos cadenas tienen el mismo número de elementos,
//  retorna true o false según sea el caso

bool mismoTamano(char arr1[], char arr2[]){
    int i {0};

    while (true){
        if (arr1[i] == '\0' || arr2[i] == '\0' ){
            if (arr1[i] == arr2[i]){
                return true;
            }
            return false;
        }
        i++;
    } 
}

void testStrings(int testNum, char x[], char y[]){
    std::printf("Test %d:\n\tString 1: %s\n\tString 2: %s\nResult %d\n\n", testNum, x, y, mismoTamano(x, y));
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
