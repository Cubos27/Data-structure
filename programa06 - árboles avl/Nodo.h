#pragma once

/**
 * Nodo
 * ----
 * Representa un nodo del árbol AVL. Cada nodo se reserva en memoria dinámica
 * (heap) con `new` desde el árbol, por lo que el árbol es responsable de
 * liberarlo con `delete`.
 *
 * Se guarda la ALTURA dentro del nodo (en lugar de calcularla recorriendo
 * los subárboles) para que obtener el factor de balance sea O(1).
 * Si la calculáramos recursivamente cada vez, perderíamos la ventaja
 * logarítmica del AVL.
 */
template <typename T>
class Nodo {
public:
    T dato;            // Valor almacenado (T debe soportar operator<)
    Nodo* izquierdo;   // Subárbol con valores menores
    Nodo* derecho;     // Subárbol con valores mayores
    int altura;        // Altura del nodo: una hoja tiene altura 1

    // `explicit` evita conversiones implícitas accidentales de T a Nodo<T>.
    explicit Nodo(const T& valor)
        : dato(valor), izquierdo(nullptr), derecho(nullptr), altura(1) {}
};
