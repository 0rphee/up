// demostración de herencia de clases con Animal->Perro, Animal->Pez, Animal->Rana

#include <iostream>
#include "Animal_0250061.h"
#include "Rana_0250061.h"
#include "Pez_0250061.h"
#include "Perro_0250061.h"

int main(){
    // Creación de objetos
    Perro perro(4, 2, "GWAUWWWW", "mamifero", "cafe", "labrador");
    Pez pez(0, 2, "glooo", "pez", "azul", true, 2);
    Rana rana(4, 2, "croook", "anfibio", "verde", true);
    // Llamada a métodos de las clases derivadas
    perro.correr();
    pez.nadar();
    rana.saltar();
    perro.sonido();
    pez.sonido();
    rana.sonido();

    // Llamada a métodos de la clase base
    perro.setPatas(3);
    perro.setOjos(2);
    perro.setSonido("wooof");
}
