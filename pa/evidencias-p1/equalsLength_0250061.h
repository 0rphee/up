MAURO ROGELIO GALINDO IBARRA 0250061
/*
hacer una biblioteca que contenga la función equalsLength, recibe como parámetro dos arreglos y retorna true
si las cosa cadenas contenidas son del mismo tamaño. En caso contrario retorna un false
*/


#include <iostream>

namespace lib{

    inline bool equalsLength(char arr1[], char arr2[]){
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
 
}

