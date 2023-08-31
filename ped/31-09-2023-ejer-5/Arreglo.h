#pragma once
#include <iostream>
#include <string>

using namespace std;

class Arreglo {

public:
  Arreglo();
  ~Arreglo();

  void LeerNombre();
  void Mostrar();
  void Ordenar();
  void Poblar();

private:
  int **arr;
  int reng;
  int col;
  string nom;

protected:
};
