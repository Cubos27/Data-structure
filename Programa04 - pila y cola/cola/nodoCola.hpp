#pragma once

#include <iostream>
#include "perro.hpp"

class Cola;

class NodoCola {
    private:
        NodoCola *sig;
    public:
        Perro dato;

        NodoCola(const Perro& dato, NodoCola *sig = nullptr) {
            this->dato = dato;
            this->sig = sig;
        }

    friend class Cola;
};