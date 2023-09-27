#include "ColaCircular.h"

ColaCircular::ColaCircular(int tam) {
  min = 0;
  max = tam - 1;
  inicio = -1;
  final = -1;
  arr = new string[tam];
  for (int i = min; i <= max; i++) {
    arr[i] = "- -";
  }
}
ColaCircular::~ColaCircular() {}

string ColaCircular::Consultar() {
  string extraido;
  // checar si hay valores en la cola
  if (inicio < min && final < min) {
    return "-1"; // cola vacia
  }
  // extrear valor de inicio
  extraido = arr[inicio];

  return extraido;
}

string ColaCircular::Extraer() {
  string extraido;
  // checar si hay valores en la cola
  if (inicio < min && final < min) {
    return "-1"; // cola vacia
  }
  // extrear valor de inicio
  extraido = arr[inicio];
  arr[inicio] = "- -";

  // incrementar valor de inicio
  if (final == inicio) {
    // inicio = final = -1; // circular, se extrajo el último elemento
    return "-1";
  }
  inicio++;
  if (inicio > max) { // si inicio sobrepasa máximo, regresa a mínimo
    inicio = min;
  }
  return extraido;
}

int ColaCircular::Insertar(string nuevoDato) {
  // verificar si hay capacidad
  if ((final + 1) == inicio)
    return -1; // circular, la cola está llena
  if (inicio == min && final == max)
    return -1; // la cola está llena

  // incrementar valor de final
  final++;
  // solo la primera inserción
  if (inicio == -1)
    inicio++;
  if (final > max)
    final = min; // circular, final regresa a mínimo

  arr[final] = nuevoDato;
  return 0;
}

void ColaCircular::Mostrar() {
  cout << "Cola: " << endl;
  cout << "inicio=" << inicio << "; final=" << final << "; min=" << min
       << "; max=" << max << endl;
  for (int i = max; i >= 0; i--) {
    string str = arr[i];
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
