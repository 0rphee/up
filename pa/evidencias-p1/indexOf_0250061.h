MAURO ROGELIO GALINDO IBARRA 0250061

#ifndef LIB
#define LIB

#include <iostream>

namespace lib{
	 inline int indexOf(const char* palabra, char letra){
		for (int i = 0; i < 100; i++){
			if (palabra[i] == letra){
				return i;
			}
		} 
        return -1;
    }
}

#endif
