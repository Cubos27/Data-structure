#pragma once

#include <iostream>
#include "gato.hpp"

class NodoPila {
    private:
        NodoPila *sig;
    public:
        Gato dato;

        NodoPila(const Gato& dato, NodoPila *sig = nullptr) {
            this->dato = dato;
            this->sig = sig;
        }

    friend class Pila;
};