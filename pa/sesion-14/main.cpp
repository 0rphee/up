#include <iostream>
#include <bitset>
#include <ostream>
#include <string>

union Chars {
    char chars[17] = "abcdefghijklmnop";
    int ints[4];
};




int main(){
    Chars miUnion;

    // printf("Ingrese 16 caracteres\n");
    // std::cin >> miUnion.chars;

    for (int i {0}; i < 4; i++){
        char primer  = (miUnion.ints[i] >> (8*0)) & 0xff;
        char segundo = (miUnion.ints[i] >> (8*1)) & 0xff;
        char tercero = (miUnion.ints[i] >> (8*2)) & 0xff;
        char cuarto  = (miUnion.ints[i] >> (8*3)) & 0xff;

        std::cout << primer << segundo << tercero << cuarto << " = " << miUnion.ints[i] <<std::endl;
    }

    for (int i {0}; i < 16; i++){
        ;
        std::cout << miUnion.chars[i] << " = " << std::bitset<8> (miUnion.chars[i]) <<std::endl;
    }
   
    return 0;
}





