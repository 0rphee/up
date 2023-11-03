#include <iostream>
#include <string>

using namespace std;

typedef struct Nodo {
  Nodo *izq;
  int dato;
  Nodo *der;
} Nodo;

class Binario {
public:
  Binario();
  ~Binario();

  Nodo *ConsultarRaiz();

  void CrearNodo(int);
  void Insertar(Nodo *);

private:
  Nodo *raiz;
  Nodo *nodo;
};

void mostrarValor(int);
