#include "MatrizAdy.h"
#include <iostream>

// Construlr una aplicación que, en un Árbol Binario de Búsqueda de números
// enteros, busque un número dado y muestre in-orden el subárbol que tiene como
// raíz el nodo encontrado

int main() {

  int opc;
  int datoAInsertar;
  int maxNodo;
  char nombreNuevoNodo;
  char origen, destino; // insertar arcos
  int peso;             // insertar arco
  int codigoRetorno;

  cout << "\nCantidad máxima de nodos: ";
  cin >> maxNodo;
  MatrizAdy grafo(maxNodo);

  do {
    cout << "1. Insertar Nodo\n"
         << "2. Insertar Arco\n"
         << "3. Mostrar\n"
         << "4. Salir\n"
         << ">";
    cin >> opc;
    cout << endl;

    switch (opc) {
    case 1: // INSERTAR NODO
      cout << "\tNombre del nodo (una letra): ";
      cin >> nombreNuevoNodo;
      codigoRetorno = grafo.InsertarNodo(nombreNuevoNodo);

      if (codigoRetorno == 0)
        cout << "\tOK. Se insertó el nodo" << endl;
      else if (codigoRetorno == -1)
        cout << "\tArreglo lleno. NO se insertó el nodo" << endl;
      else if (codigoRetorno == -2)
        cout << "\tYA existe el nodo. NO se insertó" << endl;

      break;
    case 2: // INSERTAR ARCO
      cout << "\tNombre del origen (una letra): ";
      cin >> origen;
      cout << "\tNombre del destino (una letra): ";
      cin >> destino;
      cout << "\tPeso del arco: ";
      cin >> peso;

      codigoRetorno = grafo.InsertarArco(origen, destino, peso);
      if (codigoRetorno == 0)
        cout << "\tOK. Se insertó el arco bidireccional" << endl;
      else if (codigoRetorno == -1)
        cout << "\tGrafo vacío, NO existen nodos. NO se insertó el arco"
             << endl;
      else if (codigoRetorno == -2)
        cout << "\tNo existe nodo de origen o destino. NO se insertó el arco"
             << endl;
      else if (codigoRetorno == -3)
        cout << "\tYA eiste el arco. Se modificó el peso en dos direcciones"
             << endl;

      break;
    case 3: // MOSTRAR
      grafo.Mostrar();
      break;
    case 4: // FIN DE APLICACIÓN
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 4);

  return 0;
}
