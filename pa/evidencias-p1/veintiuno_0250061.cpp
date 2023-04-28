// Programa que cuenta la frecuencia de un carácter en una
// cadena de máximo cien caracteres introducida por el usuario.

#include <iostream>
using namespace std;

int main(){
    char cadena[100];
    char caracter;
    int frecuencia = 0;
    int i = 0;
    
    cout << "Introduce una cadena de máximo 100 caracteres: ";
    cin.getline(cadena, 100);
    
    cout << "Introduce el caracter a buscar: ";
    cin >> caracter;
    
    while(cadena[i] != '\0'){
        if(cadena[i] == caracter){
            frecuencia++;
        }
        i++;
    }
    
    cout << "El caracter " << caracter << " aparece " << frecuencia << " veces." << endl;
    
    return 0;
}