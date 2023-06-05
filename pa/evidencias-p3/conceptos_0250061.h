#include <iostream>

class Conceptos {
    protected:
        int datoProtegido {0};
    private:
        int dato {0};
    public: 
        int datoPublico {0};
        Conceptos(); // Constructor
        Conceptos(int dato); // Constructor con parámetro

        Conceptos(Conceptos &copia); // Constructor copia
        int leerDato();
        void escribirDato(int dato);
        ~Conceptos(); // Destructor
};

Conceptos::Conceptos(){
    this->dato = 0; // this->_ = self._
}

Conceptos::Conceptos(int dato){
    this->dato = dato;
}

Conceptos::Conceptos(Conceptos &copia){
    this->dato = copia.dato;
}

Conceptos::~Conceptos(){
    std::cout << "Instancia elminada" << std::endl;
}

int Conceptos::leerDato() { // get
    return this->dato;
}

void Conceptos::escribirDato(int dato) { // get
    this->dato = dato;
}
