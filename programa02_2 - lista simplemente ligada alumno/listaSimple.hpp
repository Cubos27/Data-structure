#pragma once

#include <iostream>
#include "nodo.hpp"

class ListaSimple {
private:
    Nodo* h;
    int tamanio;

public:
    ListaSimple() : h(nullptr), tamanio(0) {}

    ~ListaSimple() {
        eliminarTodo();
    }

    void inicializar() {
        eliminarTodo();
        std::cout << ">> Lista reinicializada correctamente.\n";
    }

    Nodo* insertarInicio(const Alumno& alumno) {
        Nodo* nuevoNodo = new Nodo(alumno, h);
        h = nuevoNodo;
        ++tamanio;
        return nuevoNodo;
    }

    Nodo* insertarFinal(const Alumno& alumno) {
        Nodo* nuevoNodo = new Nodo(alumno);

        if (vacia()) {
            h = nuevoNodo;
            ++tamanio;
            return nuevoNodo;
        }

        Nodo* aux = h;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }

        aux->siguiente = nuevoNodo;
        ++tamanio;
        return nuevoNodo;
    }

    Nodo* insertarPosicion(int pos, const Alumno& alumno) {
        if (pos < 0 || pos > tamanio) {
            std::cout << ">> Posicion invalida.\n";
            return nullptr;
        }

        if (pos == 0) {
            return insertarInicio(alumno);
        }

        Nodo* nuevoNodo = new Nodo(alumno);
        Nodo* aux = h;

        for (int i = 0; i < pos - 1; ++i) {
            aux = aux->siguiente;
        }

        nuevoNodo->siguiente = aux->siguiente;
        aux->siguiente = nuevoNodo;

        ++tamanio;
        return nuevoNodo;
    }

    // Los alumnos se identifican mediante su código.
    Nodo* buscar(const std::string& codigo) const {
        Nodo* aux = h;
        int cont = 0;

        while (aux != nullptr) {
            if (aux->dato.getCodigo() == codigo) {
                std::cout << ">> Alumno con codigo " << codigo
                          << " encontrado en la posicion " << cont << ".\n";
                return aux;
            }

            ++cont;
            aux = aux->siguiente;
        }

        std::cout << ">> No se encontro un alumno con ese codigo.\n";
        return nullptr;
    }

    bool eliminar(const std::string& codigo) {
        if (vacia()) {
            return false;
        }

        if (h->dato.getCodigo() == codigo) {
            Nodo* aux = h;
            h = h->siguiente;
            delete aux;
            --tamanio;
            return true;
        }

        Nodo* anterior = h;

        while (anterior->siguiente != nullptr) {
            Nodo* actual = anterior->siguiente;

            if (actual->dato.getCodigo() == codigo) {
                anterior->siguiente = actual->siguiente;
                delete actual;
                --tamanio;
                return true;
            }

            anterior = actual;
        }

        std::cout << ">> No se encontro un alumno con ese codigo.\n";
        return false;
    }

    void eliminarTodo(bool verbose = false) {
        if (vacia()) {
            if (verbose) {
                std::cout << ">> La lista ya estaba vacia.\n";
            }
            tamanio = 0;
            return;
        }

        while (h != nullptr) {
            Nodo* aux = h;
            h = h->siguiente;
            delete aux;
        }

        tamanio = 0;

        if (verbose) {
            std::cout << ">> La lista se ha eliminado correctamente.\n";
        }
    }

    bool vacia() const {
        return h == nullptr;
    }

    void mostrarTodo() const {
        if (vacia()) {
            std::cout << ">> La lista no contiene ningun alumno.\n";
            return;
        }

        Nodo* ptr = h;

        while (ptr != nullptr) {
            ptr->dato.mostrarInformacion();
            std::cout << "\n";
            ptr = ptr->siguiente;
        }
    }

    Nodo* primero() const {
        return h;
    }

    Nodo* ultimo() const {
        if (vacia()) {
            return nullptr;
        }

        Nodo* aux = h;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }

        return aux;
    }

    Nodo* anterior(const std::string& codigo) const {
        if (vacia() || h->dato.getCodigo() == codigo) {
            return nullptr;
        }

        Nodo* temp = h;

        while (temp->siguiente != nullptr &&
               temp->siguiente->dato.getCodigo() != codigo) {
            temp = temp->siguiente;
        }

        if (temp->siguiente == nullptr) {
            return nullptr;
        }

        return temp;
    }

    Nodo* siguiente(const std::string& codigo) const {
        Nodo* temp = h;

        while (temp != nullptr && temp->dato.getCodigo() != codigo) {
            temp = temp->siguiente;
        }

        if (temp == nullptr || temp->siguiente == nullptr) {
            return nullptr;
        }

        return temp->siguiente;
    }

    int getTamanio() const {
        return tamanio;
    }
};
