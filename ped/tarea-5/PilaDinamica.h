#pragma once
#include <iostream>

using namespace std;

typedef struct Nodo {
  char dato;
  Nodo *prev; // Una letra y dígitos
} Nodo;

class Pila {

public:
  Pila();
  Pila(char);
  ~Pila();

  char Consultar();
  char Extraer(); // pop
  void Insertar(char);
  void Mostrar();
  bool EstaVacia();

private:
  Nodo *tope;

protected:
};
