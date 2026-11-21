#pragma once

#include <iostream>
#include <string>
#include "NodoArista.hpp"
#include "NodoVertice.hpp"

// Grafo ponderado implementado con listas de adyacencia enlazadas.
// Si 'dirigido' es false, cada arista se guarda en ambos sentidos.
class Grafo {
private:
    NodoVertice* primero;
    bool dirigido;

    // Busca un vertice por nombre (nullptr si no existe)
    NodoVertice* buscarVertice(const std::string& nombre) const {
        for (NodoVertice* v = primero; v != nullptr; v = v->getSiguiente()) {
            if (v->getNombre() == nombre) return v;
        }
        return nullptr;
    }

public:
    explicit Grafo(bool dirigido = false) : primero(nullptr), dirigido(dirigido) {}

    ~Grafo() {
        NodoVertice* actual = primero;
        while (actual != nullptr) {
            NodoVertice* sig = actual->getSiguiente();
            delete actual;  // El destructor del vertice libera sus aristas
            actual = sig;
        }
    }

    Grafo(const Grafo&) = delete;
    Grafo& operator=(const Grafo&) = delete;

    // 1) Inserta un vertice. False si ya existe uno con ese nombre.
    bool insertarVertice(const std::string& nombre) {
        if (buscarVertice(nombre) != nullptr) return false;

        NodoVertice* nuevo = new NodoVertice(nombre);
        if (primero == nullptr) {
            primero = nuevo;
        } else {
            NodoVertice* ultimo = primero;
            while (ultimo->getSiguiente() != nullptr) ultimo = ultimo->getSiguiente();
            ultimo->setSiguiente(nuevo);
        }
        return true;
    }

    // 2) Inserta una arista con peso. False si falta algun vertice o ya existe.
    bool insertarArista(const std::string& origen, const std::string& destino, double peso) {
        NodoVertice* o = buscarVertice(origen);
        NodoVertice* d = buscarVertice(destino);
        if (o == nullptr || d == nullptr) return false;

        if (!o->insertarArista(d, peso)) return false;
        if (!dirigido && o != d) d->insertarArista(o, peso);
        return true;
    }

    // 3) Elimina un vertice y todas las aristas que llegan o salen de el.
    bool eliminarVertice(const std::string& nombre) {
        NodoVertice* objetivo = buscarVertice(nombre);
        if (objetivo == nullptr) return false;

        // Quitar las aristas de los demas vertices que apuntan al objetivo
        for (NodoVertice* v = primero; v != nullptr; v = v->getSiguiente()) {
            if (v != objetivo) v->eliminarArista(objetivo);
        }

        // Desenlazar el vertice de la lista y liberarlo
        NodoVertice* anterior = nullptr;
        NodoVertice* actual = primero;
        while (actual != objetivo) {
            anterior = actual;
            actual = actual->getSiguiente();
        }
        if (anterior == nullptr) primero = objetivo->getSiguiente();
        else anterior->setSiguiente(objetivo->getSiguiente());

        delete objetivo;
        return true;
    }

    // 4) Elimina una arista. False si falta algun vertice o la arista no existe.
    bool eliminarArista(const std::string& origen, const std::string& destino) {
        NodoVertice* o = buscarVertice(origen);
        NodoVertice* d = buscarVertice(destino);
        if (o == nullptr || d == nullptr) return false;

        if (!o->eliminarArista(d)) return false;
        if (!dirigido && o != d) d->eliminarArista(o);
        return true;
    }

    // 5) Imprime el listado de vertices con sus aristas
    void imprimir() const {
        std::cout << "\n===== LISTADO DEL GRAFO ("
                  << (dirigido ? "dirigido" : "no dirigido") << ") =====\n";

        if (primero == nullptr) {
            std::cout << "(el grafo esta vacio)\n";
            return;
        }

        for (NodoVertice* v = primero; v != nullptr; v = v->getSiguiente()) {
            std::cout << "[" << v->getNombre() << "] -> ";

            if (v->getAristas() == nullptr) {
                std::cout << "(sin aristas)";
            }
            for (NodoArista* a = v->getAristas(); a != nullptr; a = a->getSiguiente()) {
                std::cout << "(" << a->getDestino()->getNombre()
                          << ", peso " << a->getPeso() << ")";
                if (a->getSiguiente() != nullptr) std::cout << ", ";
            }
            std::cout << "\n";
        }
    }
};
