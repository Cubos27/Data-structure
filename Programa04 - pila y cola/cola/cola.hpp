#pragma once

#include <iostream>
#include "nodoCola.hpp"
#include "perro.hpp"

class Cola {
    // FIFO (First in, First out)
    private:
        NodoCola *h; // Frente de la cola
        NodoCola *t; // Final de la cola

    public:
        // Constructor
        Cola() : h(nullptr), t(nullptr) {}

        // Destructor
        ~Cola() {
            eliminarTodo();
        }

        // 1. Encolar - insertar al final
        void encolar(const Perro& dato) {
            NodoCola *nuevoNodo = new NodoCola(dato);

            if (vacia()) {
                h = nuevoNodo;
                t = nuevoNodo;
            } else {
                t->sig = nuevoNodo;
                t = nuevoNodo;
            }
        }

        // 2. Desencolar - eliminar el primero
        Perro* desencolar() {
            if (vacia()) {
                std::cout << ">> La cola esta vacia. No se puede desencolar.\n";
                return nullptr;
            }

            NodoCola *aux = h;
            h = h->sig;

            if (h == nullptr) {
                t = nullptr;
            }

            Perro *datoPerro = new Perro(aux->dato);
            delete aux;
            return datoPerro;
        }

        // 3. Ver el frente
        Perro* frente() {
            if (vacia()) return nullptr;
            return &h->dato;
        }

        // 4. Ver el final
        Perro* final() {
            if (vacia()) return nullptr;
            return &t->dato;
        }

        // 5. Esta vacia
        bool vacia() {
            return h == nullptr;
        }

        // 6. Obtener tamaño
        int getTamanio() {
            NodoCola *aux = h;
            int tamanio = 0;
            while (aux != nullptr) {
                tamanio++;
                aux = aux->sig;
            }
            return tamanio;
        }
        
    private:
        // Eliminar todos los elementos
        void eliminarTodo(bool verbose = false) {
            if (vacia()) {
                if (verbose) std::cout << "La cola ya estaba vacia." << std::endl;
                return;
            }

            NodoCola *aux = h;
            while (h) {
                h = h->sig;
                delete aux;
                aux = h;
            }
            t = nullptr;

            if (verbose) std::cout << "La cola se ha vaciado correctamente." << std::endl;
        }
};