#include <iostream>
#include <string>

using namespace std;

typedef struct Nodo {
  string dato;
  Nodo *sig;
  Nodo *prev;
} Nodo;

class ListaDobleEnlace {
public:
  ListaDobleEnlace();
  ~ListaDobleEnlace();

  string ExtraerInicio();
  string ExtraerFinal();
  string ExtraerMedio(string);

  void InsertarInicio(string);
  void InsertarFinal(string);
  bool InsertarMedio(string, string);

  void MostrarIniFin();
  void MostrarFinIni();

private:
  Nodo *cabecera;
  Nodo *final;
};

void mostrarValor(string);
