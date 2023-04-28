
#include <iostream>
// Ejercicio de copia de datos de un puntero:

namespace doce{
    int *crearArreglo(int tamano) {
      int *arr = new int[tamano];
      for (int i = 0; i < tamano; i++) {
        arr[i] = i + 1;
      }
      return arr;
    }

    int *copiarArreglo(int *arr, int tamano) {
      int *copia = new int[tamano];
      for (int i = 0; i < tamano; i++) {
        copia[i] = arr[i];
      }
      return copia;
    }

    int main() {
      int tamano = 5;
      int *arreglo = crearArreglo(tamano);
      int *copia = copiarArreglo(arreglo, tamano);
      for (int i = 0; i < tamano; i++) {
        std::cout << "Arreglo[" << i << "] = " << arreglo[i] << std::endl;
        std::cout << "Copia[" << i << "] = " << copia[i] << std::endl;
        }
    delete[] arreglo;
    delete[] copia;
    return 0;
    }

}
