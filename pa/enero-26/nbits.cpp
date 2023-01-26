#include <iostream>

int main(){
	unsigned char numero {5};

	unsigned char numeroDos {11};
	std::cout << "and: " << (numero & numeroDos) << std::endl;
	return 0;
}
