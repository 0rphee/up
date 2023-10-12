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

string ListaLigada::ExtraerInicio() {
  if (cabecera == NULL)
    return ""; // lista vacía, no se extrae nada
  Nodo *nodoABorrar = cabecera;
  string valorAExtraer = nodoABorrar->dato;
  cabecera = nodoABorrar->sig;
  if (final == cabecera)
    final = NULL;
  delete nodoABorrar;
  return valorAExtraer;
}

string ListaLigada::ExtraerIntermedio(string aExtraer) {
  if (cabecera == NULL)
    return "";

  Nodo *nodoAnterior = NULL;
  Nodo *nodo = cabecera;
  bool encontrada = false; // no encontrada

  while (nodo != NULL) {
    if (nodo->dato == aExtraer) {
      encontrada = true; // se encontró la palabra
      break;
    }
    nodoAnterior = nodo;
    nodo = nodo->sig;
  }

  if (!encontrada)
    return "NO"; // no se encontró la palabra, no se extrae
  string extraida = nodo->dato;

  if (nodo == cabecera) // en caso de extraer el nodo de la cabecera
    cabecera = nodo->sig;
  else
    nodoAnterior->sig = nodo->sig;

  if (nodo == final)
    final = nodoAnterior; // en caso de extraer el nodo final
  // liberar nodo extraido
  delete nodo;
  return extraida;
}

string ListaLigada::ExtraerFinal() {
  if (cabecera == NULL)
    return ""; // lista vacía, no se extrae nada
  if (final == cabecera)
    return ExtraerInicio();

  Nodo *nodoAnterior = NULL;
  Nodo *nodo = final;
  while (nodo != final) {
    nodoAnterior = nodo;
    nodo = nodo->sig;
  }
  string valorAExtraer = nodo->dato;
  nodoAnterior->sig = NULL;
  final = nodoAnterior;
  cabecera = nodo->sig;
  delete nodo;
  return valorAExtraer;
}

void ListaLigada::Mostrar() {
  cout << "\tLista:" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl;
    return;
  }
  Nodo *nodo = cabecera;
  do {
    mostrarValor(nodo->dato);
    if (cabecera == nodo)
      cout << "\t <== cabecera";
    if (final == nodo)
      cout << "\t <== final";
    cout << "\n";
    nodo = nodo->sig;
  } while (nodo != NULL);
}

void mostrarValor(string valor) { cout << "\t\tPalabra: " << valor; }
