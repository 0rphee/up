#include "ListaArticulos.cpp"
#include "ListaTrabajadores.cpp"
#include <iostream>
#include <string>

using namespace std;

struct Combinada {
  Trabajador trabajador;
  Articulo articulo;

  bool operator==(const Combinada &other) const {
    return trabajador.nombreTrabajador == other.trabajador.nombreTrabajador;
  }

  bool operator!=(const Combinada &other) const {
    return trabajador.nombreTrabajador != other.trabajador.nombreTrabajador;
  }
};

struct NodoCombinada {
  Combinada dato;
  NodoCombinada *sig;
  NodoCombinada *prev;
};

class ListaCombinada {
public:
  ListaCombinada();
  ~ListaCombinada();

  string nombreLista;
  int GetCantidadNodos();
  Combinada ConsultaTrabajador(string);

  Combinada ExtraerInicio();
  Combinada ExtraerFinal();
  Combinada ExtraerMedio(Combinada);
  Combinada ExtraerEnIndice(
      int); // la cabecera es indice = 0. El final es el indice máximo

  void InsertarInicio(Combinada);
  void InsertarFinal(Combinada);
  bool InsertarMedio(Combinada, Combinada);

  void MostrarIniFin();
  void MostrarFinIni();

private:
  NodoCombinada *cabecera;
  NodoCombinada *final;
  int cantidadNodos;
};

void mostrarCombinada(Combinada);
