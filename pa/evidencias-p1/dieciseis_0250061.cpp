// ejemplo de una función parámetros y valores de retorno

#include <iostream>

int suma(int numeroUno, int numeroDos);
int suma(int numeroUno, int numeroDos) {
    return numeroUno + numeroDos;
}

int main(){
    std::cout << "la suma 5 + 10 es: " << suma(5, 10) << "\n"; 
    return 0;
}




