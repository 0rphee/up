#include "Arreglo.cpp"
#include <iostream>

int main() {
  Fabrica arreglo;
  int opcion;

  do {
    cout << "1. Poblar 2. Ordenar 3. Mostrar 4. Salir" << endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
      arreglo.Poblar();
      break;
    case 2:
      arreglo.Ordenar();
      break;
    case 3:
      arreglo.Mostrar();
      break;
    case 4:
      // salir
      cout << "FINAL DE LA APLICACIÓN" << endl;
      break;
    default:
      cout << "Opción INVÁLIDA" << endl;
      break;
    }
  } while (opcion != 4);

  return 0;
}
