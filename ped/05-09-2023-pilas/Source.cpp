#include "Arreglo.cpp"
#include <iostream>

int main() {
  Pila miPila(10);
  miPila.Mostrar();

  int opc, retorno;

  do {
    cout << "\n1. Insertar 2. Extraeer 3. Consultar 4. Mostrar 5. Salir ";
    cin >> opc;

    switch (opc) {
    case 1:
      int valAInsertar;
      cout << "\nEscribe el valor a insertar";
      cin >> valAInsertar;
      miPila.Insertar(valAInsertar);
      if (retorno == -1) {
        cout << "\n\tPila llena. NO SE INSERTÓ" << endl;
      } else {
        cout << "\n\tOK. Se insertó correctamente" << endl;
      }
      break;
    case 2:
      retorno = miPila.Extraer();
      if (retorno == -1) {
        cout << "\n\tPila vacía. NO SE EXTRAJO" << endl;
      } else {
        cout << "\n\tOK. Se extrajo el entero: " << retorno << endl;
      }
      break;
    case 3:
      retorno = miPila.Consultar();
      if (retorno == -1) {
        cout << "\n\tPila vacía. NO SE CONSULTÓ" << endl;
      } else {
        cout << "\n\tOK. Se consultó el entero: " << retorno << endl;
      }
      break;
    case 4:
      miPila.Mostrar();
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
