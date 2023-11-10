#include "Binario.h"

Binario::~Binario() {}

Binario::Binario() { raiz = NULL; }

Nodo *Binario::ConsultarRaiz() { return raiz; }

void Binario::CrearNodo(int valor) {
  nodo = new Nodo;
  nodo->dato = valor;
  nodo->izq = NULL;
  nodo->der = NULL;
}

void Binario::Insertar(Nodo *inicio) {
  // POSIBILIDAD 1: arbol vacio, se inserta raiz
  if (!raiz) {
    raiz = nodo;
    cout << "SE INSERTÓ EN LA RAIZ" << endl;
    // POSIBILIDAD 2: menor, se inserta a la izquierda
  } else if (nodo->dato < inicio->dato) {
    if (inicio->izq == NULL) {
      inicio->izq = nodo;
      cout << "SE INSERTO A LA IZQUIERDA DE " << inicio->dato << endl;
    } else {
      Insertar(inicio->izq);
    }
    // POSIBILIDAD 2: mayor, se inserta a la derecha
  } else if (nodo->dato > inicio->dato) {
    if (inicio->der == NULL) {
      inicio->der = nodo;
      cout << "SE INSERTO A LA DERECHA DE " << inicio->dato << endl;
    } else {
      Insertar(inicio->der);
    }
  } else {
    // POSIBILIDAD 3: es igual, no se inserta
    cout << "YA EXISTE " << nodo->dato << " EN EL ARBOL, NO SE INSERTA" << endl;
    delete nodo;
  }
}

void Binario::RecorrerINorden(Nodo *inicio) {
  if (inicio->izq != NULL)
    RecorrerINorden(inicio->izq);
  cout << "\t" << inicio->dato << endl;
  if (inicio->der != NULL)
    RecorrerINorden(inicio->der);
}

void Binario::RecorrerPREorden(Nodo *inicio) {
  cout << "\t" << inicio->dato << endl;
  if (inicio->izq != NULL)
    RecorrerINorden(inicio->izq);
  if (inicio->der != NULL)
    RecorrerINorden(inicio->der);
}

void Binario::RecorrerPOSorden(Nodo *inicio) {
  if (inicio->izq != NULL)
    RecorrerINorden(inicio->izq);
  if (inicio->der != NULL)
    RecorrerINorden(inicio->der);
  cout << "\t" << inicio->dato << endl;
}
void mostrarValor(int valor) { cout << "\t\tDato: " << valor; }
