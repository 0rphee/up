#include "ColaLigada.cpp"
#include <iostream>

int main() {
  ColaLigada miCola;
  miCola.Mostrar();

  int opc;
  string retornoStr;

  do {
    cout << "\n1. Insertar 2. Consultar 3. Extraer 4. Mostrar 5. Salir\n> ";
    cin >> opc;

    string datoAInsertar;
    switch (opc) {
    case 1:
      cout << "\nEscribe la siguiente frase a insertar: ";
      cin >> datoAInsertar;
      cout << endl;
      miCola.Insertar(datoAInsertar);
      cout << "\n\tOK. Se insertó correctamente" << endl;
      break;
    case 2:
      retornoStr = miCola.Consultar();
      if (retornoStr == "-1")
        cout << "\n\tCola vacía. NO SE CONSULTÓ" << endl;
      else
        cout << "\n\tOK. Se consultó la palabra: " << retornoStr << endl;
      break;
    case 3:
      retornoStr = miCola.Extraer();
      if (retornoStr == "-1")
        cout << "\n\tCola vacía. NO SE EXTRAJO" << endl;
      else
        cout << "\n\tOK. Se extrajo la palabra: " << retornoStr << endl;

      break;
    case 4:
      miCola.Mostrar();
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
