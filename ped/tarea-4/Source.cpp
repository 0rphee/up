#include "Arreglo.cpp"
#include <iostream>

int main() {
  Pila pila1;
  Pila pila2;

  cout << "Pila 1:" << endl;
  pila1.Mostrar();
  cout << "Pila 2:" << endl;
  pila2.Mostrar();

  int opc, retornoOperacion;

  do {
    cout << "\n1. Insertar 2. Extraer 3. Consultar 4. Mostrar 5. Depurar 6. "
            "Salir"
         << endl;
    cin >> opc;

    int intAInsertar;
    switch (opc) {
    case 1:
      cout << "\nEscribe el entero a insertar: ";
      cin >> intAInsertar;
      retornoOperacion = pila1.Insertar(intAInsertar);
      if (retornoOperacion == -1) {
        cout << "\n\tPila llena. NO SE INSERTÓ" << endl;
      } else {
        cout << "\n\tOK. Se insertó correctamente" << endl;
      }
      break;
    case 2:
      retornoOperacion = pila1.Extraer();
      if (retornoOperacion == -1) {
        cout << "\n\tPila vacía. NO SE EXTRAJO" << endl;
      } else {
        cout << "\n\tOK. Se extrajo el entero: " << retornoOperacion << endl;
      }
      break;
    case 3:
      retornoOperacion = pila1.Consultar();
      if (retornoOperacion == -1) {
        cout << "\n\tPila vacía. NO SE CONSULTÓ" << endl;
      } else {
        cout << "\n\tOK. Se consultó el entero: " << retornoOperacion << endl;
      }
      break;
    case 4:
      cout << "Pila 1:" << endl;
      pila1.Mostrar();
      cout << "Pila 2:" << endl;
      pila2.Mostrar();
      break;
    case 5:
      int enteroDepurar;
      cout << "\nIngrese un entero menor para depurar: ";
      cin >> enteroDepurar;
      cout << endl;

      do {
        retornoOperacion = pila1.Extraer();
        if (retornoOperacion == -1) {
          break;
        }
        // los enteros que son mayores al entero 'menor' si se traspasan a la
        // otra pila
        if (retornoOperacion > enteroDepurar) {
          pila2.Insertar(retornoOperacion);
        }

      } while (true);

      break;
    case 6:
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 6);

  return 0;
}
