#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Turno {
  string nombreTurno;
} Turno;

typedef struct Nodo {
  Turno dato;
  Nodo *sig;
} Nodo;

class ColaLigada {

public:
  ColaLigada();
  ~ColaLigada();

  Turno Consultar();
  Turno Extraer();
  void Insertar(Turno);
  void Mostrar();

private:
  Nodo *inicio, *final;

protected:
};

void mostrarTurno(Turno);
