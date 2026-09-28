#pragma once

#include <iostream>
#include "nodo.hpp"

class ListaSimple {
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

        // 1. Insertar inicio
        Nodo* insertarInicio(int dato){
            Nodo *nuevoNodo = new Nodo(dato, h);
            h = nuevoNodo;
            tamanio++;
            return nuevoNodo;
        }

        // 2. Insertar final
        Nodo* insertarFinal(int dato){
            Nodo *newNode = new Nodo(dato);

            if (vacia()){
                h = newNode;
                tamanio++;
                return newNode;
            }

            Nodo *aux = h;
            while (aux->sig != nullptr) {
                aux = aux->sig;
            }
            aux->sig = newNode;
            tamanio++;
            return newNode;
        }

        // 3. Insertar en posicion
        Nodo* insertarPosicion(int pos, int dato) {
            if (pos < 0 || pos > tamanio) {
                std::cout << ">> Posicion invalida.\n";
                return nullptr;
            }

            if (pos == 0) {
                Nodo *aux = insertarInicio(dato);
                return aux;
            }

            Nodo* nuevoNodo = new Nodo(dato);
            Nodo* aux = h;
            for (int i = 0; i < pos - 1; ++i) {
                aux = aux->sig;
            }

            nuevoNodo->sig = aux->sig;
            aux->sig = nuevoNodo;

            tamanio++;
            return nuevoNodo;
        }

        // 4. Buscar un elemento
        Nodo* buscar(int dato){
            Nodo *aux = h;
            int cont = 0;
            while (aux){
                if (aux->dato == dato){
                    std::cout << ">> Valor: " << dato << " encontrado en el lugar " << cont << "." << std::endl;
                    return aux;
                }
                cont++;
                aux = aux->sig;
            }
            std::cout << "No se encontro el valor en la lista" << std::endl;
            return nullptr;
        }

        // 5. Eliminar elemento
        bool eliminar(int value) {
            if (vacia()){
                return false;
            }
            Nodo * aux = h;

            if (h->dato == value) {
                aux = h;
                h = h->sig;
                delete aux;
                tamanio--;
                return true;
            }

            Nodo *aux2 = nullptr;
            while (aux->dato != value && aux->sig != nullptr){
                aux2 = aux;
                aux = aux->sig;
                if (aux->dato == value){
                    if (aux->sig == nullptr) {
                        aux2->sig = nullptr;
                        delete aux;
                        tamanio--;
                        return true;
                    } else {
                        aux2->sig = aux->sig;
                        delete aux;
                        tamanio--;
                        return true;
                    }
                }
            }
            std::cout << "No se encontro el valor en la lista" << std::endl;
            return false;
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