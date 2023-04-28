
#include <iostream>
// Ejercicio de copia de datos de un puntero:

namespace doce{
    int main(){
      int* p = new int;
      int* p2 = new int;
      *p = 10;
      printf("Valor de primer puntero: %d\n", *p);
      *p2 = *p;
      printf("Valor de segundo puntero: %d\n", *p2);
    return 0;
    }

}
