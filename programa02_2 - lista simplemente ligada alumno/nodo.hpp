#pragma once

#include "alumno.hpp"

class Nodo {
    private:
        Nodo *sig;
    public:
        Alumno dato;

        Nodo(const Alumno& dato, Nodo* siguiente = nullptr)
        : dato(dato), siguiente(siguiente) {}

    friend class ListaSimple;
};