#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Nodo {
  string dato;
  Nodo *sig;
} Nodo;

class ListaLigadaCircular {

public:
  ListaLigadaCircular();
  ~ListaLigadaCircular();

  void InsertarInicio(string);
  void InsertarFinal(string);

  string ExtraerEn(int);
  bool ExtraerImpares();

  void Mostrar();
  int GetTamano();

private:
  Nodo *cabecera, *final;
  int numNodos;

protected:
};

void mostrarValor(string, int);
