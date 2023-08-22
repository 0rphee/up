#include "Arreglo.cpp"
#include <iostream>

int main() {
  Arreglo arreglo;

  cout << "Parte1:" << endl << "Arreglo enteros original" << endl;
  arreglo.MostrarEnteros();

  arreglo.OrdenarEnteros();

  cout << "Arreglo ordenado" << endl;
  arreglo.MostrarEnteros();

  cout << endl << "Parte2:" << endl << "Arreglo de strings original" << endl;
  arreglo.MostrarStrings();

  arreglo.OrdenarStrings();

  cout << "Arreglo de strings ordenado" << endl;
  arreglo.MostrarStrings();

  return 0;
}
