#pragma once

#include <string>
#include "NodoArista.hpp"

class NodoVertice {
private:
    std::string nombre;       // Identificador del vertice
    NodoVertice* siguiente;   // Siguiente vertice en la lista del grafo
    NodoArista* aristas;      // Lista de aristas salientes

public:
    explicit NodoVertice(const std::string& nombre)
        : nombre(nombre), siguiente(nullptr), aristas(nullptr) {}

    // Libera todas las aristas salientes
    ~NodoVertice() {
        NodoArista* actual = aristas;
        while (actual != nullptr) {
            NodoArista* sig = actual->getSiguiente();
            delete actual;
            actual = sig;
        }
    }

    // No se permite copiar (el nodo es dueno de su lista de aristas)
    NodoVertice(const NodoVertice&) = delete;
    NodoVertice& operator=(const NodoVertice&) = delete;

    const std::string& getNombre() const { return nombre; }
    NodoVertice* getSiguiente() const { return siguiente; }
    NodoArista* getAristas() const { return aristas; }

    void setSiguiente(NodoVertice* sig) { siguiente = sig; }

    // Busca la arista que va hacia 'destino' (nullptr si no existe)
    NodoArista* buscarArista(const NodoVertice* destino) const {
        for (NodoArista* a = aristas; a != nullptr; a = a->getSiguiente()) {
            if (a->getDestino() == destino) return a;
        }
        return nullptr;
    }

    // Inserta una arista al final de la lista. False si ya existia.
    bool insertarArista(NodoVertice* destino, double peso) {
        if (buscarArista(destino) != nullptr) return false;

        NodoArista* nueva = new NodoArista(destino, peso);
        if (aristas == nullptr) {
            aristas = nueva;
        } else {
            NodoArista* ultima = aristas;
            while (ultima->getSiguiente() != nullptr) ultima = ultima->getSiguiente();
            ultima->setSiguiente(nueva);
        }
        return true;
    }

    // Elimina la arista que va hacia 'destino'. False si no existia.
    bool eliminarArista(const NodoVertice* destino) {
        NodoArista* anterior = nullptr;
        NodoArista* actual = aristas;

        while (actual != nullptr && actual->getDestino() != destino) {
            anterior = actual;
            actual = actual->getSiguiente();
        }
        if (actual == nullptr) return false;

        if (anterior == nullptr) aristas = actual->getSiguiente();
        else anterior->setSiguiente(actual->getSiguiente());

        delete actual;
        return true;
    }
};
