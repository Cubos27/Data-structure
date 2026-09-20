#pragma once

#include <iostream>

class Nodo {
    private:
        Nodo *sig;
    public:
        int dato;

        Nodo(int dato = 0, Nodo *sig = nullptr) {
            this->dato = dato;
            this->sig = sig;
        }

        friend class ListaSimple;
};