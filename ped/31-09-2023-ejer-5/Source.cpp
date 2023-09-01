#include "Arreglo.cpp"
#include <iostream>

int main() {
  Arreglo arreglo;

  int opc;

  do {
    cout << "\n1. Nombre 2. Poblar 3. Ordenar 4. Mostrar 5. Salir ";
    cin >> opc;

    switch (opc) {
    case 1:
      arreglo.LeerNombre();
      break;
    case 2:
      arreglo.Poblar();
      break;
    case 3:
      arreglo.Ordenar();
      break;
    case 4:
      arreglo.Mostrar();
      break;
    case 5:
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 5);

  return 0;
}
