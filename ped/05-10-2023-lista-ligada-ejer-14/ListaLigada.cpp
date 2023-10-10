#include "ListaLigada.h"

ListaLigada::ListaLigada() { cabecera = final = NULL; }

ListaLigada::~ListaLigada() {}

void ListaLigada::InsertarInicio(string nuevoDato) {
  // crear nodo nuevo
  Nodo *nodoNuevo = new Nodo{nuevoDato, cabecera};
  cabecera = nodoNuevo;
  if (final == NULL)
    final = nodoNuevo;
}

int ListaLigada::InsertarInter(string despuesDe, string nuevoDato) {
  if (cabecera == NULL) {
    InsertarInicio(nuevoDato);
    return -1; // lista vacía, insertar inicio
  }
  Nodo *nodo = cabecera;
  do {
    if (nodo->dato == despuesDe) {
      nodo->sig = new Nodo{nuevoDato, nodo->sig};
      if (nodo == final)
        final = nodo->sig;
      return 0;
    }
    nodo = nodo->sig;
  } while (nodo != NULL);
  // no se encontró, lo insertamos al final
  InsertarFinal(nuevoDato);
  return -2;
}

int ListaLigada::InsertarFinal(string nuevoDato) {
  if (!cabecera) {
    InsertarInicio(nuevoDato);
    return -1; // lista vacía, se insertó al principio
  }
  Nodo *nodo = new Nodo{nuevoDato, NULL};
  final->sig = nodo;
  final = nodo;
  return 0; // se insertó correctamente al final
}

void ListaLigada::Mostrar() {
  cout << "\tLista:" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl;
    return;
  }
  Nodo *nodo = cabecera;
  do {
    string valor = nodo->dato;

    mostrarValor(valor);
    if (cabecera == nodo)
      cout << "\t <== cabecera";
    if (final == nodo)
      cout << "\t <== final";
    cout << "\n";
    nodo = nodo->sig;
  } while (nodo != NULL);
}

void mostrarValor(string valor) { cout << "\t\tPalabra: " << valor; }
