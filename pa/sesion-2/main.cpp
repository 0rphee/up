#include <iostream>

int main(){

  int numeroUno = 0, numeroDos = 0;
  float resultado = 0;

  std::cout << "introduzca un numero entero" << std:: endl;
  std::cin >> numeroUno;
  std::cout << "\nintroduzca un numero entero" << std::endl;
  std::cin >> numeroDos;

  // suma
  resultado = numeroUno + numeroDos;
  std::cout << "suma: " << resultado << std::endl; 

  // resta
  resultado = numeroUno - numeroDos;
  std::cout << "resta: " << resultado << std:: endl;

  // mult
  resultado = numeroUno * numeroDos;
  std::cout << "mul: " << resultado << std::endl;

  // div
  resultado = (float) numeroUno / numeroDos;
  std::cout << "div " << resultado << std::endl;

  // suma
  resultado = numeroUno % numeroDos;
  std::cout << "mod" << resultado << std:: endl; 

  return 0;
  
}
