#pragma once

#include <string>
#include <iostream>

class Perro {
private:
    std::string nombre;
    std::string raza;
    int edad;
    float peso;
    std::string color;

public:
    // Constructor por defecto
    Perro()
        : nombre("Sin nombre"),
          raza("Sin raza"),
          edad(0),
          peso(0.0f),
          color("Sin color") {
    }

    // Constructor con todos los atributos
    Perro(const std::string& nombre,
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
    Perro(const Perro& otro)
        : nombre(otro.nombre),
          raza(otro.raza),
          edad(otro.edad),
          peso(otro.peso),
          color(otro.color) {
    }

    void mostrar() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Raza: " << raza << std::endl;
        std::cout << "Edad: " << edad << " años" << std::endl;
        std::cout << "Peso: " << peso << " kg" << std::endl;
        std::cout << "Color: " << color << std::endl;
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