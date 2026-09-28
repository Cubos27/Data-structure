#pragma once

#include "alumno.hpp"

class Nodo {
    private:
        Nodo* anterior;
        Nodo* siguiente;
    public:
        Alumno dato;

        Nodo(const Alumno& dato, Nodo *ant=nullptr, Nodo *sig=nullptr){
            this->anterior = ant;
            this->dato = dato;
            this->siguiente = sig;
        }
    friend class ListaDoble;
};