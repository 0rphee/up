#pragma once
#include <iostream>
#include <string>

#define TAM 5

using namespace std;

class Cola {

public:
  Cola();
  ~Cola();

  string Extraer();
  int Insertar(string);
  void Mostrar();

private:
  string arreglo[TAM];
  int min;
  int max;
  int inicio;
  int final;

protected:
};
