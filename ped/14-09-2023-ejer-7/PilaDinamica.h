#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Empleado {
  string claveEmpleado;
  string nombreEmpleado;
  double sueldoEmpleado;
} Empleado;

typedef struct Nodo {
  Empleado dato;
  Nodo *prev; // Una letra y dígitos
} Nodo;

class Pila {

public:
  Pila();
  Pila(Empleado);
  ~Pila();

  Empleado Consultar();
  Empleado Extraer(); // pop
  void Insertar(Empleado);
  void Mostrar();

private:
  Nodo *tope;

protected:
};

void mostrarEmpleado(Empleado);
