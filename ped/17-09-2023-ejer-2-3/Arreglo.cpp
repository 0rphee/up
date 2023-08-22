#include "Arreglo.h"
#include <iostream>

Arreglo::Arreglo() {}

Arreglo::~Arreglo() {}

int Arreglo::Borrar(int numABorrar) {
  int posicion = -1;

  // localizar posición a borrar
  for (int i{0}; i < ocupados; i++) {
    if (numABorrar == enteros[i]) {
      posicion = i;
      break;
    }
  }
  if (posicion == -1) {
    // no se encontró el valor a borrar
    // No se borró
    return -1;
  }

  for (int i{posicion}; i < (ocupados - 1); i++) {
    enteros[i] = enteros[i + 1];
  }
  enteros[ocupados - 1] = 0;
  ocupados--;

  // se borró exitosamente
  return 0;
}

int Arreglo::Insertar(int n) {

  int posicion = ocupados;

  // 1. verificar capacidad
  if (ocupados >= TAM) {
    return -2; // arreglo lleno, no se insertó
  }

  // 2. localizar posición de inserción
  for (int i{0}; i < ocupados; i++) {
    if (n == enteros[i]) {
      return -1; // ya existe, no se inserta
    }
    if (n < enteros[i]) {
      posicion = i;
      break;
    }
  }

  // 3. desplazar a la derecha
  for (int j{ocupados - 1}; j >= posicion; j--) {
    enteros[j + 1] = enteros[j];
  }

  // 4. insertar
  enteros[posicion] = n;
  ocupados++;

  return 0;
}

void Arreglo::Mostrar() {
  cout << "Arreglo" << endl;
  for (int i{0}; i < TAM; i++) {
    cout << "\t" << enteros[i] << endl;
  }
}
