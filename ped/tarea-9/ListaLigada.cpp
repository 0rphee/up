#include "ListaLigada.h"

ListaLigada::ListaLigada() { cabecera = final = NULL; }

ListaLigada::~ListaLigada() {}

void ListaLigada::InsertarInicio(int nuevoDato) {
  // crear nodo nuevo
  Nodo *nodoNuevo = new Nodo{nuevoDato, cabecera};
  cabecera = nodoNuevo;
  if (final == NULL)
    final = nodoNuevo;
}

void ListaLigada::InsertarAscendente(int nuevoDato) {
  Nodo *nuevoNodo = new Nodo{nuevoDato, NULL};

  if (!cabecera) { // Si la lista está vacía, el nuevo nodo se convierte en la
                   // cabecera y el final.
    cabecera = final = nuevoNodo;
  } else if (nuevoDato <=
             cabecera->dato) { // Si el nuevoDato es menor o igual que el primer
                               // nodo, inserta al inicio.
    nuevoNodo->sig = cabecera;
    cabecera = nuevoNodo;
  } else if (nuevoDato >= final->dato) { // Si el nuevoDato es mayor o igual que
                                         // el último nodo, inserta al final.
    final->sig = nuevoNodo;
    final = nuevoNodo;
  } else { // Caso general: insertar en orden ascendente.
    Nodo *anterior = cabecera;
    Nodo *actual = cabecera->sig;

    while (actual && actual->dato < nuevoDato) {
      anterior = actual;
      actual = actual->sig;
    }

    nuevoNodo->sig = actual;
    anterior->sig = nuevoNodo;
  }
}

int ListaLigada::InsertarFinal(int nuevoDato) {
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
    int valor = nodo->dato;

    mostrarValor(valor);
    if (cabecera == nodo)
      cout << "\t <== cabecera";
    if (final == nodo)
      cout << "\t <== final";
    cout << "\n";
    nodo = nodo->sig;
  } while (nodo != NULL);
}
int ListaLigada::Extraer() {
  if (!cabecera) {
    return -1; // Lista vacía
  }

  int valorExtraido = cabecera->dato;
  Nodo *nodoAEliminar = cabecera;

  if (cabecera == final) {
    // Si solo hay un nodo en la lista, la lista queda vacía después de
    // extraerlo.
    cabecera = final = nullptr;
  } else {
    cabecera = cabecera->sig;
  }

  delete nodoAEliminar;
  return valorExtraido;
}

void mostrarValor(int valor) { cout << "\t\tDato: " << valor; }
