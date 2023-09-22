#pragma once
#include <iostream>

using namespace std;

typedef struct Nodo {
  int dato;
  Nodo *prev; // Una letra y dígitos
} Nodo;

class Pila {

public:
  Pila(int);
  ~Pila();

  int Consultar();
  int Extraer(); // pop
  int Insertar(int);
  void Mostrar();

private:
  Nodo *tope;

protected:
};
