#include "Tienda.cpp"
#include <iostream>

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int main() {
  Tienda tienda;
  bool codigo;

  cout << "Arreglo vacío" << endl;
  tienda.Mostrar();
  cout << "\n...poblando el arreglo..." << endl;
  codigo = tienda.Poblar();
  if (codigo)
    cout << "\n\tWARNING: Se llenó el arreglo. Algunas sucursales no se "
            "registraron."
         << endl;
  else {
    cout << "\n\tOK: Se pobló el arreglo correctamente." << endl;
  }
  clearScreen();

  cout << "Arreglo con información." << endl;
  tienda.Mostrar();

  cout << "Arreglo ordenado." << endl;
  tienda.Ordenar();
  tienda.Mostrar();
  return 0;
}
