#include "Arreglo.cpp"
#include <iostream>

int main() {
  Arreglo arreglo;

  int inputInt, codigoDeOperacion, opcion;

  do {
    arreglo.Mostrar();

    cout << "1. Borrar 2. Insertar 3. Salir" << endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
      cout << "Que entero borrarás?" << endl;
      cin >> inputInt;

      codigoDeOperacion = arreglo.Borrar(inputInt);

      if (codigoDeOperacion == -1) {
        cout << "\n\tNo se encontró el número. NO se borró" << endl;
      } else if (codigoDeOperacion == 0) {

        cout << "\n\tOK. se borró correctamente" << endl;
      }
      // borrar
      break;
    case 2:
      // insertar
      cout << "Qué número a insertar?" << endl;
      cin >> inputInt;

      codigoDeOperacion = arreglo.Insertar(inputInt);
      switch (codigoDeOperacion) {
      case -2:
        cout << "\n\tERROR, arreglo lleno, no hubo inserción" << endl;
        break;
      case -1:
        cout << "\n\tERROR, el número ya existe en el arreglo, NO se insertó"
             << endl;
        break;
      case 0:
        cout << "\n\tOK, el número se insertó correctamente" << endl;
        break;
      }
      break;
    case 3:
      // salir
      cout << "FINAL DE LA APLICACIÓN" << endl;
      break;
    default:
      cout << "Opción INVÁLIDA" << endl;
      break;
    }

  } while (opcion != 3);

  return 0;
}
