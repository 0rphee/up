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
void Tienda::Ordenar() {}
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
    }

  } while (numS != 999);

  return false;
}
