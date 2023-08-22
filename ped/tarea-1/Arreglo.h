#pragma once
#include <iostream>
#include <string>

#define TAM 10

using namespace std;

class Arreglo {

public:
  Arreglo();
  ~Arreglo();

  void OrdenarEnteros();
  void MostrarEnteros();

  void OrdenarStrings();
  void MostrarStrings();

private:
  int enteros[TAM]{6, 5, 2, 1, 3};
  std::string arrStrings[TAM] = {"Rogelio", "Pedro", "Juan", "Fernando",
                                 "Roberto"};

protected:
};
