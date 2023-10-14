#include "ListaLigada.cpp"
#include <iostream>

int main() {
  ListaLigadaCircular lista;

  int opc;
  bool seEncontro;
  int datoAInsertar;

  do {
    cout << "\n1. Ingresar dato al final\n2. Buscar entero\n3. Mostrar "
            "Inicio\n4. Mostrar Último Visitado\n5. Salir\n> ";
    cin >> opc;

    switch (opc) {
    case 1: // INSERTAR FINAL
      cout << "\nEscribe el entero a insertar al final:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      lista.InsertarFinal(datoAInsertar);
      cout << "\tOK. Se insertó correctamente" << endl;
      break;
    case 2: // BUSCAR ENTERO
      cout << "\nEscribe el entero a buscar en la lista:\n> ";
      cin >> datoAInsertar;
      cout << endl;
      seEncontro = lista.Buscar(datoAInsertar);
      if (seEncontro)
        cout << "SÍ se encontró el entero: " << datoAInsertar << endl;
      else
        cout << "NO se encontró el entero: " << datoAInsertar << endl;
      break;
    case 3: // MOSTRAR INICIO
      lista.Mostrar(false);
      break;
    case 4: // MOSTRAR ULTIMO VISITADO
      lista.Mostrar(true);
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
