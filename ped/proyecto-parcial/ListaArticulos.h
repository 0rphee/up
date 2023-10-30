#include <iostream>
#include <string>

using namespace std;

struct Articulo {
  string nombreArticulo;
  string proveedorArticulo;

  bool operator==(const Articulo &other) const {
    return nombreArticulo == other.nombreArticulo &&
           proveedorArticulo == other.proveedorArticulo;
  }

  bool operator!=(const Articulo &other) const {
    return nombreArticulo != other.nombreArticulo ||
           proveedorArticulo != other.proveedorArticulo;
  }
};

struct NodoArticulo {
  Articulo dato;
  NodoArticulo *sig;
  NodoArticulo *prev;
};

class ListaArticulo {
public:
  ListaArticulo();
  ~ListaArticulo();

  string nombreLista;
  int GetCantidadNodos();

  Articulo ExtraerInicio();
  Articulo ExtraerFinal();
  Articulo ExtraerMedio(Articulo);
  Articulo ExtraerEnIndice(
      int); // la cabecera es indice = 0. El final es el indice máximo

  void InsertarInicio(Articulo);
  void InsertarFinal(Articulo);
  bool InsertarMedio(Articulo, Articulo);

  void MostrarIniFin();
  void MostrarFinIni();

private:
  NodoArticulo *cabecera;
  NodoArticulo *final;
  int cantidadNodos;
};

void mostrarArticulo(Articulo);
