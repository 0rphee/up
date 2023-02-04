#include <iostream>
#include <cmath>

bool isPrime(int n){
    for (int i = 2; i <= rint(sqrt(n)); i++ ){
        if (rint(n % i )== 0){
            return false;
        }
    }
    return true;
}


void list(int n){
    for (int i = 0; i < n; i++){
        if (isPrime(i)){
            std::cout << std::to_string(i) + " es primo" << std::endl;
        } else {
            std::cout << std::to_string(i) + " no es primo" << std::endl;
    }
    }

}

int main(){
    printf("Dame el número: ");

    int num {0};
    std::cin >> num;

    std::string resultMsg;

    if (isPrime(num)){
        resultMsg = std::to_string(num) + " es primo";
    } else {
        resultMsg = std::to_string(num) + " no es primo";
    }

    std::cout << resultMsg << std::endl << std::endl;  

    // list(100);

    return 0;
}



