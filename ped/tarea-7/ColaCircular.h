#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct {
  string nombre;
  int numeroBoletos;
} Comprador;

class ColaCircular {

public:
  ColaCircular(int);
  ~ColaCircular();

  Comprador Consultar();
  Comprador Extraer();
  int Insertar(Comprador);
  void Mostrar();

private:
  Comprador *arr;
  int min;
  int max;
  int inicio;
  int final;

protected:
};

void mostrarComprador(Comprador);
