
#include <iostream>
#include <ostream>

int enterNum(const char textoParaMostrar[]){
    printf("%s\n", textoParaMostrar);

    int temp;

    std::cin >> temp;

    return temp;
 }

int main(){

    int lenArr = enterNum("Ingrese la cantidad de número a ingresar y ordenar");

    int nums[lenArr];

    for (int i {0}; i < lenArr; i++ ){
        nums[i] = enterNum("Ingrese el siguiente número");
    }


    for (int i {0}; i < lenArr - 1; i++){
        for (int j {0}; j < lenArr - i - 1; j++){
            if (nums[j] > nums[j + 1]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = nums[i];
            }
        }
    }

    for (int i {0}; i < lenArr; i++){
        std::cout << nums[i] << " ";
    }
    printf("\n");

    return 0;
}