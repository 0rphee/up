#include <iostream>

// ejemplo de operadores relacionales

int main(){

    bool uno = true;
    bool dos = false;
	std::cout << "Operadores lógicos\nuno: "<< uno  << std::endl;
	std::cout << "dos: "<< dos  << std::endl;
	std::cout << "and: "<< (uno && dos)  << std::endl;
	std::cout << "or: " << (uno || dos)  << std::endl;
	std::cout << "not uno: " << uno  << std::endl;

    int nuno = 3244;
    int ndos = 34529;
	std::cout << "Operadores de comparación\nuno: "<< nuno  << std::endl;
	std::cout << "dos: "<< ndos  << std::endl;
	std::cout << "<: "<< (nuno < ndos)  << std::endl;
	std::cout << ">: " << (nuno > ndos)  << std::endl;
	std::cout << "<=: " << (nuno <= ndos)  << std::endl;
	std::cout << ">=: " << (nuno >= ndos)  << std::endl;
	std::cout << "==: " << (nuno == ndos)  << std::endl;
	std::cout << "!=: " << (nuno != ndos)  << std::endl;
	return 0;
}



