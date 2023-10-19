#include "ListaLigada.h"

ListaLigadaCircular::ListaLigadaCircular() {
  cabecera = final = NULL;
  numNodos = 0;
}

ListaLigadaCircular::~ListaLigadaCircular() {}

void ListaLigadaCircular::InsertarInicio(string valor) {
  Nodo *nuevoNodo = new Nodo{valor};
  if (!cabecera) {
    cabecera = final = nuevoNodo;
    nuevoNodo->sig = nuevoNodo;

  } else {
    nuevoNodo->sig = cabecera;
    cabecera = nuevoNodo;
    final->sig = cabecera;
  }
  numNodos += 1;
}

void ListaLigadaCircular::InsertarFinal(string valor) {
  Nodo *nuevoNodo = new Nodo{valor};
  if (!cabecera) {
    cabecera = final = nuevoNodo;
    nuevoNodo->sig = nuevoNodo;

  } else {
    nuevoNodo->sig = cabecera;
    final->sig = nuevoNodo;
    final = nuevoNodo;
  }
  numNodos += 1;
}

string ListaLigadaCircular::ExtraerEn(int numeroDesdeCabecera) {
  // se revisa que no esté vacía y que el indice que se extreará esté dentro del
  // tamaño de la lista
  string datoADevolver;
  if (cabecera == NULL || numNodos - 1 < numeroDesdeCabecera) {
    return "-1";
  }
  if (numNodos == 1) {
    datoADevolver = cabecera->dato;
    delete cabecera;
    cabecera = final = NULL;
    numNodos -= 1;
    return datoADevolver;
  }

  Nodo *nodo, *nodoPrevio;
  nodo = cabecera;
  nodoPrevio = final;
  int indice = 0;       // índice de cabecera = 0
  datoADevolver = "-1"; // si no se encuentra este dato se devuelve
  bool seEncontroDato = false;
  do {
    // se revisa si ya se llegó al indice
    if (indice == numeroDesdeCabecera) {
      datoADevolver = nodo->dato;
      seEncontroDato = true;

      nodoPrevio->sig = nodo->sig;
      delete nodo;
      numNodos -= 1;
      if (numNodos == 0)
        nodo = nodoPrevio = NULL;
      else
        nodo = nodoPrevio->sig;
    } else {
      // si no se ha llegado al índice a extraer, se sigue recorriendo

      nodoPrevio = nodoPrevio->sig;
      nodo = nodo->sig;
      indice = +1;
    }
    // mientras que no se haya recorrido completamente la lista & no se haya
    // encontrado el dato avanza el while
  } while (nodo != cabecera && !seEncontroDato);

  return datoADevolver;
}

// retorna false si falla porque esta vacía
bool ListaLigadaCircular::ExtraerImpares() {
  // se revisa que no esté vacía y que el indice que se extreará esté dentro del
  // tamaño de la lista
  if (cabecera == NULL) {
    return false; // falla, false por vacía
  }

  if (numNodos == 1) {
    ExtraerEn(0);
    return true;
  }
  Nodo *nodo, *nodoPrevio;
  nodo = cabecera;
  nodoPrevio = final;
  // si no se encuentra este dato se devuelve el false
  bool esImpar = true;
  bool cambiarCabecera = false;
  bool cambiarFinal = false;
  do {
    // si es Impar, se elimina
    if (esImpar) {
      cambiarCabecera = cambiarFinal = false;
      if (cabecera == nodo)
        cambiarCabecera = true;
      if (final == nodo)
        cambiarFinal = true;

      nodoPrevio->sig = nodo->sig;
      delete nodo;
      numNodos -= 1;
      if (numNodos == 0)
        nodo = nodoPrevio = NULL;
      else
        // como como el nodo, ahora es el siguiente, ya no se tiene que avanzar
        // otra vez el puntero
        nodo = nodoPrevio->sig;

      if (cambiarCabecera)
        cabecera = nodo;
      if (cambiarFinal)
        final = nodoPrevio;

      if (numNodos == 1)
        break;

    } else {
      nodoPrevio = nodoPrevio->sig;
      nodo = nodo->sig;
    }
    esImpar = !esImpar;
    // mientras que no se haya recorrido completamente la lista & no se haya
    // encontrado el dato avanza el while
  } while (nodo != cabecera || cambiarCabecera);
  return true;
}

void ListaLigadaCircular::Mostrar() {
  cout << "\tLista tamaño " << numNodos << ":" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl << endl;
    return;
  }

  Nodo *nodo;
  nodo = cabecera;
  int indice = 0;
  do {
    mostrarValor(nodo->dato, indice);
    if (nodo == cabecera)
      cout << "\t <== cabecera";
    if (nodo == final)
      cout << "\t <== final";
    cout << "\n";
    nodo = nodo->sig;
    indice += 1;
  } while (nodo != cabecera);
}

int ListaLigadaCircular::GetTamano() { return numNodos; }

void mostrarValor(string valor, int indice) {
  cout << "\t\tPalabra[" << indice + 1 << "]: " << valor;
}
