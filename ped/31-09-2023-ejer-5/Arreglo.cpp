#include "Arreglo.h"
#include <cstdio>
#include <iostream>
#include <malloc/_malloc.h>

Arreglo::Arreglo() {
  cout << "\nRenglones: ";
  cin >> reng;

  cout << "\nColumnas: ";
  cin >> col;

  arr = new int *[reng];
  for (int c{0}; c < reng; c++) {
    arr[c] = new int[col];
  }
}

Arreglo::~Arreglo() {}

void Arreglo::LeerNombre() {
  cout << "\nNombre: ";
  cin.ignore();
  getline(cin, nom);
}

void Arreglo::Mostrar() {
  cout << '\n' << nom << " tu arreglo es:" << endl;
  for (int i = 0; i < reng; i++) {
    for (int j = 0; i < col; j++) {
      cout << '\t' << arr[i][j];
    }
    cout << endl;
  }
}

void Arreglo::Ordenar() {}

void Arreglo::Poblar() {}
