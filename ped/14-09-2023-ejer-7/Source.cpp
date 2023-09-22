#include "PilaDinamica.cpp"
#include <iostream>

int main() {
  Pila miPila = Pila();
  miPila.Mostrar();

  int opc;

  Empleado retorno;
  do {
    cout << "\n1. Contratar empleado\n2. Extraer (despedir) más reciente "
            "empleado\n3. Consultar último empleado contratado\n4. Mostrar "
            "todos los empleados\n5. "
            "Salir\n> ";
    cin >> opc;
    Empleado datoAInsertar;
    switch (opc) {
    case 1:
      cout << "\nEscribe el nombre del empleado a contratar: ";
      cin >> datoAInsertar.nombreEmpleado;
      cout << "\nEscribe la clave del empleado a contratar: ";
      cin >> datoAInsertar.claveEmpleado;
      cout << "\nEscribe el sueldo del empleado a contratar: ";
      cin >> datoAInsertar.sueldoEmpleado;
      cout << endl;
      miPila.Insertar(datoAInsertar);
      break;
    case 2:
      retorno = miPila.Extraer();
      if (retorno.nombreEmpleado == "") {
        cout << "\n\tPila vacía. NO SE EXTRAJO" << endl;
      } else {
        cout << "\n\tOK. Se extrajo (despidió) al empleado: " << endl;
        mostrarEmpleado(retorno);
      }
      break;
    case 3:
      retorno = miPila.Consultar();
      if (retorno.nombreEmpleado == "") {
        cout << "\n\tPila vacía. NO SE CONSULTÓ" << endl;
      } else {
        cout << "\n\tOK. Se consultó el último empleado contratado: " << endl;
        mostrarEmpleado(retorno);
      }
      break;
    case 4:
      miPila.Mostrar();
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
