#include <iostream>

int main(){
  unsigned char numero {128}; //1000000|
  std::cout << "corrimiento izq de 1: " << (numero << 1) << std::endl;
  std::cout << "corrimiento izq de 2: " << (numero << 2) << std::endl;
  std::cout << "corrimiento izq de 7: " << (numero << 7) << std::endl;

  std::cout << "corrimiento derecha de 1: " << (numero << 1) << std::endl;
  std::cout << "corrimiento derecha de 2: " << (numero << 2) << std::endl;
  std::cout << "corrimiento derecha de 7: " << (numero << 7) << std::endl;
  return 0;  
}

