#include "PilaDinamica.h"
#include <cstdio>
#include <iostream>

Pila::~Pila() {}

Pila::Pila(int dato) { tope = new Nodo{dato, NULL}; }

int Pila::Consultar() {
  // mostrar el valor señalado por el tope
  if (tope == NULL) {
    return -1;
  }
  return tope->dato;
}

int Pila::Extraer() {
  if (tope == NULL) {
    return -1;
  }
  int ret = tope->dato;
  Nodo *aBorrar = tope;
  tope = tope->prev;
  delete aBorrar;
  return ret;
}

int Pila::Insertar(int nuevoDato) {
  Nodo *nuevoNodo = new Nodo{nuevoDato, tope};
  tope = nuevoNodo;
  return 0;
}

void Pila::Mostrar() {
  cout << "Pila: " << endl;
  Nodo *siguienteNodo = tope;
  if (tope == NULL) {
    cout << "\tPILA VACÍA" << endl;
    return;
  }

  while (siguienteNodo != NULL) {
    cout << "\n\t" << siguienteNodo->dato;
    siguienteNodo = siguienteNodo->prev;
  }
  cout << "\t<= Mínimo" << endl;
}
