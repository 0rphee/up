#include "App.h"
#include <clocale>
#include <iostream>

App::App() {}

App::~App() {}

void App::Tarea1() {
  cout << "Ingresar números enteros hasta recibir un cero" << endl;
  int suma{0};
  int count{0};
  while (true) {
    int temp;
    cin >> temp;
    if (temp == 0) {
      break;
    }
    count += 1;
    suma += temp;
  }
  cout << "La cantidad total de números ingresados fue: " << count
       << " sumando un total de: " << suma << endl;
}

void App::Tarea2() {
  cout << "Ingresar 9 números enteros" << endl;
  int cuentaPares{0};
  int sumaPares{0};

  int cuentaImpares{0};
  int sumaImpares{0};

  for (int i{0}; i < 9; i++) {
    int temp;
    cin >> temp;
    if (temp % 2 == 0) {
      // es par

      printf("aaa\n");
      cuentaPares += 1;
      sumaPares += temp;
    } else {

      cuentaImpares += 1;
      sumaImpares += temp;
    }
  }
  cout << "La cantidad total de números pares fue: " << cuentaPares
       << " sumando un total de: " << sumaPares << endl;

  cout << "La cantidad total de números impares fue: " << cuentaImpares
       << " sumando un total de: " << sumaImpares << endl;
}
