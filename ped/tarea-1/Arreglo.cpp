#include "Arreglo.h"
#include <iostream>

Arreglo::Arreglo() {}

Arreglo::~Arreglo() {}

void Arreglo::OrdenarEnteros() {
  for (int i = 0; i < TAM - 1; ++i) {
    for (int j = 0; j < TAM - i - 1; ++j) {
      if (enteros[j] > enteros[j + 1]) {
        // Intercambiar los elementos enteros[j] y enteros[j + 1]
        int tempVar = enteros[j];
        enteros[j] = enteros[j + 1];
        enteros[j + 1] = tempVar;
      }
    }
  }
}

void Arreglo::MostrarEnteros() {
  cout << "Arreglo" << endl;
  for (int i{0}; i < TAM; i++) {
    cout << "\t" << enteros[i] << endl;
  }
}

void Arreglo::OrdenarStrings() {
  for (int i = 0; i < TAM - 1; ++i) {
    for (int j = 0; j < TAM - i - 1; ++j) {
      if (arrStrings[j] > arrStrings[j + 1]) {
        // Intercambiar los elementos arrStrings[j] y arrStrings,[j + 1]
        std::string temp = arrStrings[j];
        arrStrings[j] = arrStrings[j + 1];
        arrStrings[j + 1] = temp;
      }
    }
  }
}

void Arreglo::MostrarStrings() {
  cout << "Arreglo" << endl;
  for (int i{0}; i < TAM; i++) {
    cout << "\t" << arrStrings[i] << endl;
  }
}
