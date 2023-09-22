#include "PilaDinamica.h"
#include <iostream>

Pila::~Pila() {}

Pila::Pila() { tope = NULL; }
Pila::Pila(Empleado dato) { tope = new Nodo{dato, NULL}; }

Empleado Pila::Consultar() {
  // mostrar el valor señalado por el tope
  if (tope == NULL) {
    return {};
  }
  return {tope->dato};
}

Empleado Pila::Extraer() {
  if (tope == NULL) { // revisar si hay valores en la pila
    return {};
  }
  Empleado ret = tope->dato; // extracción del valor en el tope
  Nodo *aBorrar = tope;      // extraer información del tope
  tope = tope->prev;         // descender el tope
  delete aBorrar;            // liberar el nodo extraído
  return ret;
}

void Pila::Insertar(Empleado nuevoDato) {
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
    mostrarEmpleado(siguienteNodo->dato);
    siguienteNodo = siguienteNodo->prev;
  }
  cout << "\t<= Mínimo" << endl;
}

void mostrarEmpleado(Empleado empleado) {
  cout << "\n\tNOMBRE: " << empleado.nombreEmpleado
       << "\n\tCLAVE: " << empleado.claveEmpleado << "\n\tSUELDO: $"
       << empleado.sueldoEmpleado;
}
