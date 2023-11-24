#include <iostream>
#include <string>

using namespace std;

class MatrizAdy {
public:
  MatrizAdy(int);

  int InsertarNodo(char);
  int InsertarArco(char, char, int);
  void Mostrar();

private:
  int BuscarNodo(char);
  char *nodos;
  int **arcos;
  int maxNodos, ocupados;
};

// void mostrarValor(int);
