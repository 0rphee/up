MAURO ROGELIO GALINDO IBARRA 0250061
#include <iostream>

namespace lib{

inline int max(int arr[], int arrLen){
    int max = arr[0];
    for (int i {0}; i < arrLen; i++){
        printf("index %d, val %d\n", i, arr[i]);
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}


}
