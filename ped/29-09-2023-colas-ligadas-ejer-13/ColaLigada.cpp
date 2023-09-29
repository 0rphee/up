#include "ColaLigada.h"

ColaLigada::ColaLigada() { inicio = final = NULL; }

ColaLigada::~ColaLigada() {}

Turno ColaLigada::Consultar() {
  if (inicio == NULL)
    return {"-1"};
  Turno extraido = inicio->dato;
  return extraido;
}

Turno ColaLigada::Extraer() {
  if (inicio == NULL)
    return {"-1"};
  Nodo *nodo = inicio;

  Turno extraido = nodo->dato;
  inicio = nodo->sig;
  if (inicio == NULL)
    final = NULL;
  delete nodo;
  return extraido;
}

void ColaLigada::Insertar(Turno nuevoDato) {
  Nodo *nodo = new Nodo;  // nodo nuevo
  nodo->dato = nuevoDato; // datos del nuevo nodo
  nodo->sig = NULL;       // ultimo nodo apunta a Null
  if (inicio == NULL)
    inicio = nodo; // solo con primera inserción
  if (final != NULL)
    final->sig = nodo; // excepto en la primera inserción
  final = nodo;
}

void ColaLigada::Mostrar() {
  cout << "\tCola:" << endl;
  if (inicio == NULL) {
    cout << "\t*COLA VACÍA*" << endl;
    return;
  }
  Nodo *nodo = inicio;
  do {
    Turno turno = nodo->dato;

    mostrarTurno(turno);
    if (inicio == nodo)
      cout << "\t <== inicio";
    if (final == nodo)
      cout << "\t <== final";
    cout << "\n\n";
    nodo = nodo->sig;
  } while (nodo != NULL);
}

void mostrarTurno(Turno turno) { cout << "\t\tTurno: " << turno.nombreTurno; }
