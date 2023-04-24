#include <iostream>

typedef struct{
    std::string nombre;
    std::string coordenadas;
    int numMunicipios;
    std::string capital;
    std::string fechaFundacion;
    
} Estado;

typedef struct {
    std::string nombre;
    std::string capital;
    int numEstados;
    Estado* estados;
} Pais;

Estado leerEstado(){
    Estado estado;
    std::cout << "Ingrese el Nombre: "; std::cin >> estado.nombre; // std::cout << // std::endl;
    std::cout << "Ingrese las Coordenadas: "; std::cin >> estado.coordenadas; // std::cout << // std::endl;
    std::cout << "Ingrese el Número de municipios: "; std::cin >> estado.numMunicipios; // std::cout << // std::endl;
    std::cout << "Ingrese la Capital: "; std::cin >> estado.capital; // std::cout << // std::endl;
    std::cout << "Ingrese la Fecha de fundación: "; std::cin >> estado.fechaFundacion; // std::cout << // std::endl;
    return estado;
}

Pais leerPais (){
    Pais pais;
    int nEstados;
    std::cout << "Ingrese el Nombre: "; std::cin >> pais.nombre; // std::cout << std::endl;
    std::cout << "Ingrese la Capital: "; std::cin >> pais.capital; // std::cout << // std::endl;
    std::cout << "Ingrese el Número de Estados: "; std::cin >> pais.numEstados; // std::cout << // std::endl;
    std::cout << "Ingrese los Estados: " << std::endl;

    pais.estados = new Estado[pais.numEstados];
    
    for (int i {0}; i < pais.numEstados; i++){
        std::cout << "\n------------\n";
        std::cout << "Estado " << i+1 << std::endl;
        pais.estados[i] = leerEstado();
        std::cout << "------------\n";
    }
    return pais;
}

void printEstado(Estado estado){
    std::cout << "Nombre: "<< estado.nombre << std::endl;
    std::cout << "Coordenadas: "<< estado.coordenadas << std::endl;
    std::cout << "Número de municipios: "<< estado.numMunicipios << std::endl;
    std::cout << "Capital: "<< estado.capital << std::endl;
    std::cout << "Fecha de fundación: "<< estado.fechaFundacion << std::endl;
}
void printPais(Pais pais){
    std::cout << "Nombre: "<< pais.nombre << std::endl;
    std::cout << "Capital: "<< pais.capital << std::endl;
    std::cout << "Cantidad de Estados: "<< pais.numEstados << std::endl;
    std::cout << "Estados: " << std::endl;

    for (int i {0}; i < pais.numEstados; i++){
        std::cout << "\n------------\n";
        std::cout << "Estado " << i+1 << std::endl;
        printEstado(pais.estados[i]);
        std::cout << "------------\n";
    }
}
