#include "ListaLigada.cpp"
#include <iostream>

int main() {
  ListaLigadaCircular lista;

  int opc, numNodos;
  string datoAInsertarOExtraido;
  bool resultadoExtraerImpares;

  do {
    cout << "1. Insertar nombre\n"
         << "2. Mostrar número de nodos de lista\n"
         << "3. Extraer 1 vez nodos impares\n"
         << "4. Extraer nodos impares hasta vaciar lista\n"
         << "5. Mostrar lista\n"
         << "6. Salir\n"
         << ">";
    cin >> opc;
    cout << endl;

    switch (opc) {

    case 1: // INSERTAR FINAL
      cout << "\nEscribe el nombre a insertar:\n> ";
      cin >> datoAInsertarOExtraido;
      cout << endl;
      lista.InsertarInicio(datoAInsertarOExtraido);
      cout << "\tOK. Se insertó correctamente" << endl;
      break;

    case 2: // MOSTRAR NÚMERO DE NODOS
      numNodos = lista.GetTamano();
      cout << "\nLa lista tiene " << numNodos << " nodos.\n\n";
      break;

    case 3: // EXTRAER NODOS IMPARES UNA VEZ
      resultadoExtraerImpares = lista.ExtraerImpares();
      if (resultadoExtraerImpares == true) // true = exito
      {
        cout << "\tSÍ se extrajeron los impares exitosamente" << endl;
        lista.Mostrar();
      } else
        cout << "\tNO se extrajeron, lista vacía" << endl;
      break;

    case 4: // EXTRAER NODOS IMPARES HASTA QUE SE ACABEN
      cout << "\tLista inicial:" << endl;
      lista.Mostrar();
      do {
        resultadoExtraerImpares = lista.ExtraerImpares();
        if (resultadoExtraerImpares == true) {
          cout << "\tSÍ se extrajeron los impares exitosamente" << endl;
          lista.Mostrar();
        }
      } while (resultadoExtraerImpares == true);
      cout << "\tSe terminaron de extraer impares, lista vacía" << endl;
      break;
    case 5: // MOSTRAR LISTA COMPLETA
      lista.Mostrar();
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
