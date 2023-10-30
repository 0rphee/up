#include "ListaCombinada.cpp"
#include <iostream>
#include <string>

int main() {
  cout << "** PROYECTO PARCIAL **\n"
       << "Obsequios para trabajadores" << endl
       << endl;

  ListaArticulo listaArticulos;
  listaArticulos.nombreLista = "Articulos";

  ListaTrabajador listaTrabajadores;
  listaTrabajadores.nombreLista = "Trabajadores";

  ListaCombinada listaCombinada;
  listaCombinada.nombreLista = "Articulos entregados a Trabajadores";

  int opc;
  Articulo extraidoArticulo, articuloAInsertar;
  Trabajador extraidoTrabajador, trabajadorAInsertar;
  Combinada extraidoCombinada, combinadaAInsertar;
  string trabajadorRevisar;

  do {
    cout << "1. Ingresar artículo de proveedor\n"
         << "2. Ingresar trabajador a fila de regalos\n"
         << "3. Mostrar Estado de Filas\n"
         << "4. PREMIACION: Dar siguiente regalo a trabajador\n"
         << "5. SUPERVISION: Revisar trabajadores y sus regalos\n"
         << "6. SUPERVISION: Revisar trabajador específico\n"
         << "7. Salir\n"
         << ">";
    cin >> opc;
    cout << endl;

    cin.ignore();
    switch (opc) {
    case 1: // INSERTAR: ARTICULO
      cout << "\nEscribe el nombre del artículo a insertar:\n> ";
      getline(cin, articuloAInsertar.nombreArticulo, '\n');
      cout << endl;

      cout << "\nEscribe el nombre del proveedor:\n> ";
      getline(cin, articuloAInsertar.proveedorArticulo);
      cout << endl;

      listaArticulos.InsertarFinal(articuloAInsertar);
      cout << "\tOK. Se insertó correctamente" << endl << endl;
      break;
    case 2: // INSERTAR: TRABAJADOR A FILA

      if (listaArticulos.GetCantidadNodos() <=
          listaTrabajadores.GetCantidadNodos()) {
        cout << "¡Ingresa más regalos antes de ingresar trabajadores!" << endl
             << endl;
      } else {

        cout << "\nEscribe el nombre del trabajador a insertar a la fila:\n> ";
        getline(cin, trabajadorAInsertar.nombreTrabajador);
        cout << endl;

        cout << "\nEscribe el nombre del departamento en que trabaja:\n> ";
        getline(cin, trabajadorAInsertar.departamentoTrabajador);
        cout << endl;

        listaTrabajadores.InsertarFinal(trabajadorAInsertar);
        cout << "\tOK. Se insertó correctamente" << endl << endl;
      }
      break;
    case 3: // MOSTRAR: FILAS
      cout << endl << "\t==============================" << endl;
      listaArticulos.MostrarIniFin();
      cout << endl << "\t==============================" << endl;
      listaTrabajadores.MostrarIniFin();
      cout << endl << "\t==============================" << endl;
      listaCombinada.MostrarIniFin();
      cout << endl << "\t==============================" << endl << endl;
      break;
    case 4: // PREMIACION: dar siguiente regalo a trabajador
      if (listaTrabajadores.GetCantidadNodos() > 0) {
        extraidoTrabajador = listaTrabajadores.ExtraerInicio();
        extraidoArticulo = listaArticulos.ExtraerInicio();
        listaCombinada.InsertarFinal({extraidoTrabajador, extraidoArticulo});
        cout << "Se da regalo:" << endl;
        mostrarArticulo(extraidoArticulo);
        cout << endl << "Al trabajador:" << endl;
        mostrarTrabajador(extraidoTrabajador);
        cout << endl << endl;
      } else {
        cout << "\n\t** ERROR: Hace falta ingresar más trabajadores y/o "
                "artículos"
             << endl
             << endl;
      }
      break;
    case 5: // SUPERVISION: Revisar (mostrar) trabajadores y sus regalos
      cout << endl << "\t==============================" << endl;
      listaCombinada.MostrarIniFin();
      cout << endl << "\t==============================" << endl << endl;
      break;
    case 6: // SUPERVISION: Revisar trabajador específico
      cout << "\nEscribe el trabajador a revisar:\n> ";
      getline(cin, trabajadorRevisar);
      cout << endl;
      extraidoCombinada = listaCombinada.ConsultaTrabajador(trabajadorRevisar);
      if (extraidoCombinada.trabajador.nombreTrabajador == "-1")
        cout << "NO se encontró al trabajador: " << trabajadorRevisar << endl;
      else {
        cout << "Se encontró:" << endl;
        mostrarCombinada(extraidoCombinada);
        cout << endl << endl;
      }
      break;
    case 7: // FIN DE APLICACIÓN
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 7);

  return 0;
}
