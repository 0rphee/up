#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct Frase {
  string dato;
  Frase *sig;
} Frase;

class ColaLigada {

public:
  ColaLigada();
  ~ColaLigada();

  string Consultar();
  string Extraer();
  void Insertar(string);
  void Mostrar();

private:
  Frase *inicio, *final;

protected:
};
