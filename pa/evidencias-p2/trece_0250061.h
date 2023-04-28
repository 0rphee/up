#include <iostream>
#include <bitset>
#include <ostream>
#include <string>

// Introducción a uniones 

namespace trece{
    union Datos {
        int numeroUno;
        int numeroDos;
    };
    int main(){
        Datos datos;
        datos.numeroUno = 10;
        std::cout << "numero guardado: " << datos.numeroDos << std::endl;
        return 0;
    }



}


