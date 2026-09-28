#pragma once

#include <iostream>
#include "gato.hpp"

class Nodo {
    private:
        Nodo *sig;
    public:
        Gato *dato;

        Nodo(Gato dato = 0, Nodo *sig = nullptr) {
            this->dato = dato;
            this->sig = sig;
        }

        friend class ListaSimple;
};