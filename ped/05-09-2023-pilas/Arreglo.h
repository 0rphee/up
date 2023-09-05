#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pila {

public:
  Pila(int);
  ~Pila();

  int Consultar();
  int Extraer(); // pop
  int Insertar(int);
  void Mostrar();

private:
  int *pilaEnteros;

  int min, max, tope;

protected:
};
