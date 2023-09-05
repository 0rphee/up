#include "Arreglo.h"
#include <iostream>

Fabrica::Fabrica() {}

Fabrica::~Fabrica() {}

int Fabrica::Poblar() {

  cout << "Ingrese el número de empleados: ";
  cin >> this->numEmpleados;

  // Crear un arreglo de punteros a registros de empleados
  this->arr = new Empleado[numEmpleados];

  // Inicializar los registros de empleados
  for (int i = 0; i < numEmpleados; i++) {
    cout << "Empleado numero " << i + 1 << endl;
    cout << "Nombre de empleado a insertar? ";
    cin >> arr[i].nombre;

    cout << endl << "Que antiguedad tiene (en años)? ";
    cin >> arr[i].antiguedad;

    cout << endl << "Cuantas piezas fabricó en el mes 1? ";
    cin >> arr[i].piezas_mes1;

    cout << endl << "Cuantas piezas fabricó en el mes 2? ";
    cin >> arr[i].piezas_mes2;

    cout << endl << "Cuantas piezas fabricó en el mes 3? ";
    cin >> arr[i].piezas_mes3;
    cout << endl;
  }
  return 0;
}

void Fabrica::Ordenar() {
  for (int i = 0; i < numEmpleados - 1; ++i) {
    for (int j = 0; j < numEmpleados - i - 1; ++j) {
      if (arr[j].antiguedad > arr[j + 1].antiguedad) {
        // Intercambiar los elementos arr[j] y arr[j + 1]
        Empleado tempVar = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tempVar;
      }
    }
  }
}

void Fabrica::Mostrar() {
  cout << "Arreglo (num. empleados " << numEmpleados << ')' << endl;
  for (int i{0}; i < numEmpleados; i++) {
    cout << "Empleado N: " << i + 1 << endl;
    cout << "\tNombre: " << arr[i].nombre
         << "\n\tAntiguedad (años): " << arr[i].antiguedad
         << "\n\tPiezas fabricadas mes 1: " << arr[i].piezas_mes1
         << "\n\tPiezas fabricadas mes 2: " << arr[i].piezas_mes2
         << "\n\tPiezas fabricadas mes 3: " << arr[i].piezas_mes3 << endl;
  }
}
