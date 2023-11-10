#include "Binario.cpp"
#include <iostream>

int main() {
  Binario arbol;

  int opc;
  int datoAInsertar;

  do {
    cout << "1. Insertar\n"
         << "2. Recorrer In-orden\n"
         << "3. Recorrer Pre-orden\n"
         << "4. Recorrer Pos-orden\n"
         << "5. Salir\n"
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
    case 2: // INORDEN
      if (arbol.ConsultarRaiz() == NULL)
        cout << "\n\t\t\t ARBOL VACÍO, NO SE RECORRIÓ" << endl;
      else {
        arbol.RecorrerINorden(arbol.ConsultarRaiz());
      }
      break;
    case 3: // PREORDEN
      if (arbol.ConsultarRaiz() == NULL)
        cout << "\n\t\t\t ARBOL VACÍO, NO SE RECORRIÓ" << endl;
      else {
        arbol.RecorrerPREorden(arbol.ConsultarRaiz());
      }
      break;
    case 4: // POSORDEN
      if (arbol.ConsultarRaiz() == NULL)
        cout << "\n\t\t\t ARBOL VACÍO, NO SE RECORRIÓ" << endl;
      else {
        arbol.RecorrerPOSorden(arbol.ConsultarRaiz());
      }
      break;
    case 5: // FIN DE APLICACIÓN
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 5);

  return 0;
}
