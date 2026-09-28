#pragma once

#include <iostream>
#include "nodo.hpp"
#include "gato.hpp"

class ListaSimple {
    // Last in first out (LIFO)
    private:
        Nodo *h;
        int tamanio;

    public:
        // Constructor
        ListaSimple() : h(nullptr), tamanio(0) {}

        // Destructor
        ~ListaSimple() {
            eliminarTodo();
        }

        void inicializar() {
            eliminarTodo();
            std::cout << ">> Lista reinicializada correctamente.\n";
        }

        // Insertar elemento
        void push(int dato){
            Nodo *nuevoNodo = new Nodo(dato, h);
            h = nuevoNodo;
            tamanio++;
        }

        // Eliminar y retornar elemento
        Gato* pop(int value) {
            if (vacia() || h->sig == nullptr){
                return nullptr;
            }

            Nodo * aux = h;
            h = h->sig;
            Gato *dato = aux->dato;
            delete aux;
            return dato;
        }

        // 6. Eliminar todo
        void eliminarTodo(bool verbose = false) {
            if (vacia()){
                if (verbose) std::cout << "La lista ya estaba vacía" << std::endl;
                return;
            }

            Nodo *aux = h;
            while (h){
                h = h->sig;
                delete aux;
                aux = h;
            }
            if (verbose) std::cout << "La lista se ha eliminado correctamente." << std::endl;
            tamanio = 0;
        }

        // 7. esta vacia?
        bool vacia(){
            return h == nullptr;
        }

        // 8. Mostrar todos los elementos
        void mostrarTodo(){
            if(vacia()){
                std::cout << "La lista no contiene ningún elemento." << std::endl;
                return;
            }

            Nodo *ptr = h;
            while (ptr->sig != nullptr){
                std::cout << "[" << ptr->dato << "], ";
                ptr = ptr->sig;
            }
            std::cout << "[" << ptr->dato << "]" << std::endl;
        }

        // 9. Primero
        Nodo* primero(){
            if (vacia()) return nullptr;

            return h;
        }

        // 10. Ultimo
        Nodo* ultimo(){
            if (vacia()) return nullptr;

            Nodo *aux = h;
            while(aux->sig) aux = aux->sig;
            return aux;
        }

        // 11. Obtener elemento anterior a un valor
        Nodo* anterior(int valor) {
            // Retorna nullptr si no existe una lista o no existe anterior
            if (vacia() || h->dato == valor) {
                return nullptr;
            }

            Nodo* temp = h;
            while (temp->sig != nullptr && temp->sig->dato != valor) {
                temp = temp->sig;
            }
            // Retorna nullptr si no encontró el dato
            if (temp->sig == nullptr) {
                return nullptr;
            }            
            return temp;
        }

        // 12. Obtener elemento siguiente a un valor
        Nodo* siguiente(int valor) {
            Nodo* temp = h;
            while (temp != nullptr && temp->dato != valor) {
                temp = temp->sig;
            }

            // Retorna nullptr si es el ultimo o penultimo elemento
            if (temp == nullptr || temp->sig == nullptr) {
                return nullptr;
            }
            return temp->sig;
        }

        // 13. Obtener tamaño de la lista
        int getTamanio(){
            return tamanio;
        }
};