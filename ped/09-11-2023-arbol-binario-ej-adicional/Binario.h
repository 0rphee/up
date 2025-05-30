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

  void RecorrerINorden(Nodo *);
  void RecorrerPREorden(Nodo *);
  void RecorrerPOSorden(Nodo *);

  Nodo *Buscar(Nodo *, int);

  void Mostrar(Nodo *, int);

private:
  Nodo *raiz;
  Nodo *nodo;
};

void mostrarValor(int);
