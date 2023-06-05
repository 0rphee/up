#pragma once
#include <iostream>

class Alumno
{
private:
    std::string nombre;
    std::string id;
    std::string anioIngreso;
    std::string carrera;
    
public:
    Alumno(/* args */);
    Alumno(std::string nombre, std::string id, std::string anioIngreso, std::string carrera);

    //Set
    bool setNombre(std::string nombre);
    bool setId(std::string id);
    bool setAnioIngreso(std::string anioIngreso);
    bool setCarrera(std::string carrera);

    //Get
    std::string getNombre();
    std::string getId();
    std::string getAnioIngreso();
    std::string getCarrera();

    ~Alumno();
};

Alumno::Alumno(/* args */)
{
    this->nombre = "indefinido";
    this->id = "indefinido";
    this->anioIngreso = "indefinido";
    this->carrera = "indefinido";
}

Alumno::Alumno(std::string nombre, std::string id, std::string anioIngreso, std::string carrera)
{
    this->nombre = nombre;
    if(stoi(id) >= 0)
    {
        this->id = id;
    }
    if(stoi(anioIngreso) >= 0 && stoi(anioIngreso) <= 2023)
    {
        this->anioIngreso = anioIngreso;
    }
    this->carrera = carrera;
}

bool Alumno::setNombre(std::string nombre)
{
    this->nombre = nombre;
    return true;
}

bool Alumno::setId(std::string id)
{
    if(stoi(id) < 0)
    {
        return false;
    }
    this->id = id;
    return true;
}

bool Alumno::setAnioIngreso(std::string anioIngreso)
{
    if(stoi(anioIngreso) < 0 || stoi(anioIngreso) > 2023)
    {
        return false;
    }
    this->anioIngreso = anioIngreso;
    return true;
}

bool Alumno::setCarrera(std::string carrera)
{
    this->carrera = carrera;
    return true;
}

std::string Alumno::getNombre()
{
    return this->nombre;
}

std::string Alumno::getId()
{
    return this->id;
}

std::string Alumno::getAnioIngreso()
{
    return this->anioIngreso;
}

std::string Alumno::getCarrera()
{
    return this->carrera;
}

Alumno::~Alumno()
{
}