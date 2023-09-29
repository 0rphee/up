#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Trailer {
  string placas;
  string producto;
} Trailer;

typedef struct Nodo {
  Trailer dato;
  Nodo *sig;
} Nodo;

class ColaLigada {

public:
  ColaLigada();
  ~ColaLigada();

  Trailer Consultar();
  Trailer Extraer();
  void Insertar(Trailer);
  void Mostrar();

private:
  Nodo *inicio, *final;

protected:
};

void mostrarTrailer(Trailer);
