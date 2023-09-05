#include "Arreglo.cpp"
#include <iostream>

int main() {
  Pila miPila(10);
  miPila.Mostrar();

  // int opc;

  // do {
  //   cout << "\n1. Nombre 2. Poblar 3. Ordenar 4. Mostrar 5. Salir ";
  //   cin >> opc;

  //   switch (opc) {
  //   case 1:
  //     miPila.LeerNombre();
  //     break;
  //   case 2:
  //     miPila.Poblar();
  //     break;
  //   case 3:
  //     miPila.Ordenar();
  //     break;
  //   case 4:
  //     miPila.Mostrar();
  //     break;
  //   case 5:
  //     cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
  //     break;

  //   default:
  //     cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
  //     break;
  //   }
  // } while (opc != 5);

  return 0;
}
