#include "ListaLigada.h"

ListaLigadaCircular::ListaLigadaCircular() {
  cabecera = final = ultimoVisitado = NULL;
}

ListaLigadaCircular::~ListaLigadaCircular() {}

void ListaLigadaCircular::InsertarFinal(int valor) {
  Nodo *nuevoNodo = new Nodo{valor};
  if (!cabecera) {
    cabecera = final = ultimoVisitado = nuevoNodo;
    nuevoNodo->sig = nuevoNodo;

  } else {
    nuevoNodo->sig = cabecera;
    final->sig = nuevoNodo;
    final = nuevoNodo;
  }
}
void ListaLigadaCircular::Mostrar(bool ultimoVisitadoB) {
  cout << "\tLista:" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl;
    return;
  }

  Nodo *nodo, *corteWhile;
  if (ultimoVisitadoB)
    corteWhile = nodo = ultimoVisitado;
  else
    corteWhile = nodo = cabecera;

  do {
    mostrarValor(nodo->dato);
    if (nodo == cabecera)
      cout << "\t <== cabecera";
    if (nodo == final)
      cout << "\t <== final";
    if (nodo == ultimoVisitado)
      cout << "\t <== ultimoVisitado";
    cout << "\n";
    nodo = nodo->sig;
  } while (nodo != corteWhile);
}

bool ListaLigadaCircular::Buscar(int valor) {
  if (!cabecera)
    return false;

  Nodo *nodoActual = cabecera;
  do {
    if (nodoActual->dato == valor) {
      ultimoVisitado = nodoActual;
      return true;
    }
    nodoActual = nodoActual->sig;
  } while (nodoActual != cabecera);

  return false; // El valor no se encontró en la lista.
}

void mostrarValor(int valor) { cout << "\t\tPalabra: " << valor; }
