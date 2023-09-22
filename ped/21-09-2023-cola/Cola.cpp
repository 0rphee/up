#include "Cola.h"
#include <cstdio>
#include <iostream>

Cola::Cola() {
  min = 0;
  max = TAM - 1;
  inicio = -1;
  final = -1;
}
Cola::~Cola() {}

string Cola::Extraer() {
  string extraido;
  // checar si hay valores en la cola
  if (final < min && inicio < min) {
    return "-1";
  }
  if (inicio > final) {
    return "-1";
  }
  // extrear valor de inicio
  extraido = arreglo[inicio];
  arreglo[inicio] = "";
  // incrementar valor de inicio
  inicio++;
  return extraido;
}

int Cola::Insertar(string nuevoDato) {
  // verificar si hay capacidad
  if (final == max) {
    return -1;
  }
  // incrementar valor de final
  final++;
  if (inicio == -1) {
    inicio++;
  }
  arreglo[final] = nuevoDato;

  return 0;
}

void Cola::Mostrar() {
  cout << "Cola: " << endl;
  cout << "inicio=" << inicio << "; final=" << final << "; min=" << min
       << "; max=" << max << endl;
  for (int i = TAM - 1; i >= 0; i--) {
    string str = arreglo[i];
    if (str == "") {
      str = "\"\"";
    }
    cout << "\t" << str;
    if (final == i)
      cout << " <== final";
    if (inicio == i)
      cout << " <== inicio";
    if (min == i)
      cout << " <== min";
    if (max == i)
      cout << " <== max";
    cout << endl;
  }
}
