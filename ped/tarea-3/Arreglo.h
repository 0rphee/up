#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Empleado {
  string nombre;
  int antiguedad;
  int piezas_mes1;
  int piezas_mes2;
  int piezas_mes3;
} Empleado;

class Fabrica {

public:
  Fabrica();
  ~Fabrica();

  int Poblar();
  void Ordenar();
  void Mostrar();

private:
  Empleado *arr;
  int numEmpleados{0};

protected:
};
