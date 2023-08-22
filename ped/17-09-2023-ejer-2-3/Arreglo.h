#pragma once
#include <iostream>
#define TAM 6

using namespace std;

class Arreglo {

public:
  Arreglo();
  ~Arreglo();

  int Borrar(int);
  int Insertar(int);
  void Mostrar();

private:
  int enteros[TAM]{3, 6, 9, 12};
  int ocupados{4};

protected:
};
