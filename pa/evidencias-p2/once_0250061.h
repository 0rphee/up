#include <iostream>
#include <string>
using namespace std;

// Ejercicio referencia con estructuras
namespace once{
    struct Persona {
      string nombre;
      int edad;
    };

    void cambiarPersona(Persona &p, string nuevoNombre, int nuevaEdad) {
      p.nombre = nuevoNombre;
      p.edad = nuevaEdad;
    }

    int main() {
      Persona persona;
      printf("Ingrese el nombre inicial de la persona: ");
      cin >> persona.nombre; cout << endl;

      printf("Ingrese la edad inicial de la persona: ");
      cin >> persona.edad; cout << endl;

      cout << "La persona se llama " << persona.nombre << " y tiene " << persona.edad << " años\n";

      string nNombre;
      int nEdad;

      printf("Ingrese el nuevo nombre de la persona: ");
      cin >> nNombre; cout << endl;

      printf("Ingrese la nueva edad de la persona: ");
      cin >> nEdad; cout << endl;
      
      cambiarPersona(persona, nNombre, nEdad);
      cout << "La persona ahora se llama " << persona.nombre << " y tiene " << persona.edad << " años\n";
      return 0;
    }

}

