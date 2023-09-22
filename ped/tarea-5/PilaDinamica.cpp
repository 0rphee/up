#include "PilaDinamica.h"
#include <iostream>

Pila::~Pila() {}

Pila::Pila() { tope = NULL; }

Pila::Pila(char dato) { tope = new Nodo{dato, NULL}; }

char Pila::Consultar() {
  // mostrar el valor señalado por el tope
  if (tope == NULL) {
    return 99;
  }
  return tope->dato;
}

char Pila::Extraer() {
  if (tope == NULL) { // revisar si hay valores en la pila
    return 99;
  }
  char ret = tope->dato; // extracción del valor en el tope
  Nodo *aBorrar = tope;  // extraer información del tope
  tope = tope->prev;     // descender el tope
  delete aBorrar;        // liberar el nodo extraído
  return ret;
}

void Pila::Insertar(char nuevoDato) {
  Nodo *nuevoNodo = new Nodo{nuevoDato, tope};
  tope = nuevoNodo;
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

bool Pila::EstaVacia() {
  if (tope == NULL) {
    return true;
  }
  return false;
}
