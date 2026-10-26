#pragma once

#include <iostream>
#include "nodoPila.hpp"
#include "gato.hpp"

class Pila {
    // Last in first out (LIFO)
    private:
        NodoPila *h;

    public:
        // Constructor
        Pila() : h(nullptr) {}

        // Destructor
        ~Pila() {
            eliminarTodo();
        }

        void inicializar() {
            eliminarTodo();
            std::cout << ">> Lista reinicializada correctamente.\n";
        }

        // 1. Insertar elemento
        void apilar(const Gato& dato){
            NodoPila *nuevoNodo = new NodoPila(dato, h);
            h = nuevoNodo;
        }

        // 2. Eliminar y retornar elemento
        Gato* desapilar() {
            if (vacia()){
                return nullptr;
            }

            NodoPila *aux = h;
            h = h->sig;
            Gato *datoGato = new Gato(aux->dato);
            delete aux;
            return datoGato;
        }

        // 3. Cima
        Gato* cima() {
            if (h == nullptr) {
                return nullptr;
            }

            return &(h->dato);
        }

        // 4. esta vacia?
        bool vacia(){
            return h == nullptr;
        }

        // 5. Obtener tamaño de la lista
        int getTamanio(){
            NodoPila *aux = h;
            int tamanio = 0;
            while (aux != nullptr) {
                tamanio++;
                aux = aux->sig;
            }
            return tamanio;
        }
    private:
        // Eliminar todo
        void eliminarTodo(bool verbose = false) {
            if (vacia()){
                if (verbose) std::cout << "La lista ya estaba vacía" << std::endl;
                return;
            }

            NodoPila *aux = h;
            while (h){
                h = h->sig;
                delete aux;
                aux = h;
            }
            if (verbose) std::cout << "La lista se ha eliminado correctamente." << std::endl;
        }
};