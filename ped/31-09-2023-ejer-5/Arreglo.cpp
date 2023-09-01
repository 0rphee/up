#include "Arreglo.h"
#include <cstdio>
#include <iostream>

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
    for (int j = 0; j < col; j++) {
      cout << '\t' << arr[i][j];
    }
    cout << endl;
  }
}

void Arreglo::Ordenar() {
  bool ordenado = false;
  int itera = 0;
  int aux;

  for (int i = 0; i < reng; i++) {
    ordenado = false;
    itera = 0;

    while (!ordenado) {
      ordenado = true;
      for (int j = 0; j < col - 1 - itera; j++) {
        if (arr[i][j] > arr[i][j + 1]) {
          aux = arr[i][j];
          arr[i][j] = arr[i][j + 1];
          arr[i][j + 1] = aux;
          ordenado = false;
        }
      }
      itera++;
    }
  }
}

void Arreglo::Poblar() {
  for (int i = 0; i < reng; i++) {
    cout << "\nRenglon " << i << ": " << endl;
    for (int j = 0; j < col; j++) {
      cout << "\tcolumna " << j << ": ";
      cin >> arr[i][j];
      cout << endl;
    }
  }
}
