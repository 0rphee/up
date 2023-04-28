MAURO ROGELIO GALINDO IBARRA 0250061
#include <iostream>

namespace lib{

inline int min(int arr[], int arrLen){
    int min = arr[0];
    for (int i {0}; i < arrLen; i++){
        printf("index %d, val %d\n", i, arr[i]);
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}


}
