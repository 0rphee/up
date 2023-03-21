#include <iostream>
#include <unistd.h>
#include <termios.h>

struct Persona {
    char* name;
    char* apellidoPaterno;
    int edad {0};
};

struct Alumno {
    struct Persona persona;
    float calificacion {0};
    int semestre {0};
};

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}



int main(){
    struct Alumno alumno;

    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Introduce un char: ");
    char *ch;

    char* temp = new char[1];
    int count {0};
    
    do {
        ch = new char;
        *ch = getch();
        std::cout << ch;

        if (*ch != '\n'){
            count++;
            char* t = new char[count];
            t = temp;

            *(temp + count) = *ch;

        }
    } while (*ch != '\n');
    std::cout << (temp - count) << std::endl;



    // printf("Introduce un nombre: ");
    // std::cin >> alumno.persona.name;
    // printf("Nombre del alumno: %s", alumno.persona.name);
    
}





