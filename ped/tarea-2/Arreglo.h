#pragma once
#include <iostream>
#include <string>

#define TAM 10

using namespace std;

typedef struct Empleado {
  string nombre;
  int estaturaCm;
  double sueldoSemanal;
} Empleado;

class Arreglo {

public:
  Arreglo();
  ~Arreglo();

  void Ordenar();
  void Mostrar();
  int Borrar(string);
  int Insertar(Empleado);

private:
  Empleado arr[TAM] = {
      {"Roberto", 180, 1200}, {"Juan", 175, 1000},  {"Mauricio", 165, 1700},
      {"Iván", 177, 3400},    {"Pedro", 181, 2200},
  };
  int ocupados{5};

protected:
};
