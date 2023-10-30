#include "ListaTrabajadores.h"

ListaTrabajador::ListaTrabajador() {
  cabecera = final = NULL;
  cantidadNodos = 0;
  nombreLista = "";
}

ListaTrabajador::~ListaTrabajador() {}

int ListaTrabajador::GetCantidadNodos() { return cantidadNodos; }

void ListaTrabajador::InsertarInicio(Trabajador valor) {
  NodoTrabajador *nuevoNodo = new NodoTrabajador{valor}; // paso 1 & 2 & 3
  nuevoNodo->sig = cabecera;
  nuevoNodo->prev = NULL; // paso 4

  if (cabecera)
    cabecera->prev = nuevoNodo; // paso 5
  else
    final = nuevoNodo;
  cabecera = nuevoNodo; // paso 6
  cantidadNodos += 1;
}

void ListaTrabajador::InsertarFinal(Trabajador valor) {
  if (cabecera == NULL) {
    InsertarInicio(valor);
    return;
  }
  NodoTrabajador *nuevoNodo = new NodoTrabajador{valor};
  nuevoNodo->sig = NULL;
  nuevoNodo->prev = final;

  final->sig = nuevoNodo;
  final = nuevoNodo;
  cantidadNodos += 1;
}

bool ListaTrabajador::InsertarMedio(Trabajador valorNuevo,
                                    Trabajador despuesDe) {
  if (!cabecera)
    return false; // lista vacía, no se inserta

  NodoTrabajador *nodoAnterior = cabecera;
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
    NodoTrabajador *nodoSiguiente = nodoAnterior->sig;

    NodoTrabajador *nuevoNodo = new NodoTrabajador{valorNuevo}; // paso 2 & 3
    nuevoNodo->sig = nodoSiguiente;                             // paso 4
    nuevoNodo->prev = nodoAnterior;                             // paso 5
    nodoAnterior->sig = nuevoNodo;                              // paso 6
    nodoSiguiente->prev = nuevoNodo;
  }
  cantidadNodos += 1;
  return true;
}

Trabajador ListaTrabajador::ExtraerMedio(Trabajador valor) {
  if (!cabecera) {
    return {"-1"}; // Caso: lista vacía. No se puede extraer.
  }

  NodoTrabajador *nodoActual = cabecera;

  while (nodoActual && nodoActual->dato != valor) {
    nodoActual = nodoActual->sig;
  }

  if (!nodoActual) {
    return {"-1"}; // El valor no se encontró en la lista.
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

  cantidadNodos -= 1;
  Trabajador extraida = nodoActual->dato;
  delete nodoActual;
  return extraida;
}

Trabajador ListaTrabajador::ExtraerFinal() {
  if (!final) {
    return {"-1"}; // Caso: lista vacía, no se extrae
  }

  NodoTrabajador *nodoAExtraer = final;
  final = final->prev; // Actualizamos el puntero 'final' al nodo anterior
  if (final == NULL) {
    cabecera = NULL; // Si la lista solo tenía un elemento, ahora esta vacía
  } else {
    final->sig = NULL; // Desvinculamos el nodo final
  }

  cantidadNodos -= 1;
  Trabajador extraida = nodoAExtraer->dato;
  delete nodoAExtraer;
  return extraida;
}

Trabajador ListaTrabajador::ExtraerInicio() {
  if (!cabecera) {
    return {"-1"}; // Caso: lista vacía. No se extrae
  }
  NodoTrabajador *nodoAExtraer = cabecera;
  cabecera = cabecera->sig; // paso 1

  if (cabecera == NULL)
    final = NULL; // Caso: cabecera igual a final
  else
    cabecera->prev = NULL; // paso 2

  cantidadNodos -= 1;
  Trabajador extraida = nodoAExtraer->dato;
  delete nodoAExtraer;
  return extraida;
}

Trabajador ListaTrabajador::ExtraerEnIndice(int indice) {
  if (indice < 0 || indice >= cantidadNodos || !cabecera) {
    return {"-1"}; // Índice fuera de rango o lista vacía, no se puede extraer.
  }

  NodoTrabajador *nodoActual = cabecera;
  int indiceActual = cantidadNodos - 1; // Empezamos desde el índice más alto

  while (indiceActual > indice) {
    nodoActual = nodoActual->prev;
    indiceActual--;
  }

  if (nodoActual->prev) {
    nodoActual->prev->sig = nodoActual->sig;
  } else {
    cabecera = nodoActual->sig; // Actualizamos la cabecera si el nodo a extraer
                                // es el primero
  }

  if (nodoActual->sig) {
    nodoActual->sig->prev = nodoActual->prev;
  } else {
    final =
        nodoActual
            ->prev; // Actualizamos el final si el nodo a extraer es el último
  }

  Trabajador extraida = nodoActual->dato;
  delete nodoActual;
  cantidadNodos--; // Actualizamos el número de nodos
  return extraida;
}

void ListaTrabajador::MostrarIniFin() {
  cout << "\tLista " << nombreLista << " (" << cantidadNodos << "):" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl;
    return;
  }
  NodoTrabajador *nodo;
  nodo = cabecera;

  int i = 0;
  do {
    mostrarTrabajador(nodo->dato);
    cout << "\t [" << i + 1 << "]";
    if (nodo == cabecera)
      cout << " <== cabecera";
    if (nodo == final)
      cout << " <== final";
    cout << "\n";
    nodo = nodo->sig;
    i++;
  } while (nodo != NULL);
}

void ListaTrabajador::MostrarFinIni() {
  cout << "\tLista " << nombreLista << " (" << cantidadNodos << "):" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl;
    return;
  }
  NodoTrabajador *nodo;
  nodo = final;

  int i = 0;
  do {
    mostrarTrabajador(nodo->dato);
    cout << "\t [" << i + 1 << "]";
    if (nodo == cabecera)
      cout << " <== cabecera";
    if (nodo == final)
      cout << " <== final";
    cout << "\n";
    nodo = nodo->prev;
    i++;
  } while (nodo != NULL);
  cout << "\n\n";
}

void mostrarTrabajador(Trabajador valor) {
  cout << "\tTrabajador:\n"
       << "\t\tNombre: " << valor.nombreTrabajador << "\n"
       << "\t\tDepartamento: " << valor.departamentoTrabajador;
}
