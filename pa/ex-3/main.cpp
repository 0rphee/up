// Resolver las preguntas en su archivo .cpp y subirlo al espacio asignado en Moodle.
// El archivo debe de cumplir con el siguiente formato nombre_completo_id.cpp
 

/*

1.     ¿Qué es una clase base?

    Una clase base es una clase de la cual se derivan características comunes entre otras clases,
    tales como métodos y propiedades comunes. Mediante herencia, la clase base (que puede ser 
    cualquier clase), da a la clase derivada sus características, sin embargo, esto no impide
    que la clase base tambien herede de otra clase.

2.     ¿Qué es una clase derivada?

    Una clase derivada, es una clase que se creada a partir de una clase base o superclase. La
    clase derivada hereda los atributos y métodos de la clase base y puede agregar nuevos atributos
    y métodos o modificarlos los métodos y atributos heredados según sea necesario.

3.     ¿Qué es un constructor copia?

    Es un constructor que pasa ciertos parámetros al constructor de la clase base de la que se deriva,
    pero que despúes ejecuta código propio para inicializar de forma específica las características de
    la clase derivada, evitando el código duplicado.  

4.     ¿Qué es el destructor?

    Un destructor es un método especial de cada clase que sirve para liberar los recursos (de memoria)
    de una instancia de una clase cuando deja de ser utilizada (o cuando se utiliza la palabra reservada
    'delete'). Este método suele invocarse automáticamente.

5.     Describa las características de los diferentes niveles de acceso para los miembros de una clase y que pasa en cada uno de los casos cuando se tiene herencia


    Public: los miembros son accesibles desde cualquier parte del programa, sin restricción alguna,
            y este estatus se mantiene para las clases derivadas .

    Protected: los miembros se pueden acceder desde la clase que los define y clases derivadas, pero
               no en todo el programa en general.

    Private: los miembros solo pueden ser accedidos mediante la clase que los define, y no son 
             accesibles desde clases derivadas ni pueden ser accesibles en el programa en general.

6.     Escriba un programa que le permita al usuario ingresar n cantidad de elementos de una clase Alumno que tiene herencia de la clase Persona

a.     Los miembros de la clase Alumno son (calificación, grado, id_alumno ,id_materia, carrera)

b.     Los miembros de la clase Persona son (nombre, edad, fecha_nacimiento, curp)

c.     Programar los métodos gets, sets para los respectivos atributos de cada una de las clases

*/

#include <iostream>
#include <string>

class Persona {
protected:
    std::string nombre;
    unsigned int edad;
    std::string fecha_nacimiento;
    std::string curp;

public:
    Persona(){
        this->nombre = "indefinido";
        this->edad = 0;
        this->fecha_nacimiento = "indefinido";
        this->curp = "indefinido";
    }
    Persona(std::string nombre, int edad, std::string fecha_nacimiento, std::string curp) {
        this->nombre = nombre;
        this->edad = edad;
        this->fecha_nacimiento = fecha_nacimiento;
        this->curp = curp;
    }

    std::string getNombre() {
        return this->nombre;
    }
    void setNombre(std::string nombre) {
        this->nombre = nombre;
    }

    int getEdad() {
        return this->edad;
    }
    void setEdad(int edad) {
        this->edad = edad;
    }

    std::string getFechaNacimiento() {
        return this->fecha_nacimiento;
    }
    void setFechaNacimiento(std::string fecha_nacimiento) {
        this->fecha_nacimiento = fecha_nacimiento;
    }

    std::string getCurp() {
        return this->curp;
    }
    void setCurp(std::string curp) {
        this->curp = curp;
    }
};

class Alumno : public Persona {
protected:
    double calificacion;
    std::string grado;
    std::string id_alumno;
    std::string id_materia;
    std::string carrera;

public:
    Alumno() : Persona() {
        this->calificacion = 0;
        this->grado = "indefinido";
        this->id_alumno = "indefinido";
        this->id_materia = "indefinido";
        this->carrera = "indefinido";
    }
    Alumno(std::string nombre, int edad, std::string fecha_nacimiento, std::string curp, double calificacion, std::string grado, std::string id_alumno, std::string id_materia, std::string carrera)
        : Persona(nombre, edad, fecha_nacimiento, curp) {
        this->calificacion = calificacion;
        this->grado = grado;
        this->id_alumno = id_alumno;
        this->id_materia = id_materia;
        this->carrera = carrera;
    }

    double getCalificacion() {
        return this->calificacion;
    }
    void setCalificacion(double calificacion) {
        this->calificacion = calificacion;
    }

    std::string getGrado() {
        return this->grado;
    }
    void setGrado(std::string grado) {
        this->grado = grado;
    }

    std::string getIdAlumno() {
        return this->id_alumno;
    }
    void setIdAlumno(int id_alumno) {
        this->id_alumno = id_alumno;
    }

    std::string getIdMateria() {
        return this->id_materia;
    }
    void setIdMateria(int id_materia) {
        this->id_materia = id_materia;
    }

    std::string getCarrera() {
        return this->carrera;
    }
    void setCarrera(std::string carrera) {
        this->carrera = carrera;
    }
};

int main() {
    int n_alumnos;
    printf("Ingrese la cantidad de alumnos a ingresar: ");
    std::cin >> n_alumnos;

    Alumno* alumnos = new Alumno[n_alumnos];

    for (int i = 0; i < n_alumnos; i++) {
        std::string nombre;
        unsigned int edad;
        std::string fecha_nacimiento;
        std::string curp;

        std::string id_materia;
        int calificacion;
        std::string grado;
        std::string id_alumno;
        std::string carrera;

        printf("Alumno %d\n", i+1);

        printf("Nombre: ");
        std::cin >> nombre;

        printf("Edad: ");
        std::cin >> edad;

        printf("Fecha de nacimiento: ");
        std::cin >> fecha_nacimiento;

        printf("CURP: ");
        std::cin >> curp;

        printf("ID de la materia: ");
        std::cin >> id_materia;

        printf("Calificación de la materia: ");
        std::cin >> calificacion;

        printf("Grado del alumno: ");
        std::cin >> grado;

        printf("ID el alumno: ");
        std::cin >> id_alumno;

        printf("Carrera del alumno: ");
        std::cin >> carrera;

        alumnos[i] = Alumno(nombre, edad, fecha_nacimiento, curp, calificacion, grado, id_alumno, id_materia, carrera);
        printf("\n");
    }

    // Mostrar información de los alumnos ingresados
    std::cout << "Informacion de los alumnos:" << std::endl;
    for (int i = 0; i < n_alumnos; i++) {
        std::cout << "Alumno " << i + 1 << "\n";
        std::cout << "Nombre: " << alumnos[i].getNombre() << std::endl;
        std::cout << "Edad: " << alumnos[i].getEdad() << std::endl;
        std::cout << "Fecha de nacimiento: " << alumnos[i].getFechaNacimiento() << std::endl;
        std::cout << "CURP: " << alumnos[i].getCurp() << std::endl;
        std::cout << "Calificacion: " << alumnos[i].getCalificacion() << std::endl;
        std::cout << "Grado: " << alumnos[i].getGrado() << std::endl;
        std::cout << "ID Alumno: " << alumnos[i].getIdAlumno() << std::endl;
        std::cout << "ID Materia: " << alumnos[i].getIdMateria() << std::endl;
        std::cout << "Carrera: " << alumnos[i].getCarrera() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
