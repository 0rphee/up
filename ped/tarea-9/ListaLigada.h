#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Nodo {
  int dato;
  Nodo *sig;
} Nodo;

class ListaLigada {

public:
  ListaLigada();
  ~ListaLigada();

  void InsertarInicio(int);
  void InsertarAscendente(int);
  int InsertarFinal(int);
  void Mostrar();
  int Extraer();

private:
  Nodo *cabecera, *final;

protected:
};

void mostrarValor(int);
