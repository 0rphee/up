#include "ColaLigada.cpp"
#include "ColaLigada.h"
#include <iostream>
#include <ostream>

int main() {
  ColaLigada miCola;
  miCola.Mostrar();

  int opc;
  Trailer retornoTrailer;

  do {
    cout << "\n1. Registrar llegada de trailer\n2. Consultar siguiente trailer "
            "a descargar\n3. Sacar de fila trailer que descargó\n4. Mostrar "
            "fila\n5. Salir\n> ";
    cin >> opc;

    Trailer datoAInsertar;
    switch (opc) {
    case 1:
      cout << "\nEscribe las placas del trailer a insertar: ";
      cin >> datoAInsertar.placas;
      cout << "\nEscribe el producto del trailer a insertar: ";
      cin >> datoAInsertar.producto;
      cout << endl;

      miCola.Insertar(datoAInsertar);
      cout << "\n\tOK. Se insertó correctamente" << endl;
      break;
    case 2:
      retornoTrailer = miCola.Consultar();
      if (retornoTrailer.placas == "-1")
        cout << "\n\tCola vacía. NO SE CONSULTÓ" << endl;
      else {
        cout << "\n\tOK. El próximo trailer a descargar es:" << endl;
        mostrarTrailer(retornoTrailer);
        cout << endl;
      }
      break;
    case 3:
      retornoTrailer = miCola.Extraer();
      if (retornoTrailer.placas == "-1")
        cout << "\n\tCola vacía. NO SE EXTRAJO" << endl;
      else {
        cout << "\n\tOK. Se descargó el trailer:" << endl;
        mostrarTrailer(retornoTrailer);
        cout << endl;
      }

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
