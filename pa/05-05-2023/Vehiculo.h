#pragma once
#include <iostream>

namespace db{
    class Vehiculo{
        private:
            unsigned char llantas;
            bool status;
            unsigned char puertas;
            std::string color;
            std::string marca;
            std::string placas;
            float combustible;
            char marcha;
            std::string tipo;
        public:
        Vehiculo(/* args */);
        Vehiculo(unsigned char llantas, bool status, unsigned char puertas, std::string color, std::string marca, std::string placas, float combustible, char marcha, std::string tipo);
        Vehiculo(const Vehiculo &v);

        bool setLlantas(unsigned char llantas);
        unsigned char getLlantas();
        bool setStatus(bool status);
        bool getStatus();
        bool setPuertas(unsigned char puertas);
        unsigned char getPuertas();
        bool setColor(std::string color);
        std::string getColor();
        bool setMarca(std::string marca);
        std::string getMarca();
        bool setPlacas(std::string placas);
        std::string getPlacas();
        bool setCombustible(float combustible);
        float getCombustible();
        bool setMarcha(char marcha);
        char getMarcha();
        bool setTipo(std::string tipo);
        std::string getTipo();

        ~Vehiculo();

    };
    Vehiculo::Vehiculo(unsigned char llantas, bool status, unsigned char puertas, std::string color, std::string marca, std::string placas, float combustible, char marcha, std::string tipo){
        this->llantas = llantas;
        this->status = status;
        this->puertas = puertas;
        this->color = color;
        this->marca = marca;
        this->placas = placas;
        this->combustible = combustible;
        this->marcha = marcha;
        this->tipo = tipo;
    }
    Vehiculo::Vehiculo(const Vehiculo &v){
        this->llantas = v.llantas;
        this->status = v.status;
        this->puertas = v.puertas;
        this->color = v.color;
        this->marca = v.marca;
        this->placas = v.placas;
        this->combustible = v.combustible;
        this->marcha = v.marcha;
        this->tipo = v.tipo;
    }
    bool Vehiculo::setLlantas(unsigned char llantas){
        if(llantas > 0 && llantas < 20){
            this->llantas = llantas;
            return true;
        }
        return false;
    }
    unsigned char Vehiculo::getLlantas(){
        return this->llantas;
    }
    bool Vehiculo::setStatus(bool status){
        this->status = status;
        return true;
    }
    bool Vehiculo::getStatus(){
        return this->status;
    }
    bool Vehiculo::setPuertas(unsigned char puertas){
        if(puertas > 0){
            this->puertas = puertas;
            return true;
        }
        return false;
    }
    unsigned char Vehiculo::getPuertas(){
        return this->puertas;
    }
    bool Vehiculo::setColor(std::string color){
        if(color.length() > 0){
            this->color = color;
            return true;
        }
        return false;
    }
    std::string Vehiculo::getColor(){
        return this->color;
    }
    bool Vehiculo::setMarca(std::string marca){
        if(marca.length() > 0){
            this->marca = marca;
            return true;
        }
        return false;
    }
    std::string Vehiculo::getMarca(){
        return this->marca;
    }
    bool Vehiculo::setPlacas(std::string placas){
        if(placas.length() > 0){
            this->placas = placas;
            return true;
        }
        return false;
    }
    std::string Vehiculo::getPlacas(){
        return this->placas;
    }
    bool Vehiculo::setCombustible(float combustible){
        if(combustible > 0){
            this->combustible = combustible;
            return true;
        }
        return false;
    }
    float Vehiculo::getCombustible(){
        return this->combustible;
    }

    bool Vehiculo::setMarcha(char marcha){
        if(marcha == 'P' || marcha == 'N' || marcha == 'R' || marcha == 'D'){
            this->marcha = marcha;
            return true;
        }
        return false;
    }

    char Vehiculo::getMarcha(){
        return this->marcha;
    }

    bool Vehiculo::setTipo(std::string tipo){
        if(tipo.length() > 0){
            this->tipo = tipo;
            return true;
        }
        return false;
    }
    std::string Vehiculo::getTipo(){
        return this->tipo;
    }

    Vehiculo::~Vehiculo(){
    }
}

