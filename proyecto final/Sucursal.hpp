#pragma once

#include <iostream>
#include <string>

class Sucursal {
private:
    std::string nombre;
    std::string direccion;
    std::string telefono;
    std::string horario;

public:
    // Constructor con valores por defecto
    Sucursal(const std::string& nombre = "",
             const std::string& direccion = "",
             const std::string& telefono = "",
             const std::string& horario = "")
        : nombre(nombre),
          direccion(direccion),
          telefono(telefono),
          horario(horario) {}

    void imprimir() const {
        std::cout << "\n===== DATOS DE LA SUCURSAL =====\n";
        std::cout << "Nombre:    " << (nombre.empty()    ? "(sin datos)" : nombre)    << "\n";
        std::cout << "Direccion: " << (direccion.empty() ? "(sin datos)" : direccion) << "\n";
        std::cout << "Telefono:  " << (telefono.empty()  ? "(sin datos)" : telefono)  << "\n";
        std::cout << "Horario:   " << (horario.empty()   ? "(sin datos)" : horario)   << "\n";
        std::cout << "================================\n";
    }

    void pedirDatos() {
        std::cout << "\n--- Captura de datos de la sucursal ---\n";

        std::cout << "Nombre de la sucursal: ";
        std::getline(std::cin, nombre);

        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);

        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);

        std::cout << "Horario (ej. Lun-Vie 9:00-18:00): ";
        std::getline(std::cin, horario);
    }
};
