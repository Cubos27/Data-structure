#include <iostream>
#include <string>

class Alumno {
private:
    std::string nombre;
    std::string codigo;
    std::string carrera;
    int edad;
    float promedio;

public:
    // Constructores
    Alumno() 
        : nombre("Sin nombre"), codigo("000000000"), edad(0), carrera("Sin asignar"), promedio(0.0f) {}

    Alumno(std::string nombre, std::string codigo) 
        : nombre(nombre), codigo(codigo), edad(0), carrera("Sin asignar"), promedio(0.0f) {}

    Alumno(std::string nombre, std::string codigo, int edad, std::string carrera, float promedio)
        : nombre(nombre), codigo(codigo), edad(edad), carrera(carrera), promedio(promedio) {}

    ~Alumno() {}

    // Getters
    std::string getNombre() const { return nombre; }
    std::string getCodigo() const { return codigo; }
    int getEdad() const { return edad; }
    std::string getCarrera() const { return carrera; }
    float getPromedio() const { return promedio; }

    // Setters
    void setNombre(const std::string& n) { nombre = n; }
    void setCodigo(const std::string& c) { codigo = c; }
    void setEdad(int e) { edad = e; }
    void setCarrera(const std::string& car) { carrera = car; }
    void setPromedio(float p) { promedio = p; }

    // Metodo para imprimir la informacion
    void mostrarInformacion() const {
        std::cout << "Nombre:   " << nombre << "\n"
                  << "Código:   " << codigo << "\n"
                  << "Edad:     " << edad << " años\n"
                  << "Carrera:  " << carrera << "\n"
                  << "Promedio: " << promedio << "\n"
                  << "------------------------------------" << std::endl;
    }
};