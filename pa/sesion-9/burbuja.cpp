
#include <iostream>
#include <ostream>

int enterNum(const char textoParaMostrar[]){
    printf("%s\n", textoParaMostrar);

    int temp;

    std::cin >> temp;

    return temp;
 }

void burbuja(int arr[], int lenArr){
    for (int i {0}; i < lenArr - 1; i++){
        for (int j {0}; j < lenArr - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = arr[i];
            }
        }
    }
}

int main(){

    int lenArr = enterNum("Ingrese la cantidad de número a ingresar y ordenar");

    int nums[lenArr];

    for (int i {0}; i < lenArr; i++ ){
        nums[i] = enterNum("Ingrese el siguiente número");
    }

    burbuja(nums, lenArr);

    for (int i {0}; i < lenArr; i++){
        std::cout << nums[i] << " ";
    }
    printf("\n");

    return 0;
}