#include "Arreglo.h"
#include <cstdio>
#include <iostream>

Pila::~Pila() {}

Pila::Pila(int tam) {
  pilaEnteros = new int[tam];
  min = 0;
  max = tam - 1;
  tope = -1;

  for (int i = 0; i <= max; i++) {
    pilaEnteros[i] = 0;
  }
}

int Pila::Consultar() {}

int Pila::Insertar(int nuevoInt) {}

int Pila::Extraer() {}

void Pila::Mostrar() {
  cout << "Arreglo: " << endl;

  for (int i = max; i >= 0; i--) {
    cout << "\t" << pilaEnteros[i];
    if (i == min) {
      cout << "\t<= Mínimo";
    }
    if (i == max) {
      cout << "\t<=Máximo";
    }
    if (i == tope) {
      cout << "\t<= Tope";
    }
    cout << endl;
  }
}
