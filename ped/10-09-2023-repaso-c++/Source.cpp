#include "Ejemplo.cpp"
#include <iostream>

int main() {
  Ejemplo ej = Ejemplo();

  ej.Mostrar();

  int a, b;
  cout << "Dime un entero" << endl;
  cin >> a;

  cout << "Dime otro entero" << endl;
  cin >> b;

  int suma = ej.Sumar(a, b);

  cout << "Resultado:" << suma << endl << endl;

  return 0;
}
