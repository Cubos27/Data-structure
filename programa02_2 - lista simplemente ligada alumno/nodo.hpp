#pragma once

#include "alumno.hpp"

class Nodo {
    private:
        Nodo *siguiente;
    public:
        Alumno dato;

        Nodo(const Alumno& dato, Nodo* siguiente = nullptr)
        : dato(dato), siguiente(siguiente) {}

    friend class ListaSimple;
};