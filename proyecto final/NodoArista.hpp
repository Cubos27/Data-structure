#pragma once

class NodoVertice;  // Declaracion adelantada (evita inclusion circular)

class NodoArista {
private:
    NodoVertice* destino;   // Vertice al que apunta la arista
    double peso;            // Peso de la arista
    NodoArista* siguiente;  // Siguiente arista en la lista del vertice origen

public:
    NodoArista(NodoVertice* destino, double peso)
        : destino(destino), peso(peso), siguiente(nullptr) {}

    NodoVertice* getDestino() const { return destino; }
    double getPeso() const { return peso; }
    NodoArista* getSiguiente() const { return siguiente; }

    void setPeso(double nuevoPeso) { peso = nuevoPeso; }
    void setSiguiente(NodoArista* sig) { siguiente = sig; }
};
