#include "ColaLigada.cpp"
#include "ColaLigada.h"
#include <iostream>
#include <ostream>

int main() {
  ColaLigada cajaC20;
  ColaLigada cajaC25;
  ColaLigada cajaD10;

  int opc;
  Turno retornoTurno;

  do {
    cout << "\n1. Ingresar turnos iniciales de las cajas C20 y C25.\n2. "
            "Transferir turnos a caja D10.\n3. Sacar 1 turno de caja D10\n4. "
            "Mostrar todas las cajas\n5. "
            "Salir\n> ";
    cin >> opc;

    Turno datoAInsertar;
    switch (opc) {
    case 1:
      // CAJA C20
      cout << "\nA continuación ingresarás los datos de la caja C20" << endl;
      do {
        cout << "\nEscribe el nombre del siguiente turno ej. RR15 (escribe -1 "
                "para terminar):\n> ";
        cin >> datoAInsertar.nombreTurno;
        cout << endl;
        if (datoAInsertar.nombreTurno == "-1")
          break;
        cajaC20.Insertar(datoAInsertar);
      } while (true);
      cout << "\tOK. Se insertó correctamente" << endl;

      // CAJA C25
      cout << "\nA continuación ingresarás los datos de la caja C25" << endl;
      do {
        cout << "\nEscribe el nombre del siguiente turno ej. RR15 (escribe -1 "
                "para terminar):\n> ";
        cin >> datoAInsertar.nombreTurno;
        cout << endl;
        if (datoAInsertar.nombreTurno == "-1")
          break;
        cajaC25.Insertar(datoAInsertar);
      } while (true);
      cout << "tOK. Se insertó correctamente" << endl;

      cout << "\n\tEstado actual de cajas:" << endl;
      cout << "\n\tCaja C20:" << endl;
      cajaC20.Mostrar();
      cout << "\n\tCaja C25:" << endl;
      cajaC25.Mostrar();

      break;
    case 2:

      bool c20vacio, c25vacio;
      c20vacio = c25vacio = false;
      do {
        retornoTurno = cajaC20.Extraer();
        if (retornoTurno.nombreTurno == "-1")
          c20vacio = true;
        else
          cajaD10.Insertar(retornoTurno);

        retornoTurno = cajaC25.Extraer();
        if (retornoTurno.nombreTurno == "-1")
          c25vacio = true;
        else
          cajaD10.Insertar(retornoTurno);

        if (c25vacio && c20vacio)
          break;
      } while (true);

      cout << "\n\tEstado final de cajas:" << endl;
      cout << "\n\tCaja C20:" << endl;
      cajaC20.Mostrar();
      cout << "\n\tCaja C25:" << endl;
      cajaC25.Mostrar();
      cout << "\n\tCaja D10:" << endl;
      cajaD10.Mostrar();
      break;
    case 3:
      retornoTurno = cajaD10.Extraer();
      if (retornoTurno.nombreTurno == "-1")
        cout << "\n\tCaja D10 vacía. NO SE EXTRAJO" << endl;
      else {
        cout << "\n\tOK. Se extrajo el turno:";
        mostrarTurno(retornoTurno);
        cout << endl << endl;
      }
      cajaD10.Mostrar();
      break;
    case 4:
      cout << "\n\tMOSTRAR CAJAS:" << endl;
      cout << "\n\tCaja C20:" << endl;
      cajaC20.Mostrar();
      cout << "\n\tCaja C25:" << endl;
      cajaC25.Mostrar();
      cout << "\n\tCaja D10:" << endl;
      cajaD10.Mostrar();
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
