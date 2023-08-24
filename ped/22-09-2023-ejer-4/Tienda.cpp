#include "Tienda.h"
#include <iostream>

Tienda::Tienda() { ocupados = 0; }

Tienda::~Tienda() {}

void Tienda::Mostrar() {
  cout << endl << "SUCURSALES " << endl;
  for (int i{0}; i < ocupados; i++) {
    cout << '\t' << sucs[i].numSuc << '\t' << sucs[i].nomGte << '\t'
         << sucs[i].ventas[0] << '\t' << sucs[i].ventas[1] << endl;
  }
  cout << endl;
}
void Tienda::Ordenar() {
  bool ordenado = false;
  Sucursal aux;
  int nItera = 0;

  while (!ordenado) {
    ordenado = true; // false = desordenado
    for (int i = 0; i < ocupados - 1 - nItera; i++) {
      if (sucs[i].numSuc > sucs[i + 1].numSuc) {
        aux = sucs[i];
        sucs[i] = sucs[i + 1];
        sucs[i + 1] = aux;
        ordenado = false;
      }
    }
    nItera++;
  }
}
bool Tienda::Poblar() {
  int numS;
  if (ocupados >= TAM) {
    return false; // el arreglo está lleno
  }

  do {
    cout << "\nNúmero de de sucursal (999 para terminar):";
    cin >> numS;
    if (numS != 999) {
      cin.ignore();
      sucs[ocupados].numSuc = numS;
      cout << "Nombre del gerente: ";
      getline(cin, sucs[ocupados].nomGte);

      cout << "Ventas de este mes: ";
      cin >> sucs[ocupados].ventas[0];

      cout << "Ventas del mes anterior: ";
      cin >> sucs[ocupados].ventas[1];

      ocupados++;
    }

  } while (numS != 999);

  return false;
}
