// MAURO ROGELIO GALINDO IBARRA 

#include <iostream>
#include <ostream>

double obtenerDouble(const char textoAMostrar[]){
    int i;
    std::cout << textoAMostrar;
    std::cin >> i;
    std::cout << std::endl;
    return i;
}


int main(){
    int numTrabjadores = obtenerDouble("Ingrese el número de trabajadores a registrar: ");

    for (int i {0}; i < numTrabjadores; i++){
        std::cout << "\nIngrese el sueldo base del trabajador " << i + 1;
        double sueldoActual = obtenerDouble(": $");

        if (sueldoActual < 10'000){
            sueldoActual = sueldoActual * 1.2;

        } else if (10'000 <= sueldoActual && sueldoActual <= 15'000 ){
            sueldoActual = sueldoActual * 1.1;
            
        } else if (15'000 < sueldoActual && sueldoActual <= 20'000 ){
            sueldoActual = sueldoActual * 1.05;

        }     
        std::printf("El sueldo total del trabajador %d es: $%f\n", i + 1, sueldoActual);
    }
     
    return 0;
}

