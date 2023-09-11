#pragma once
#include <iostream>
#include <string>

#define TAM 10

using namespace std;

class Pila {

public:
  Pila();
  ~Pila();

  int Consultar();
  int Extraer(); // pop
  int Insertar(int);
  void Mostrar();

private:
  int pilaEnteros[TAM];

  int min, max, tope;

protected:
};
