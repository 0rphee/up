#include "ListaDoble.cpp"
#include <iostream>

int main() {
  ListaDobleEnlace lista;

  int opc;
  string extraido, datoAInsertar, insertarDespuesDe;

  do {
    cout << "1. Insertar Inicio\n"
         << "2. Insertar Medio\n"
         << "3. Insertar Final\n"
         << "4. Extraer Inicio\n"
         << "5. Extraer Medio\n"
         << "6. Extraer Final\n"
         << "7. Mostrar Inicio a Final\n"
         << "8. Mostrar Final a Inicio\n"
         << "9. Salir\n"
         << ">";
    cin >> opc;
    cout << endl;

    switch (opc) {
    case 1: // INSERTAR INICIO
      cout << "\nEscribe el dato a insertar:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      lista.InsertarInicio(datoAInsertar);
      cout << "\tOK. Se insertó correctamente" << endl;
      break;
    case 2: // INSERTAR MEDIO
      cout << "\nEscribe el dato a insertar:\n> ";
      cin >> datoAInsertar;
      cout << endl;

      cout << "\nEscribe el dato tras el cual se insertará:\n> ";
      cin >> insertarDespuesDe;
      cout << endl;
      lista.InsertarMedio(datoAInsertar, insertarDespuesDe);
      cout << "\tOK. Se insertó correctamente" << endl;
      break;
    case 3: // INSERTAR FINAL
      cout << "\nEscribe el dato a insertar:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      lista.InsertarFinal(datoAInsertar);
      cout << "\tOK. Se insertó correctamente" << endl;
      break;
    case 4: // EXTRAER INICIO

      extraido = lista.ExtraerInicio();
      if (extraido == "-1")
        cout << "NO se extrajo, LISTA VACÍA" << endl << endl;
      else
        cout << "SÍ se extrajo el valor: " << extraido << endl;
      break;
    case 5: // EXTRAER MEDIO
      cout << "\nEscribe el dato a extraer:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      extraido = lista.ExtraerMedio(datoAInsertar);
      if (extraido == "-1")
        cout << "NO se extrajo, LISTA VACÍA" << endl << endl;
      else
        cout << "SÍ se extrajo el valor: " << extraido << endl;
      break;
    case 6: // EXTRAER FINAL
      extraido = lista.ExtraerFinal();
      if (extraido == "-1")
        cout << "NO se extrajo, LISTA VACÍA" << endl << endl;
      else
        cout << "SÍ se extrajo el valor: " << extraido << endl;
      break;
    case 7: // MOSTRAR INICIO A FINAL
      lista.MostrarIniFin();
      break;
    case 8: // MOSTRAR FINAL A INCIO
      lista.MostrarFinIni();
      break;
    case 9: // FIN DE APLICACIÓN
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 9);

  return 0;
}
