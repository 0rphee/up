#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Nodo {
  string dato;
  Nodo *sig;
} Nodo;

class ListaLigada {

public:
  ListaLigada();
  ~ListaLigada();

  void InsertarInicio(string);
  int InsertarInter(string, string);
  int InsertarFinal(string);
  void Mostrar();

private:
  Nodo *cabecera, *final;

protected:
};

void mostrarValor(string);
