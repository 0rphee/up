#include "ListaLigada.cpp"
#include <iostream>

int main() {
  ListaLigada lista;

  int opc;
  int retornoExtraer;

  do {
    cout << "\n1. Ingresar dato.\n2. Extraer dato\n3. "
            "Mostrar lista\n4. Salir\n> ";
    cin >> opc;

    int datoAInsertar;
    switch (opc) {
    case 1:
      cout << "\nEscribe el entero a insertar:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      lista.InsertarAscendente(datoAInsertar);
      cout << "\tOK. Se insertó correctamente" << endl;
      break;
    case 2:
      retornoExtraer = lista.Extraer();
      if (retornoExtraer == -1)
        cout << "\tERROR. La lista está vacía" << endl;
      else
        cout << "\tOK. Se extrajo el valor: " << retornoExtraer << endl;
      break;
    case 3:
      lista.Mostrar();
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
