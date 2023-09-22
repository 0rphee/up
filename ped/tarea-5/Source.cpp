#include "PilaDinamica.cpp"
#include "PilaDinamica.h"
#include <iostream>
#include <string>

// Después de algunas pruebas, parece que la implementación del algoritmo es
// correcta, sin embargo, la especificación del algoritmo parece estar
// incorrecta, ejemplos como "(1+2)*3", dejan un uso de paréntesis aparentemente
// erróneo
int precedencia(char c) {
  switch (c) {
  case '/':
    return 2;
    break;
  case '*':
    return 2;
    break;
  case '+':
    return 1;
    break;
  case '-':
    return 1;
  case ')':
    return 0;
    break;
  default:
    return 4;
    break;
  }
}
bool isOperator(char c) {
  return (c == '*') || (c == '+') || (c == '-') || (c == '/');
}

int main() {
  Pila pilaOperadores = Pila();
  int opc;
  string cadenaInfija, cadenaPostfija;

  do {
    cout << "\n1. Insertar cadena inicial\n2. Ejecutar cambio a postfijo\n3. "
            "Mostrar string inicial y final\n4. Salir\n> ";
    cin >> opc;
    switch (opc) {
    case 1:
      cout << "\nEscribe la cadena inicial a pasar de notación infija a "
              "postfija: ";
      cin >> cadenaInfija;
      cout << endl;
      break;
    case 2:
      for (int i = 0; i < cadenaInfija.size(); i++) {
        char nextStringChar = cadenaInfija[i];
        if (isOperator(nextStringChar)) {
          char topOperator = pilaOperadores.Consultar();
          // Si la pila está vacía regresa 99
          if (topOperator != 99) {
            if (precedencia(nextStringChar) > precedencia(topOperator)) {
              // si es de mayor precedencia que el del tope se inserta a la
              // pila
            } else {
              // si es de menor o igual, se extraen todos los de mayor
              // precedencia en la pila concatenándolos en cadena posfija y
              // luego se inserta en la pila
              do {
                topOperator = pilaOperadores.Consultar();

                // Si la pila está vacía regresa 99
                if (topOperator != 99) {

                  // si se cumple la condicion de precedencia, se remueve de la
                  // pila  el útlimo operador y se añade al string postfijo
                  if (precedencia(nextStringChar) < precedencia(topOperator)) {
                    topOperator = pilaOperadores.Extraer();
                    cadenaPostfija.push_back(topOperator);
                  }
                }
              } while (precedencia(nextStringChar) < precedencia(topOperator) &&
                       topOperator != 99);
            }
          }
          // al final se inserta en la pila
          pilaOperadores.Insertar(nextStringChar);
        } else if (nextStringChar == '(') {
          // Si es Paréntesis izquierdo, se inserta en la pila (se considera de
          // precedencia 0)
          pilaOperadores.Insertar(nextStringChar);
        } else if (nextStringChar == ')') {
          // Si es Paréntesis derecho, se extraen repetidamente todos los de la
          // pila, concatenándolos a la cadena posfija, hasta encontrar un
          // paréntesis izquierdo
          char topOperator;
          do {
            topOperator = pilaOperadores.Consultar();
            // mientras no se encuentre un paréntesis izquierdo, se quitan los
            // operadores de la pila y pasan al string postfijo
            if ((topOperator != '(') && (topOperator != 99)) {
              topOperator = pilaOperadores.Extraer();
              cadenaPostfija.push_back(topOperator);
            }

          } while ((topOperator != '(') && !pilaOperadores.EstaVacia());
          // después de haber vaciado la pila, se agrega el paréntesis
          cadenaPostfija.push_back(nextStringChar);
        } else {
          // si es variable o constante la añade al segundo string
          // inmediatamente

          cadenaPostfija.push_back(nextStringChar);
        }
      }
      // Al terminar cadena infija, se vacía la pila, insertando a posfija
      char c;
      do {
        c = pilaOperadores.Extraer();
        if (c != 99) {
          cadenaPostfija.push_back(c);
        }
      } while (c != 99);

      break;
    case 3:
      cout << "String inicial:\n\t" << cadenaInfija << endl;
      cout << "String final:\n\t" << cadenaPostfija << endl;
      pilaOperadores.Mostrar();
      break;
    case 4:
      cout << "\n\t\t\t** FIN DE LA APLICACIÓN **" << endl;
      break;

    default:
      cout << "\n\t\t\t** OPCIÓN INVÁLIDA **" << endl;
      break;
    }
  } while (opc != 4);

  return 0;
}
