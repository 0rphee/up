#include <iostream>
#define RENG 10
#define COL 10

using namespace std;

int **arr;

void Mostrar() {
  int aux = 0;
  for (int i = 0; i < RENG; i++) {
    for (int j = 0; j < COL; j++) {
      aux += arr[i][j];
    }
  }
}

void Mostrar2() {
  int aux = 0;
  for (int i = 0; i < RENG; i++) {
    for (int j = 0; j < COL; j++) {
      aux *= *(*(arr + i) + j);
    }
  }
}

int main() {

  arr = new int *[RENG];
  for (int c = 0; c < RENG; c++) {
    arr[c] = new int[COL];
  }

  for (int i = 0; i < RENG; i++) {
    for (int j = 0; j < COL; j++) {
      arr[i][j] = i + j;
    }
  }

  Mostrar();
  Mostrar2();
}
