#pragma once

class Nodo {
    private:
        Nodo* anterior;
        Nodo* siguiente;
    public:
        int dato;

        Nodo(const int dato, Nodo *ant=nullptr, Nodo *sig=nullptr){
            this->anterior = ant;
            this->dato = dato;
            this->siguiente = sig;
        }
    friend class ListaDoble;
};
