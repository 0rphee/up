#include "Arreglo.h"
#include <iostream>

Arreglo::Arreglo() {}

Arreglo::~Arreglo() {}

int Arreglo::Borrar(string nombreABorrar) {
  int posicion = -1;

  // localizar posición a borrar
  for (int i{0}; i < TAM; i++) {
    if (nombreABorrar == arr[i].nombre) {

      posicion = i;
      break;
    }
  }
  if (posicion == -1) {
    // no se encontró el valor a borrar
    // No se borró
    return -1;
  }

  arr[posicion] = {"", 0, 0};

  ocupados--;

  // se borró exitosamente
  return 0;
}

int Arreglo::Insertar(Empleado empleadoAInsertar) {

  int posicion = ocupados;

  // 1. verificar capacidad
  if (ocupados >= TAM) {
    return -2; // arreglo lleno, no se insertó
  }

  // 2. localizar posición de inserción
  for (int i{0}; i < ocupados; i++) {
    if (empleadoAInsertar.nombre == arr[i].nombre) {
      return -1; // ya existe, no se inserta
    }
    if (empleadoAInsertar.nombre < arr[i].nombre) {
      posicion = i;
      break;
    }
  }

  // 3. desplazar a la derecha
  for (int j{ocupados - 1}; j >= posicion; j--) {
    arr[j + 1] = arr[j];
  }

  // 4. insertar
  arr[posicion] = empleadoAInsertar;
  ocupados++;

  return 0;
}

void Arreglo::Ordenar() {
  for (int i = 0; i < TAM - 1; ++i) {
    for (int j = 0; j < TAM - i - 1; ++j) {
      if (arr[j].nombre > arr[j + 1].nombre) {
        // Intercambiar los elementos arr[j] y arr[j + 1]
        Empleado tempVar = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tempVar;
      }
    }
  }
}

void Arreglo::Mostrar() {
  cout << "Arreglo" << endl;
  for (int i{0}; i < TAM; i++) {
    cout << "\tNombre: " << arr[i].nombre
         << " Estatura (cm): " << arr[i].estaturaCm
         << " Sueldo semanal: " << arr[i].sueldoSemanal << endl;
  }
}
