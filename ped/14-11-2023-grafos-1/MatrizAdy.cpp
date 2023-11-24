#include "MatrizAdy.h"
#include <cstddef>
#include <cstdlib>

MatrizAdy::MatrizAdy(int tam) {
  maxNodos = tam;
  ocupados = 0;
  nodos = new char[tam];  // arreglo de nodos
  arcos = new int *[tam]; // renglones del arreglo de arcos

  for (int i = 0; i < tam; i++) {
    arcos[i] = new int[tam]; // columnas de cada renglon de arcos
    nodos[i] = '=';          // inicializa arreglo de nodos

    for (int j = 0; j < tam; j++)
      arcos[i][j] = -1; // inicializa adyacencias vacías
  }
}

void MatrizAdy::Mostrar() {
  cout << "\nMATRIZ DE ADYACENCIAS\n\n\t";

  for (int i = 0; i < maxNodos; i++) { // encabezado de columnas
    cout << "\t" << nodos[i];
  }
  cout << endl;

  for (int i = 0; i < maxNodos; i++) {
    cout << "\t" << nodos[i]; // nodo de cada renglon
    for (int j = 0; j < maxNodos; j++) {
      if (arcos[i][j] != -1)
        cout << "\t" << arcos[i][j]; // adyacencias de cada renglon
      else
        cout << "\t-"; // adyacencia vacia
    }
    cout << endl;
  }
}

int MatrizAdy::InsertarNodo(char nuevo) {
  if (ocupados == maxNodos) // arreglo lleno. No insertamos
    return -1;

  if (ocupados == 0) { // grafo vacío, se inserta el nodo
    nodos[ocupados] = nuevo;
    ocupados++;
    return 0;
  }

  if (BuscarNodo(nuevo) != -1) // ya existe el nodo. no se inserta
    return -2;

  nodos[ocupados] = nuevo; // se insertó el nodo
  ocupados++;
  return 0;
}

int MatrizAdy::InsertarArco(char nodoOrigen, char nodoDestino, int peso) {
  if (ocupados == 0) // Grafo vacío. No existen nodos. NO se insertó el arco
    return -1;

  int posOrig = BuscarNodo(nodoOrigen);
  int posDes = BuscarNodo(nodoDestino);

  if (posOrig == -1 ||
      posDes == -1) // No existe origen o destino. NO se inserta
    return -2;

  if (arcos[posOrig][posDes] != -1) { // Ya existe el arco, se modifica el peso
    arcos[posOrig][posDes] = peso;
    arcos[posDes][posOrig] = peso; // se modifica arco bidireccional
    return -3;
  } else { // no existe el arco, se inserta
    arcos[posOrig][posDes] = peso;
    arcos[posDes][posOrig] = peso; // se inserta arco bidireccional
    return 0;
  }
}

int MatrizAdy::BuscarNodo(char buscado) {
  for (int i = 0; i < ocupados; i++) {
    if (nodos[i] == buscado)
      return i;
  }
  return -1;
}

// void mostrarValor(int valor) { cout << "\t\tDato: " << valor; }
