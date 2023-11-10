#include "Binario.cpp"
#include <iostream>

// Construlr una aplicación que, en un Árbol Binario de Búsqueda de números
// enteros, busque un número dado y muestre in-orden el subárbol que tiene como
// raíz el nodo encontrado

int main() {
  Binario arbol;

  int opc;
  int datoAInsertar;
  Nodo *subArbolEncontrado;

  do {
    cout << "1. Insertar\n"
         << "2. Recorrer In-orden\n"
         << "3. Recorrer Pre-orden\n"
         << "4. Recorrer Pos-orden\n"
         << "5. Buscar\n"
         << "6. Salir\n"
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
    case 5: // buscar
      cout << "\nEscribe el dato entero a buscar en el árbol:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      subArbolEncontrado = arbol.Buscar(arbol.ConsultarRaiz(), datoAInsertar);
      if (subArbolEncontrado != NULL) {
        cout << "Se encontró el dato: " << datoAInsertar << endl;
        cout << "Recorrido IN-orden de sub-arbol" << endl << endl;
        arbol.RecorrerINorden(subArbolEncontrado);
      } else {
        cout << "No se encontró el dato: " << datoAInsertar << endl;
      }

      break;
    case 6: // FIN DE APLICACIÓN
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 6);

  return 0;
}
