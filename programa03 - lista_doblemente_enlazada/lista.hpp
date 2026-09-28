#pragma once

#include <iostream>
#include <string>
#include "nodo.hpp"

class ListaDoble {
private:
    Nodo* h;
    Nodo* t;

public:
    ListaDoble() {
        h = nullptr;
        t = nullptr;
    }

    ~ListaDoble() {
        eliminarTodo();
    }

    // 1. insertar inicio
    void insertarInicio(const Alumno& alumno) {
        Nodo* nuevo = new Nodo(alumno, nullptr, h);

        if (h != nullptr) {
            h->anterior = nuevo;
        }
        else {
            t = nuevo;
        }

        h = nuevo;
    }

    // 2. insertar final
    void insertarFinal(const Alumno& alumno) {
        Nodo* nuevo = new Nodo(alumno, t, nullptr);

        if (t != nullptr) {
            t->siguiente = nuevo;
        }
        else {
            h = nuevo;
        }

        t = nuevo;
    }

    // 3. insertar posicion
    bool insertarPosicion(int posicion, const Alumno& alumno) {
        int total = tamanho();

        if (posicion < 0 || posicion > total) {
            return false;
        }

        if (posicion == 0) {
            insertarInicio(alumno);
            return true;
        }

        if (posicion == total) {
            insertarFinal(alumno);
            return true;
        }

        Nodo* actual = h;

        for (int i = 0; i < posicion; i++) {
            actual = actual->siguiente;
        }

        Nodo* anteriorNodo = actual->anterior;

        Nodo* nuevo = new Nodo(alumno, anteriorNodo, actual);

        anteriorNodo->siguiente = nuevo;
        actual->anterior = nuevo;

        return true;
    }

    // 4. buscar
    Nodo* buscar(const std::string& codigo) {
        Nodo* actual = h;

        while (actual != nullptr) {
            if (actual->dato.getCodigo() == codigo) {
                return actual;
            }

            actual = actual->siguiente;
        }

        return nullptr;
    }

    // 5. eliminar
    bool eliminar(const std::string& codigo) {
        Nodo* actual = buscar(codigo);

        if (actual == nullptr) {
            return false;
        }

        if (actual == h) {
            h = actual->siguiente;
        }
        else {
            actual->anterior->siguiente = actual->siguiente;
        }

        if (actual == t) {
            t = actual->anterior;
        }
        else {
            actual->siguiente->anterior = actual->anterior;
        }

        delete actual;

        return true;
    }

    // 6. eliminar todo
    void eliminarTodo(bool verbose=false) {
        Nodo* actual = h;

        while (actual != nullptr) {
            Nodo* siguienteNodo = actual->siguiente;
            delete actual;
            actual = siguienteNodo;
        }

        h = nullptr;
        t = nullptr;
        if (verbose) {
            std::cout << ">> La lista se ha eliminado correctamente.\n";
        }
    }

    // 7. vacia
    bool vacia() const {
        return h == nullptr;
    }

    // 8. mostrar todo
    void mostrarTodo() const {
        if (vacia()) {
            std::cout << "La lista esta vacia." << std::endl;
            return;
        }

        Nodo* actual = h;

        while (actual != nullptr) {
            actual->dato.mostrarInformacion();
            actual = actual->siguiente;
        }
    }

    // 9. primero
    Nodo* primero() const {
        return h;
    }

    // 10. ultimo
    Nodo* ultimo() const {
        return t;
    }

    // 11. anterior
    Nodo* anterior(const std::string& codigo) const {
        Nodo* temp = h;

        while (temp != nullptr && temp->dato.getCodigo() != codigo) {
            temp = temp->siguiente;
        }

        if (temp == nullptr || temp->siguiente == nullptr) {
            return nullptr;
        }

        return temp->anterior;
    }

    // 12. siguiente
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

    // 13. tamanho
    int tamanho() const {
        int contador = 0;
        Nodo* actual = h;

        while (actual != nullptr) {
            contador++;
            actual = actual->siguiente;
        }

        return contador;
    }
};