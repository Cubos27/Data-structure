#pragma once

#include <string>

class Gato {
private:
    std::string nombre;
    std::string raza;
    int edad;
    float peso;
    std::string color;

public:
    // Constructor por defecto
    Gato()
        : nombre("Sin nombre"),
          raza("Sin raza"),
          edad(0),
          peso(0.0f),
          color("Sin color") {
    }

    // Constructor con todos los atributos
    Gato(const std::string& nombre,
         const std::string& raza,
         int edad,
         float peso,
         const std::string& color)
        : nombre(nombre),
          raza(raza),
          edad(edad),
          peso(peso),
          color(color) {
    }

    // Constructor de copia
    Gato(const Gato& otro)
        : nombre(otro.nombre),
          raza(otro.raza),
          edad(otro.edad),
          peso(otro.peso),
          color(otro.color) {
    }

    // Getters
    std::string getNombre() const {
        return nombre;
    }

    std::string getRaza() const {
        return raza;
    }

    int getEdad() const {
        return edad;
    }

    float getPeso() const {
        return peso;
    }

    std::string getColor() const {
        return color;
    }

    // Setters
    void setNombre(const std::string& nombre) {
        this->nombre = nombre;
    }

    void setRaza(const std::string& raza) {
        this->raza = raza;
    }

    void setEdad(int edad) {
        this->edad = edad;
    }

    void setPeso(float peso) {
        this->peso = peso;
    }

    void setColor(const std::string& color) {
        this->color = color;
    }
};