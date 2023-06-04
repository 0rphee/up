#include <cstdio>
#include <iostream>

#include "Vehiculo.h"

std::string getString(std::string msg){
    std::cout << msg;
    std::string val;
    std::cin >> val;
    printf("\n\n");
    return val;
}


int main(){
    db::Vehiculo vehiculo;

    unsigned char llantas;
    bool status;
    std::string color;
    std::string marca;
    std::string placas;
    float combustible;
    char marcha;
    std::string tipo;

    printf("Ingrese el número de llantas del vehículo: ");
    std::cin >> llantas;
    printf("\n\n");

    printf("Ingrese el status del vehículo (bueno/malo): ");
    std::string temp;
    std::cin >> temp;
    if (temp == "bueno") { status = true; }
    else { status = false; }
    printf("\n\n");

    color = getString("Ingrese el color del vehículo: ");

    marca = getString("Ingrese la marca del vehículo: ");

    placas = getString("Ingrese el número de placas del vehículo: ");

    printf("Ingrese la cantidad de combustible en litros del vehículo: ");
    std::cin >> combustible;
    printf("\n\n");

    printf("Ingrese la marcha actual vehículo: ");
    std::cin >> marcha;
    printf("\n\n");

    tipo = getString("Ingrese el tipo de vehículo: ");

    vehiculo.setLlantas(llantas);
    vehiculo.setStatus(status);
    vehiculo.setColor(color);
    vehiculo.setMarca(marca);
    vehiculo.setPlacas(placas);
    vehiculo.setCombustible(combustible);
    vehiculo.setMarcha(marcha);

    std::cout << "Llantas: "<< static_cast<int>(vehiculo.getLlantas()) << std::endl;
    std::cout << "Status: "<< vehiculo.getStatus() << std::endl;
    std::cout << "Color: "<< vehiculo.getColor() << std::endl;
    std::cout << "Marca: "<< vehiculo.getMarca() << std::endl;
    std::cout << "Placas: "<< vehiculo.getPlacas() << std::endl;
    std::cout << "Combustible: "<< vehiculo.getCombustible() << std::endl;
    std::cout << "Marcha: "<< vehiculo.getMarcha() << std::endl;

    return 0;
}






