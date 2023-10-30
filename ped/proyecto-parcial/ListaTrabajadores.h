#include <iostream>
#include <string>

using namespace std;

struct Trabajador {
  string nombreTrabajador;
  string departamentoTrabajador;

  bool operator==(const Trabajador &other) const {
    return nombreTrabajador == other.nombreTrabajador &&
           departamentoTrabajador == other.departamentoTrabajador;
  }

  bool operator!=(const Trabajador &other) const {
    return nombreTrabajador != other.nombreTrabajador ||
           departamentoTrabajador != other.departamentoTrabajador;
  }
};

struct NodoTrabajador {
  Trabajador dato;
  NodoTrabajador *sig;
  NodoTrabajador *prev;
};

class ListaTrabajador {
public:
  ListaTrabajador();
  ~ListaTrabajador();

  string nombreLista;
  int GetCantidadNodos();

  Trabajador ExtraerInicio();
  Trabajador ExtraerFinal();
  Trabajador ExtraerMedio(Trabajador);
  Trabajador ExtraerEnIndice(
      int); // la cabecera es indice = 0. El final es el indice máximo

  void InsertarInicio(Trabajador);
  void InsertarFinal(Trabajador);
  bool InsertarMedio(Trabajador, Trabajador);

  void MostrarIniFin();
  void MostrarFinIni();

private:
  NodoTrabajador *cabecera;
  NodoTrabajador *final;
  int cantidadNodos;
};

void mostrarTrabajador(Trabajador);
