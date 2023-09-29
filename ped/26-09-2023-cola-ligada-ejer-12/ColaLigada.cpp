#include "ColaLigada.h"

ColaLigada::ColaLigada() { inicio = final = NULL; }

ColaLigada::~ColaLigada() {}

string ColaLigada::Consultar() {
  if (inicio == NULL)
    return "-1";
  string extraido = inicio->dato;
  return extraido;
}

string ColaLigada::Extraer() {
  if (inicio == NULL)
    return "-1";
  Frase *nodo = inicio;

  string extraido = nodo->dato;
  inicio = nodo->sig;
  if (inicio == NULL)
    final = NULL;
  delete nodo;
  return extraido;
}

void ColaLigada::Insertar(string nuevoDato) {
  Frase *nodo = new Frase; // nodo nuevo
  nodo->dato = nuevoDato;  // datos del nuevo nodo
  nodo->sig = NULL;        // ultimo nodo apunta a Null
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
  Frase *nodo = inicio;
  do {
    string str = nodo->dato;
    if (str.empty()) {
      str = "\"\"";
    }
    cout << "\t" << str;
    if (inicio == nodo)
      cout << " <== inicio";
    if (final == nodo)
      cout << " <== final";
    cout << endl;
    nodo = nodo->sig;
  } while (nodo != NULL);
}
