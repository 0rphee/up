
#include <iostream>

namespace aritmetica{

	inline int suma(int a, int b) { return a + b;}
	inline int resta(int a, int b) { return a - b;}
	inline int multiplicacion(int a, int b) { return a * b;}
	inline double division(double a, double b) { return a / b;}
	inline int modulo(int a, int b) { return a % b;}

	inline int enterInt(const char textoAMostrar[]){
	    printf("%s\n", textoAMostrar);

	    int temp;

	    std::cin >> temp;

	    return temp;
	 }
	inline double enterDouble(const char textoAMostrar[]){
	    printf("%s\n", textoAMostrar);

	    double temp;

	    std::cin >> temp;

	    return temp;
	 }

	inline void aritmetica(){
		int opc = enterInt("1 - Suma\n2 - Resta\n3 - Multiplicación\n4 - División\n5 - Módulo\nIngrese la opción que desee");
		int res {0};
		double d {0};
		switch (opc){
			case 1:
				res = suma(enterInt("Ingrese el primer número:"), enterInt("Ingrese el segundo número:"));
				printf("El resultado es: %d\n",res);
				break;
			case 2:
				res = resta(enterInt("Ingrese el primer número:"), enterInt("Ingrese el segundo número:"));
				printf("El resultado es: %d\n",res);
				break;
			case 3:
				res = multiplicacion(enterInt("Ingrese el primer número:"), enterInt("Ingrese el segundo número:"));
				printf("El resultado es: %d\n",res);
				break;
			case 4:
				d = division(enterDouble("Ingrese el primer número:"), enterDouble("Ingrese el segundo número:"));
				printf("El resultado es: %f\n",d);
				break;
			case 5:
				res = modulo(enterInt("Ingrese el primer número:"), enterInt("Ingrese el segundo número:"));
				printf("El resultado es: %d\n",res);
				break;
			default:
				printf("No se ingresó una opción válida, se regresa al menú principal\n");
				break;
		}
		
	}

	
}
