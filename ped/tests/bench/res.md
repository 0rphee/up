``` cpp
const int RENG = 1000; // Adjust these values as needed
const int COL = 1000;
const int NUM_RUNS = 10000; // Number of times to run each function
```


# Mostrar

```cpp
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
```

Average Mostrar  duration: 0.000963647 seconds

Average Mostrar2 duration: 0.000966822 seconds
