#include <chrono>
#include <iostream>

const int RENG = 1000; // Adjust these values as needed
const int COL = 1000;
const int NUM_RUNS = 10000; // Number of times to run each function

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
      aux += *(*(arr + i) + j);
    }
  }
}

double benchmarkFunction(void (*func)()) {
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < NUM_RUNS; i++) {
    func();
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  return duration.count() / NUM_RUNS;
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

  // Benchmark Mostrar
  double averageDuration1 = benchmarkFunction(Mostrar);

  // Benchmark Mostrar2
  double averageDuration2 = benchmarkFunction(Mostrar2);

  // Print the average execution times
  std::cout << "Average Mostrar duration: " << averageDuration1 << " seconds"
            << std::endl;
  std::cout << "Average Mostrar2 duration: " << averageDuration2 << " seconds"
            << std::endl;

  // Clean up memory
  for (int i = 0; i < RENG; i++) {
    delete[] arr[i];
  }
  delete[] arr;

  return 0;
}
