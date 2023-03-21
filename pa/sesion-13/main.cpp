#include <cstdio>
#include <iostream>
#include <string>
#define MAX 100

struct Profesor {
    char nombre[MAX] = {'\0'};
    char apellidoPaterno[MAX] = {'\0'};
    char apellidoMaterno[MAX] = {'\0'};
};

void printProf(Profesor profesor){
    printf("\n\t\t\t--------------- INFORMACIÓN DE LA MATERIA ---------------\n");
    std::cout << "Nombre: " << profesor.nombre << "\n";
    std::cout << "Apellido paterno: " << profesor.apellidoPaterno << "\n";
    std::cout << "Apelldio materno: " << profesor.apellidoMaterno<< std::endl;
}

struct Materia {
    char nombre[MAX] = {'\0'};
    int creditos;
    char horario[MAX] = {'\0'};
    struct Profesor profesor;
};

void printMateria(Materia *materia, int numMateria){
    printf("\n------------------------------ INFORMACIÓN DE LA MATERIA %d ---------------\n", numMateria);
    std::cout << "Nombre: " << materia->nombre << "\n";
    std::cout << "Créditos: " << materia->creditos << "\n";
    std::cout << "Horarios: " << materia->horario<< std::endl;
    printProf(materia->profesor);
}

struct Alumno {
    char nombre[MAX] = {'\0'};
    char apellidoPaterno[MAX] = {'\0'};
    char apellidoMaterno[MAX] = {'\0'};
    int edad;
    int grado;
    struct Materia *materias;

};

void printAlumno(Alumno *alumno, int numMaterias, int numAlumno){
    printf("\n-------------------------- INFORMACIÓN DEL ALUMNO %d --------------------------\n", numAlumno);
    std::cout << "Nombre: " << alumno->nombre << "\n";
    std::cout << "Apellido Paterno: " << alumno->apellidoPaterno << "\n";
    std::cout << "Apellido Materno: " << alumno->apellidoMaterno<< std::endl;
    std::cout << "Edad: " << alumno->edad << std::endl;
    std::cout << "Grados: " << alumno->grado<< std::endl;

    for (int i {0}; i < numMaterias; i++ ){ // TODO
        printMateria(alumno->materias + i, i);
    }
}

struct Escuela {
    char nombre[MAX] = {'\0'};
    char direccion[MAX] = {'\0'};
    char nivelEducativo[MAX] = {'\0'};
    struct Alumno *alumnos;
};

void printEscuela(Escuela escuela, int numAlumnos, int *numMaterias){
    printf("\n----------------------------------------------------------------------------------------------------------\n|                                INFORMACIÓN ESCUELA                                |\n----------------------------------------------------------------------------------------------------------\n");
    std::cout << "Nombre: " << escuela.nombre << "\n";
    std::cout << "Dirección: " << escuela.direccion << "\n";
    std::cout << "Nivel Educativo: " << escuela.nivelEducativo << std::endl;
    std::cout << "ALUMNOS: " << std::endl;

    for (int i {0}; i < numAlumnos ; i++ ){
        printAlumno(escuela.alumnos + i, numMaterias[i], i);
    }
}

void printPregunta(const char *tabs, const char *pregunta, const char *preguntado){
    printf("%sIngrese %s %s: ", tabs, pregunta, preguntado);
}
void printPreguntaEscuela(const char *pregunta){
    printPregunta("", pregunta, "de la escuela");
}
void printPreguntaAlumno(const char *pregunta){
    printPregunta("\t", pregunta, "del alumno");
}
void printPreguntaMateria(const char *pregunta){
    printPregunta("\t\t", pregunta, "de la materia");
}
void printPreguntaProfesor(const char *pregunta){
    printPregunta("\t\t\t", pregunta, "del profesor");
}


int main(){
    struct Escuela escuela;

    printPreguntaEscuela("el nombre");
    std::cin >> escuela.nombre;

    printPreguntaEscuela("la dirección");
    std::cin >> escuela.direccion;

    printPreguntaEscuela("el nivel educativo");
    std::cin >> escuela.nivelEducativo;

    printPreguntaEscuela("la cantidad de alumnos");
    int numAlumnos {0};
    std::cin >> numAlumnos;
    escuela.alumnos = new Alumno[numAlumnos];

    int *materiasPtr = new int[numAlumnos];

    for (int i{0}; i < numAlumnos; i++){
        printf("\n\t--------------- INFORMACIÓN ALUMNO %d ---------------\n", i+1);

        printPreguntaAlumno("el nombre");
        std::cin >> (escuela.alumnos[i]).nombre;

        printPreguntaAlumno("el apellido paterno");
        std::cin >> (escuela.alumnos[i]).apellidoPaterno;

        printPreguntaAlumno("el apellido materno");
        std::cin >> (escuela.alumnos[i]).apellidoMaterno;

        printPreguntaAlumno("la edad");
        std::cin >> (escuela.alumnos[i]).edad;

        printPreguntaAlumno("el grado");
        std::cin >> (escuela.alumnos[i]).grado;

        printPreguntaAlumno("el número de materias");
        std::cin >> materiasPtr[i];
        escuela.alumnos[i].materias = new Materia[materiasPtr[i]];

        for (int j {0}; j < materiasPtr[i]; j++){
            printf("\n\t\t--------------- INFORMACIÓN DE LA MATERIA %d ---------------\n", j+1);

            printPreguntaMateria("el nombre");
            std::cin >> escuela.alumnos[i].materias[j].nombre;

            printPreguntaMateria("el número de créditos");
            std::cin >> escuela.alumnos[i].materias[j].creditos;

            printPreguntaMateria("el horario");
            std::cin >> escuela.alumnos[i].materias[j].horario;

            /// /// /// /// /// ///
            printf("\n\t\t\t--------------- INFORMACIÓN DEL PROFESOR ---------------\n");

            printPreguntaProfesor("el nombre");
            std::cin >> escuela.alumnos[i].materias[j].profesor.nombre;

            printPreguntaProfesor("el apellido paterno");
            std::cin >> escuela.alumnos[i].materias[j].profesor.apellidoPaterno;

            printPreguntaProfesor("el apellido materno");
            std::cin >> escuela.alumnos[i].materias[j].profesor.apellidoMaterno;
        }
    }

    printEscuela(escuela, numAlumnos, materiasPtr);

    return 0;
}




