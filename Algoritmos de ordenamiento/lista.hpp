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
    void insertarInicio(const int dato) {
        Nodo* nuevo = new Nodo(dato, nullptr, h);

        if (h != nullptr) {
            h->anterior = nuevo;
        }
        else {
            t = nuevo;
        }

        h = nuevo;
    }

    // 2. insertar final
    void insertarFinal(const int dato) {
        Nodo* nuevo = new Nodo(dato, t, nullptr);

        if (t != nullptr) {
            t->siguiente = nuevo;
        }
        else {
            h = nuevo;
        }

        t = nuevo;
    }

    // 3. insertar posicion
    bool insertarPosicion(int posicion, const int dato) {
        int total = tamanho();

        if (posicion < 0 || posicion > total) {
            return false;
        }

        if (posicion == 0) {
            insertarInicio(dato);
            return true;
        }

        if (posicion == total) {
            insertarFinal(dato);
            return true;
        }

        Nodo* actual = h;

        for (int i = 0; i < posicion; i++) {
            actual = actual->siguiente;
        }

        Nodo* anteriorNodo = actual->anterior;

        Nodo* nuevo = new Nodo(dato, anteriorNodo, actual);

        anteriorNodo->siguiente = nuevo;
        actual->anterior = nuevo;

        return true;
    }

    // 4. buscar
    Nodo* buscar(const int dato) {
        Nodo* actual = h;

        while (actual != nullptr) {
            if (actual->dato == dato) {
                return actual;
            }

            actual = actual->siguiente;
        }

        return nullptr;
    }

    // 5. eliminar
    bool eliminar(const int dato) {
        Nodo* actual = buscar(dato);

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
            std::cout << actual->dato << ", ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
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
    Nodo* anterior(const int dato) const {
        Nodo* temp = h;

        while (temp != nullptr && temp->dato != dato) {
            temp = temp->siguiente;
        }

        if (temp == nullptr || temp->siguiente == nullptr) {
            return nullptr;
        }

        return temp->anterior;
    }

    // 12. siguiente
    Nodo* siguiente(const int dato) const {
        Nodo* temp = h;

        while (temp != nullptr && temp->dato != dato) {
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

    void intercambio(int i){
        // Recibe un entero que representa el lugar a verificar lista[2]
        // Intercambia solo datos con el contador y su siguiente
        Nodo *temp = h;
        int cont = 0;
        while (temp->siguiente != nullptr && cont != i){
            temp = temp->siguiente;
            cont++;
        }
        std::cout << temp->dato << std::endl;
        // En esta parte se tiene que intercambiar los nodos
    }
};
