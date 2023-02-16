
#ifndef LIB
#define LIB

#include <iostream>

namespace lib{
	 inline int indexOf(std::string palabra, char letra){
		for (int i = 0; i < sizeof(palabra); i++){
			if (palabra[i] == letra){
				return i;
			}
		} 
        return -1;
    }
}

#endif
