#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Nodo {
  int dato;
  Nodo *sig;
} Nodo;

class ListaLigadaCircular {

public:
  ListaLigadaCircular();
  ~ListaLigadaCircular();

  void InsertarFinal(int);

  void Mostrar(bool);
  bool Buscar(int);

private:
  Nodo *cabecera, *final, *ultimoVisitado;

protected:
};

void mostrarValor(int);
