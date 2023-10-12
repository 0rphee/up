#include "ListaLigada.cpp"
#include <iostream>

int main() {
  ListaLigada lista;

  int opc;
  int retornoInsertar;
  string retornoExtraer;

  do {
    cout << "\n1. Ingresar dato al incio.\n2. "
            "Ingresar dato después de un valor.\n3. Ingresar dato al final\n4. "
            "Mostrar lista\n5. Extraer Inicio\n6. Extraer Intermedio\n7. "
            "Extraer Final\n8. Salir\n> ";
    cin >> opc;

    string datoAInsertar;
    string datoMatch;
    switch (opc) {
    case 1: // INSERTAR INICIO
      cout << "\nEscribe la palabra a insertar:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      lista.InsertarInicio(datoAInsertar);
      cout << "\tOK. Se insertó correctamente" << endl;
      break;
    case 2: // INSERTAR INTERMEDIO

      cout << "\nEscribe la palabra a insertar:\n> ";
      cin >> datoAInsertar;
      cout << endl;

      cout << "\nEscribe la palabra tras la que se insertará el valor:\n> ";
      cin >> datoMatch;
      cout << endl;
      retornoInsertar = lista.InsertarInter(datoMatch, datoAInsertar);
      if (retornoInsertar == 0)
        cout << "\tOK. Se insertó después de la palabra correctamente" << endl;
      else if (retornoInsertar == -1)
        cout << "\tOK. Se insertó al inicio correctamente" << endl;
      else if (retornoInsertar == -2)
        cout << "\tOK . No se encontró, se insertó al final" << endl;
      break;
    case 3: // INSERTAR FINAL
      cout << "\nEscribe la palabra a insertar:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      retornoInsertar = lista.InsertarFinal(datoAInsertar);

      if (retornoInsertar == 0)
        cout << "\tOK. Se insertó correctamente" << endl;
      else
        cout << "\tOk. Se insertó al inicio, estaba vacía" << endl;
      break;
    case 4: // MOSTRAR
      lista.Mostrar();
      break;
    case 5: // EXTRAER INICIO
      retornoExtraer = lista.ExtraerInicio();
      if (retornoExtraer == "")
        cout << "\tLISTA VACÍA. No se extrajo." << endl;
      else
        cout << "\tOk. Se extrajo del inicio: " << retornoExtraer << endl;
      break;
    case 6: // EXTRAER INTERMEDIO
      cout << "\nEscribe la palabra a extraer:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      retornoExtraer = lista.ExtraerIntermedio(datoAInsertar);
      if (retornoExtraer == "") // esta vacía
        cout << "\tLISTA VACÍA. No se extrajo." << endl;
      else if (retornoExtraer == "NO") // No se encontró el valor a extraer
        cout << "\tLISTA VACÍA. No se extrajo." << endl;
      else
        cout << "\tOk. Se extrajo: " << retornoExtraer << endl;
      break;
    case 7: // EXTRAER FINAL
      retornoExtraer = lista.ExtraerFinal();
      if (retornoExtraer == "")
        cout << "\tLISTA VACÍA. No se extrajo." << endl;
      else
        cout << "\tOk. Se extrajo del final: " << retornoExtraer << endl;
      break;
    case 8: // FIN DE APLICACIÓN
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 8);

  return 0;
}
