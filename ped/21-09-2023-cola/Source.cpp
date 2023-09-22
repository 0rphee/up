#include "Cola.cpp"
#include <iostream>

int main() {
  Cola miCola;
  miCola.Mostrar();

  int opc, retornoInt;
  string retornoStr;

  do {
    cout << "\n1. Insertar 2. Extraer 3. Mostrar 5. Salir\n> ";
    cin >> opc;
    string datoAInsertar;
    switch (opc) {
    case 1:
      cout << "\nEscribe la siguiente palabra a insertar: ";
      cin >> datoAInsertar;
      cout << endl;
      retornoInt = miCola.Insertar(datoAInsertar);
      if (retornoInt == -1) {
        cout << "\n\tCola llena. NO SE INSERTÓ" << endl;
      } else {
        cout << "\n\tOK. Se insertó correctamente" << endl;
      }
      break;
    case 2:
      retornoStr = miCola.Extraer();
      if (retornoStr == "-1") {
        cout << "\n\tCola vacía. NO SE EXTRAJO" << endl;
      } else {
        cout << "\n\tOK. Se extrajo la palabra: " << retornoStr << endl;
      }
      break;
    case 3:
      miCola.Mostrar();
      break;
    case 4:
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 5);

  return 0;
}
