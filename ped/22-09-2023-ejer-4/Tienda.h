#pragma once
#include <iostream>
#include <string>
#define TAM 6

using namespace std;

typedef struct Sucursal {
  int numSuc;
  string nomGte;
  int ventas[2];
} Sucursal;

class Tienda {

public:
  Tienda();
  ~Tienda();

  void Mostrar();
  void Ordenar();
  bool Poblar();

private:
  Sucursal sucs[TAM];
  int ocupados{4};

protected:
};
