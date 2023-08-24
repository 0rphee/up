#include "Arreglo.cpp"
#include <iostream>

int main() {
  Arreglo arreglo;
  cout << "\t\tArreglo enteros original\n\n";

  arreglo.Mostrar();

  arreglo.Ordenar();

  cout << "\n\t\tArreglo ordenado\n\n" << endl;
  arreglo.Mostrar();

  string inputNombre;
  int codigoDeOperacion, opcion;

  do {
    cout << "1. Borrar 2. Insertar 3. Salir" << endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
      cout << "Que empleado borrarás? (ingresa nombre) ";
      cin >> inputNombre;
      cout << endl;

      codigoDeOperacion = arreglo.Borrar(inputNombre);

      if (codigoDeOperacion == -1) {
        cout << "\n\tNo se encontró el empleado. NO se borró" << endl;
      } else if (codigoDeOperacion == 0) {

        cout << "\n\tOK. se borró correctamente" << endl;
        arreglo.Ordenar();
        arreglo.Mostrar();
      }
      // borrar
      break;
    case 2:
      // insertar
      int inputEstatura;
      double inputSueldo;
      cout << "Qué nombre a insertar? ";
      cin >> inputNombre;

      cout << endl << "Qué estatura tiene (en cm)? ";
      cin >> inputEstatura;

      cout << endl << "Qué sueldo semanal tiene? ";
      cin >> inputSueldo;
      cout << endl;

      codigoDeOperacion =
          arreglo.Insertar({inputNombre, inputEstatura, inputSueldo});
      switch (codigoDeOperacion) {
      case -2:
        cout << "\n\tERROR, arreglo lleno, no hubo inserción" << endl;
        break;
      case -1:
        cout << "\n\tERROR, el nombre ya existe en el arreglo, NO se insertó"
             << endl;
        break;
      case 0:
        cout << "\n\tOK, el empleado se insertó correctamente" << endl;
        arreglo.Ordenar();
        arreglo.Mostrar();
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