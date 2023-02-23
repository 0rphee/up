#include <iostream>


int enterNum(const char textoParaMostrar[]){
    printf("%s\n", textoParaMostrar);

    int temp;

    std::cin >> temp;

    return temp;
 }

int main(int args, const char* argv[]){

    int num = enterNum("Ingrese el número de números a ingresar");

    printf("A continuacón se leerá cada número\n");

    int maximo;

    int i = 0;

    do {
        int temp = enterNum("Ingrese el siguiente número");
        if (i == 0){
            maximo = temp;

        } else if (temp > maximo){
            maximo = temp;
        }
        i++;
    } while (i < num);


    printf("El número más alto es %d\n", maximo);

       

    return 0;
}

