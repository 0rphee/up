#include <iostream>
#include "Alumno_0250061.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Alumno alumno1;
    std::string inputNombre, inputId, inputAnioIngreso, inputCarrera;

    cout << "DATOS DEL ALUMNO" << endl;
    cout << "Ingrese su nombre: ";
    cin >> inputNombre;
    alumno1.setNombre(inputNombre);
    cout << "Ingrese su ID: ";
    cin >> inputId;
    alumno1.setId(inputId);
    cout << "Ingrese su año de ingreso: ";
    cin >> inputAnioIngreso;
    alumno1.setAnioIngreso(inputAnioIngreso);
    cout << "Ingrese su carrera: ";
    cin >> inputCarrera;
    alumno1.setCarrera(inputCarrera);

    cout << "\nPRESENTACIÓN DE DATOS" << endl;
    cout << "Nombre: " << alumno1.getNombre() << endl;
    cout << "ID: " << alumno1.getId() << endl;
    cout << "Año de ingreso: " << alumno1.getAnioIngreso() << endl;
    cout << "Carrera: " << alumno1.getCarrera() << endl;
    return 0;
}