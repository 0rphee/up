#include "ColaLigada.h"

ColaLigada::ColaLigada() { inicio = final = NULL; }

ColaLigada::~ColaLigada() {}

Trailer ColaLigada::Consultar() {
  if (inicio == NULL)
    return {"-1"};
  Trailer extraido = inicio->dato;
  return extraido;
}

Trailer ColaLigada::Extraer() {
  if (inicio == NULL)
    return {"-1"};
  Nodo *nodo = inicio;

  Trailer extraido = nodo->dato;
  inicio = nodo->sig;
  if (inicio == NULL)
    final = NULL;
  delete nodo;
  return extraido;
}

void ColaLigada::Insertar(Trailer nuevoDato) {
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
    Trailer trailer = nodo->dato;

    mostrarTrailer(trailer);
    if (inicio == nodo)
      cout << "\t <== inicio";
    if (final == nodo)
      cout << "\t <== final";
    cout << "\n\n";
    nodo = nodo->sig;
  } while (nodo != NULL);
}

void mostrarTrailer(Trailer trailer) {
  cout << "\t\tPlacas: " << trailer.placas
       << "\n\t\tProducto: " << trailer.producto;
}
