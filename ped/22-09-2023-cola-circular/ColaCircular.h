#pragma once
#include <iostream>
#include <string>

using namespace std;

class ColaCircular {

public:
  ColaCircular(int);
  ~ColaCircular();

  string Consultar();
  string Extraer();
  int Insertar(string);
  void Mostrar();

private:
  string *arr;
  int min;
  int max;
  int inicio;
  int final;

protected:
};
