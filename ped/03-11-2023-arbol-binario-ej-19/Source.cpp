#include "Binario.cpp"
#include <iostream>

int main() {
  Binario arbol;

  int opc;
  int datoAInsertar;

  do {
    cout << "1. Insertar\n"
         << "2. Salir\n"
         << ">";
    cin >> opc;
    cout << endl;

    switch (opc) {
    case 1: // INSERTAR
      cout << "\nEscribe el dato entero a insertar:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      arbol.CrearNodo(datoAInsertar);
      arbol.Insertar(arbol.ConsultarRaiz());
      cout << "\tOK. Se insertó correctamente" << endl;
      break;
    case 2: // FIN DE APLICACIÓN
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 2);

  return 0;
}
