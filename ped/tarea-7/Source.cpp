#include "ColaCircular.cpp"
#include "ColaCircular.h"
#include <iostream>
#define TAMCOLA 10

int main() {
  cout << "**COLA DE BOLETOS DE CONCIERTO**\n\n";

  ColaCircular miCola(TAMCOLA);
  miCola.Mostrar();

  int opc, retornoInt;
  int contadorExtraidos = 0;
  Comprador retornoComprador;

  do {
    cout << "\n1. Insertar 2. Consultar 3. Extraer 4. Salir\n> ";
    cin >> opc;

    Comprador datoAInsertar;
    switch (opc) {
    case 1:
      cout << "\nEscribe el nombre del siguiente comprador a insertar: ";
      cin >> datoAInsertar.nombre;

      cout << "Escribe el número de boletos que comprará: ";
      cin >> datoAInsertar.numeroBoletos;
      cout << endl;

      retornoInt = miCola.Insertar(datoAInsertar);
      if (retornoInt == -1) {
        cout << "\n\tCola llena. NO SE INSERTÓ" << endl;
      } else {
        cout << "\n\tOK. Se insertó correctamente" << endl << endl;
        ;
        miCola.Mostrar();
        cout << endl;
      }
      break;
    case 2:
      retornoComprador = miCola.Consultar();
      if (retornoComprador.numeroBoletos == -1)
        cout << "\n\tCola vacía. NO SE CONSULTÓ" << endl;
      else {
        cout << "\n\tOK. Se consultó el comprador: " << endl;
        mostrarComprador(retornoComprador);
      }
      break;
    case 3:
      retornoComprador = miCola.Extraer();
      if (retornoComprador.numeroBoletos == -1)
        cout << "\n\tCola vacía. NO SE EXTRAJO" << endl;
      else {
        contadorExtraidos += 1;
        cout << "\n\tOK. Se extrajo el comprador: " << endl;
        mostrarComprador(retornoComprador);
        if (contadorExtraidos == 5) {
          contadorExtraidos = 0;
          cout << "\n\n\t"
               << "----------------------------------------------------\n\t"
               << "Múltiplo de 5. ¡Es ganador de vale 50% de descuento!\n\t"
               << "----------------------------------------------------\n\n";
        }
      }
      cout << endl;
      miCola.Mostrar();
      cout << endl;
      break;
    case 4:
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 4);

  return 0;
}
