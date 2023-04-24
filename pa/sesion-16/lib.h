#include <iostream>
#include <ostream>
#include <string>

typedef struct{
    std::string nombre;
    unsigned int edad;
    std::string curp;
    std::string fechaNacimiento;
    std::string carrera;
    std::string universidad;

} Alumno;

Alumno getAlumno(){
    Alumno alum;
    std::cout << std::endl << "Ingrese el nombre del alumno: " ;
    std::cin >> alum.nombre;
    std::cout << std::endl << "Ingrese la edad del alumno: ";
    std::cin >> alum.edad;
    std::cout << std::endl << "Ingrese el CURP del alumno: ";
    std::cin >> alum.curp;
    std::cout << std::endl << "Ingrese la fecha de nacimiento del alumno (dd/mm/yyyy): ";
    std::cin >> alum.fechaNacimiento;
    std::cout << std::endl << "Ingrese la carrera del alumno: "; 
    std::cin >> alum.carrera;
    std::cout << std::endl << "Ingrese la universidad del alumno: "; 
    std::cin >> alum.universidad;
	std::cout << std::endl;
    return alum;
}

void printAlumno(Alumno alum){
    std::cout << std::endl << "Nombre del alumno: " << alum.nombre;
    std::cout << std::endl << "Edad del alumno: " << alum.edad;
    std::cout << std::endl << "CURP del alumno: " << alum.curp;
    std::cout << std::endl << "Fecha de nacimiento del alumno: " << alum.fechaNacimiento;
    std::cout << std::endl << "Carrera del alumno: " << alum.carrera; 
    std::cout << std::endl << "Universidad del alumno: " << alum.universidad; 
	std::cout << std::endl;
}

