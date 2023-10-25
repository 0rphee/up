#include "ListaDoble.h"

ListaDobleEnlace::ListaDobleEnlace() { cabecera = final = NULL; }

ListaDobleEnlace::~ListaDobleEnlace() {}

void ListaDobleEnlace::InsertarInicio(string valor) {
  Nodo *nuevoNodo = new Nodo{valor}; // paso 1 & 2 & 3
  nuevoNodo->sig = cabecera;
  nuevoNodo->prev = NULL; // paso 4

  if (cabecera)
    cabecera->prev = nuevoNodo; // paso 5
  else
    final = nuevoNodo;
  cabecera = nuevoNodo; // paso 6
}

void ListaDobleEnlace::InsertarFinal(string valor) {
  if (cabecera == NULL) {
    InsertarInicio(valor);
    return;
  }
  Nodo *nuevoNodo = new Nodo{valor};
  nuevoNodo->sig = NULL;
  nuevoNodo->prev = final;

  final->sig = nuevoNodo;
  final = nuevoNodo;
}

bool ListaDobleEnlace::InsertarMedio(string valorNuevo, string despuesDe) {
  if (!cabecera)
    return false; // lista vacía, no se inserta

  Nodo *nodoAnterior = cabecera;
  bool encontrada = false; // false = no encontrada
  do {
    if (nodoAnterior->dato == despuesDe) {
      encontrada = true;
      break;
    }
    nodoAnterior = nodoAnterior->sig;

  } while (nodoAnterior != NULL);

  if (encontrada == false)
    return false; // no la encontró despuesDe, no se inserta
  else if (nodoAnterior == final) {
    InsertarFinal(valorNuevo); // se encontro en el último nodo
  } else {
    Nodo *nodoSiguiente = nodoAnterior->sig;

    Nodo *nuevoNodo = new Nodo{valorNuevo}; // paso 2 & 3
    nuevoNodo->sig = nodoSiguiente;         // paso 4
    nuevoNodo->prev = nodoAnterior;         // paso 5
    nodoAnterior->sig = nuevoNodo;          // paso 6
    nodoSiguiente->prev = nuevoNodo;
  }
  return true;
}

string ListaDobleEnlace::ExtraerMedio(string valor) {
  if (!cabecera) {
    return "-1"; // Caso: lista vacía. No se puede extraer.
  }

  Nodo *nodoActual = cabecera;

  while (nodoActual && nodoActual->dato != valor) {
    nodoActual = nodoActual->sig;
  }

  if (!nodoActual) {
    return "-1"; // El valor no se encontró en la lista.
  }

  if (nodoActual->prev != NULL) {
    nodoActual->prev->sig =
        nodoActual->sig; // se reasigna el puntero al siguiente nodo del
                         // anterior nodo (se va a borrar el actual nodo)
  } else {
    cabecera = nodoActual->sig; // Si prev es NULL, estamos en cabecera, la
                                // actualizamos
  }

  if (nodoActual->sig != NULL) {
    nodoActual->sig->prev =
        nodoActual->prev; // se reasigna el puntero al anteriro nodo del
                          // siguiente nodo (se va a borrar el actual nodo)
  } else {
    final =
        nodoActual->prev; // Si sig es NULL, estamos en final, lo actualizamos
  }

  string extraida = nodoActual->dato;
  delete nodoActual;
  return extraida;
}

string ListaDobleEnlace::ExtraerFinal() {
  if (!final) {
    return "-1"; // Caso: lista vacía, no se extrae
  }

  Nodo *nodoAExtraer = final;
  final = final->prev; // Actualizamos el puntero 'final' al nodo anterior
  if (final == NULL) {
    cabecera = NULL; // Si la lista solo tenía un elemento, ahora esta vacía
  } else {
    final->sig = NULL; // Desvinculamos el nodo final
  }

  string extraida = nodoAExtraer->dato;
  delete nodoAExtraer;
  return extraida;
}

string ListaDobleEnlace::ExtraerInicio() {
  if (!cabecera) {
    return "-1"; // Caso: lista vacía. No se extrae
  }
  Nodo *nodoAExtraer = cabecera;
  cabecera = cabecera->sig; // paso 1

  if (cabecera == NULL)
    final = NULL; // Caso: cabecera igual a final
  else
    cabecera->prev = NULL; // paso 2

  string extraida = nodoAExtraer->dato;
  delete nodoAExtraer;
  return extraida;
}

void ListaDobleEnlace::MostrarIniFin() {
  cout << "\tLista:" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl;
    return;
  }
  Nodo *nodo;
  nodo = cabecera;

  do {
    mostrarValor(nodo->dato);
    if (nodo == cabecera)
      cout << "\t <== cabecera";
    if (nodo == final)
      cout << "\t <== final";
    cout << "\n";
    nodo = nodo->sig;
  } while (nodo != NULL);
}

void ListaDobleEnlace::MostrarFinIni() {
  cout << "\tLista:" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl;
    return;
  }
  Nodo *nodo;
  nodo = final;

  do {
    mostrarValor(nodo->dato);
    if (nodo == cabecera)
      cout << "\t <== cabecera";
    if (nodo == final)
      cout << "\t <== final";
    cout << "\n";
    nodo = nodo->prev;
  } while (nodo != NULL);
}

void mostrarValor(string valor) { cout << "\t\tPalabra: " << valor; }
