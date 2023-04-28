// Programa que valida si número es par o impar
#include <iostream>
using namespace std;

void mPrint(string text){
  cout << text << endl;
}

int main(){
  int num {0};
  mPrint("Ingrese un número entero");
  cin >> num;

  if (num % 2 == 0){
    mPrint("El número es par");
  } else {
    mPrint("El número es impar");
  }
  
  return 0;
}


