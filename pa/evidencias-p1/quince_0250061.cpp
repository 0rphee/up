// Programa que cuenta la frecuencia de los caracteres en una
// cadena de máximo cien caracteres introducida por el usuario.

#include <iostream>
using namespace std;

int main(){
    char cadena[100];
    int frecuencia[256] = {0};
    int i = 0;
    
    cout << "Introduce una cadena de máximo 100 caracteres: ";
    cin.getline(cadena, 100);
    
    while(cadena[i] != '\0'){
        frecuencia[cadena[i]]++;
        i++;
    }
    
    for(int i = 0; i < 256; i++){
        if(frecuencia[i] > 0){
        cout << "El caracter " << (char) i << " aparece " << frecuencia[i] << " veces." << endl;
        }
    }
    
    return 0;
}
