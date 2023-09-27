#include "ColaCircular.h"

ColaCircular::ColaCircular(int tam) {
  min = 0;
  max = tam - 1;
  inicio = -1;
  final = -1;
  arr = new Comprador[tam];
  for (int i = min; i <= max; i++) {
    arr[i].nombre = "- -";
    arr[i].numeroBoletos = 0;
  }
}
ColaCircular::~ColaCircular() {}

Comprador ColaCircular::Consultar() {
  Comprador extraido;
  // checar si hay valores en la cola
  if (inicio < min && final < min) {
    return {"", -1}; // cola vacia
  }
  // extrear valor de inicio
  extraido = arr[inicio];

  return extraido;
}

Comprador ColaCircular::Extraer() {
  Comprador extraido;
  // checar si hay valores en la cola
  if (inicio < min && final < min) {
    return {"", -1}; // cola vacia
  }
  // extrear valor de inicio
  extraido = arr[inicio];
  arr[inicio] = {"- -", 0};

  // incrementar valor de inicio
  if (final == inicio) {
    if (extraido.nombre != "- -" && extraido.numeroBoletos != 0)
      return extraido;
    // inicio = final = -1; // circular, se extrajo el último elemento
    return {"", -1};
  }
  inicio++;
  if (inicio > max) { // si inicio sobrepasa máximo, regresa a mínimo
    inicio = min;
  }
  return extraido;
}

int ColaCircular::Insertar(Comprador nuevoDato) {
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
  cout << "----------------------------------------------------\n\t"
       << "Cola: "
       << "inicio=" << inicio << "; final=" << final << "; min=" << min
       << "; max=" << max << endl
       << endl;
  ;
  for (int i = max; i >= 0; i--) {
    Comprador comprador = arr[i];
    if (comprador.nombre == "") {
      comprador = {"- -", 0};
    }
    mostrarComprador(comprador);
    cout << '\t';
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
  cout << "----------------------------------------------------\n";
}

void mostrarComprador(Comprador comprador) {
  cout << "\n\tNombre: " << comprador.nombre
       << "\n\tNúm. boletos: " << comprador.numeroBoletos;
}
