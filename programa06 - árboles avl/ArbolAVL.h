#pragma once

#include <algorithm>   // std::max
#include <functional>  // std::function
#include <iostream>
#include <stdexcept>
#include <string>

#include "Nodo.h"

/**
 * ArbolAVL
 * --------
 * Árbol binario de búsqueda autobalanceable (Adelson-Velsky y Landis).
 *
 * Invariante AVL: para TODO nodo, |altura(izq) - altura(der)| <= 1.
 * Esto garantiza altura O(log n) y, por tanto, insertar, eliminar y
 * buscar en O(log n) incluso en el peor caso (un BST normal puede
 * degenerar en una lista enlazada con O(n)).
 *
 * Requisito para T: solo necesita operator<. La igualdad se deduce con
 * !(a < b) && !(b < a), igual que hacen los contenedores de la STL.
 *
 * Gestión de memoria: cada nodo se crea con `new` y se libera con `delete`
 * en eliminar(), vaciar() y en el destructor (RAII).
 */
template <typename T>
class ArbolAVL {
public:
    ArbolAVL() : raiz(nullptr), cantidad(0) {}

    // Destructor: libera TODA la memoria dinámica del árbol.
    ~ArbolAVL() { vaciar(); }

    // Regla de los tres: el árbol es dueño de punteros crudos, así que una
    // copia superficial (copiar solo el puntero raiz) produciría un
    // "double delete". Prohibimos la copia para evitar ese error de raíz.
    ArbolAVL(const ArbolAVL&) = delete;
    ArbolAVL& operator=(const ArbolAVL&) = delete;

    // ======================= API PÚBLICA =======================

    /** Inserta un valor. Devuelve false si ya existía (no se permiten duplicados). */
    bool insertar(const T& valor) {
        bool insertado = false;
        raiz = insertar(raiz, valor, insertado);
        if (insertado) ++cantidad;
        return insertado;
    }

    /** Elimina un valor. Devuelve false si no existía. */
    bool eliminar(const T& valor) {
        bool eliminado = false;
        raiz = eliminar(raiz, valor, eliminado);
        if (eliminado) --cantidad;
        return eliminado;
    }

    /**
     * Busca un valor. Devuelve un puntero al dato almacenado o nullptr si
     * no existe. Se devuelve puntero const para que el usuario NO pueda
     * modificar la clave y romper el orden del árbol.
     */
    const T* buscar(const T& valor) const {
        // Búsqueda iterativa: evita el costo de la pila de llamadas.
        const Nodo<T>* actual = raiz;
        while (actual != nullptr) {
            if (valor < actual->dato)       actual = actual->izquierdo;
            else if (actual->dato < valor)  actual = actual->derecho;
            else                            return &actual->dato;
        }
        return nullptr;
    }

    bool contiene(const T& valor) const { return buscar(valor) != nullptr; }

    /** Menor valor del árbol. Lanza excepción si está vacío. */
    const T& minimo() const {
        if (!raiz) throw std::underflow_error("El arbol esta vacio");
        return nodoMinimo(raiz)->dato;
    }

    /** Mayor valor del árbol. Lanza excepción si está vacío. */
    const T& maximo() const {
        if (!raiz) throw std::underflow_error("El arbol esta vacio");
        const Nodo<T>* actual = raiz;
        while (actual->derecho) actual = actual->derecho;
        return actual->dato;
    }

    bool estaVacio() const { return raiz == nullptr; }
    std::size_t tamanio() const { return cantidad; }
    int altura() const { return obtenerAltura(raiz); }

    /** Elimina todos los nodos y libera la memoria. */
    void vaciar() {
        destruir(raiz);
        raiz = nullptr;
        cantidad = 0;
    }

    // ---------- Recorridos (reciben una función para procesar cada dato) ----------
    void inOrden(const std::function<void(const T&)>& visitar) const { inOrden(raiz, visitar); }
    void preOrden(const std::function<void(const T&)>& visitar) const { preOrden(raiz, visitar); }
    void postOrden(const std::function<void(const T&)>& visitar) const { postOrden(raiz, visitar); }

    /** Dibuja el árbol de lado (la raíz a la izquierda) con su factor de balance. */
    void imprimirEstructura() const {
        if (!raiz) { std::cout << "(arbol vacio)\n"; return; }
        imprimirEstructura(raiz, 0);
    }

private:
    Nodo<T>* raiz;
    std::size_t cantidad;

    // ======================= UTILIDADES DE ALTURA =======================

    // Altura de un puntero que puede ser nulo (un subárbol vacío mide 0).
    static int obtenerAltura(const Nodo<T>* nodo) {
        return nodo ? nodo->altura : 0;
    }

    // Recalcula la altura de un nodo a partir de la de sus hijos. Debe
    // invocarse siempre DESPUÉS de modificar los hijos de un nodo.
    static void actualizarAltura(Nodo<T>* nodo) {
        nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierdo),
                                    obtenerAltura(nodo->derecho));
    }

    // Factor de balance = altura(izq) - altura(der).
    //   > 1  : demasiado pesado a la izquierda
    //   < -1 : demasiado pesado a la derecha
    static int factorBalance(const Nodo<T>* nodo) {
        return nodo ? obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho) : 0;
    }

    // ======================= ROTACIONES =======================
    //
    // Una rotación cambia la forma del árbol SIN alterar el recorrido
    // in-orden (es decir, conserva la propiedad de BST) y en O(1).
    // Es la herramienta que usa el AVL para reducir la altura.

    /**
     * Rotación simple a la DERECHA (caso Izquierda-Izquierda).
     *
     *        y                x
     *       / \              / \
     *      x   C    --->    A   y
     *     / \                  / \
     *    A   B                B   C
     *
     * Orden se conserva: A < x < B < y < C.
     * El subárbol B (que estaba a la derecha de x) pasa a ser hijo
     * izquierdo de y: sigue siendo mayor que x y menor que y.
     *
     * Orden de actualización de alturas: primero `y` (ahora es hijo) y
     * luego `x` (ahora es padre), porque la altura de x depende de la de y.
     */
    Nodo<T>* rotarDerecha(Nodo<T>* y) {
        Nodo<T>* x = y->izquierdo;
        Nodo<T>* B = x->derecho;

        x->derecho = y;
        y->izquierdo = B;

        actualizarAltura(y);
        actualizarAltura(x);
        return x;  // Nueva raíz de este subárbol; el llamador debe enlazarla.
    }

    /**
     * Rotación simple a la IZQUIERDA (caso Derecha-Derecha). Es el espejo
     * de rotarDerecha.
     *
     *      x                    y
     *     / \                  / \
     *    A   y      --->      x   C
     *       / \              / \
     *      B   C            A   B
     */
    Nodo<T>* rotarIzquierda(Nodo<T>* x) {
        Nodo<T>* y = x->derecho;
        Nodo<T>* B = y->izquierdo;

        y->izquierdo = x;
        x->derecho = B;

        actualizarAltura(x);
        actualizarAltura(y);
        return y;
    }

    /**
     * balancear: corazón del AVL. Se llama en el camino de vuelta de la
     * recursión (post-orden) tanto en insertar como en eliminar, para
     * restaurar el invariante en cada ancestro afectado.
     *
     * Hay 4 casos de desbalance:
     *  - Izquierda-Izquierda  (fb > 1  y hijo izq. con fb >= 0): rotación derecha.
     *  - Izquierda-Derecha    (fb > 1  y hijo izq. con fb <  0): rotación izquierda
     *                          sobre el hijo + rotación derecha (rotación doble).
     *  - Derecha-Derecha      (fb < -1 y hijo der. con fb <= 0): rotación izquierda.
     *  - Derecha-Izquierda    (fb < -1 y hijo der. con fb >  0): rotación derecha
     *                          sobre el hijo + rotación izquierda (rotación doble).
     *
     * IMPORTANTE: usamos ">= 0" y "<= 0" (no solo > 0 / < 0) para el caso
     * simple. Con eliminación el hijo puede tener factor 0, y en ese caso
     * una rotación simple es la correcta; usar la doble dejaría el árbol
     * desbalanceado. En inserción ese factor 0 nunca ocurre, por eso este
     * detalle solo se nota al eliminar.
     */
    Nodo<T>* balancear(Nodo<T>* nodo) {
        actualizarAltura(nodo);
        const int fb = factorBalance(nodo);

        if (fb > 1) {                                   // Pesado a la izquierda
            if (factorBalance(nodo->izquierdo) < 0)     // Caso Izquierda-Derecha
                nodo->izquierdo = rotarIzquierda(nodo->izquierdo);
            return rotarDerecha(nodo);                  // Izq-Izq (o 2.º paso del doble)
        }

        if (fb < -1) {                                  // Pesado a la derecha
            if (factorBalance(nodo->derecho) > 0)       // Caso Derecha-Izquierda
                nodo->derecho = rotarDerecha(nodo->derecho);
            return rotarIzquierda(nodo);                // Der-Der (o 2.º paso del doble)
        }

        return nodo;  // Ya estaba balanceado
    }

    // ======================= INSERTAR (recursivo) =======================

    /**
     * Se devuelve el puntero al (posible) nuevo nodo raíz del subárbol en
     * vez de usar Nodo*&. Así, cuando una rotación cambia la raíz del
     * subárbol, el padre simplemente reasigna su hijo con el valor
     * retornado y el árbol queda correctamente enlazado.
     * `insertado` indica si realmente se creó un nodo (para llevar el conteo).
     */
    Nodo<T>* insertar(Nodo<T>* nodo, const T& valor, bool& insertado) {
        if (nodo == nullptr) {
            insertado = true;
            return new Nodo<T>(valor);   // Memoria dinámica
        }

        if (valor < nodo->dato)
            nodo->izquierdo = insertar(nodo->izquierdo, valor, insertado);
        else if (nodo->dato < valor)
            nodo->derecho = insertar(nodo->derecho, valor, insertado);
        else
            return nodo;                 // Duplicado: no se modifica nada

        return balancear(nodo);          // Rebalancea al volver de la recursión
    }

    // ======================= ELIMINAR (recursivo) =======================

    /**
     * Tres casos al encontrar el nodo:
     *  1. Hoja: se libera y se devuelve nullptr.
     *  2. Un solo hijo: se libera el nodo y el hijo lo reemplaza.
     *  3. Dos hijos: no se puede quitar el nodo sin romper el árbol, así
     *     que se copia el SUCESOR IN-ORDEN (el menor del subárbol derecho)
     *     al nodo actual y luego se elimina ese sucesor, que tiene como
     *     máximo un hijo (caso 1 o 2). El sucesor es el valor inmediatamente
     *     mayor, por lo que mantiene el orden del BST.
     *
     * Diferencia clave con insertar: al eliminar, UNA sola rotación puede
     * no ser suficiente en toda la ruta; por eso se llama a balancear() en
     * cada ancestro al volver de la recursión, no solo en el primero.
     */
    Nodo<T>* eliminar(Nodo<T>* nodo, const T& valor, bool& eliminado) {
        if (nodo == nullptr) return nullptr;     // No encontrado

        if (valor < nodo->dato) {
            nodo->izquierdo = eliminar(nodo->izquierdo, valor, eliminado);
        } else if (nodo->dato < valor) {
            nodo->derecho = eliminar(nodo->derecho, valor, eliminado);
        } else {
            eliminado = true;

            if (nodo->izquierdo == nullptr || nodo->derecho == nullptr) {
                // Casos 1 y 2: a lo sumo un hijo
                Nodo<T>* hijo = nodo->izquierdo ? nodo->izquierdo : nodo->derecho;
                delete nodo;                     // Liberamos la memoria dinámica
                return hijo;                     // Puede ser nullptr (hoja)
            }

            // Caso 3: dos hijos
            const Nodo<T>* sucesor = nodoMinimo(nodo->derecho);
            nodo->dato = sucesor->dato;
            // Se elimina el sucesor del subárbol derecho. Se usa una copia
            // local del dato porque `sucesor->dato` desaparece al hacer delete.
            bool auxiliar = false;
            const T datoSucesor = nodo->dato;
            nodo->derecho = eliminar(nodo->derecho, datoSucesor, auxiliar);
        }

        return balancear(nodo);
    }

    // Nodo más a la izquierda = valor mínimo del subárbol.
    static const Nodo<T>* nodoMinimo(const Nodo<T>* nodo) {
        while (nodo->izquierdo) nodo = nodo->izquierdo;
        return nodo;
    }

    // ======================= RECORRIDOS =======================

    void inOrden(const Nodo<T>* nodo, const std::function<void(const T&)>& visitar) const {
        if (!nodo) return;
        inOrden(nodo->izquierdo, visitar);
        visitar(nodo->dato);
        inOrden(nodo->derecho, visitar);
    }

    void preOrden(const Nodo<T>* nodo, const std::function<void(const T&)>& visitar) const {
        if (!nodo) return;
        visitar(nodo->dato);
        preOrden(nodo->izquierdo, visitar);
        preOrden(nodo->derecho, visitar);
    }

    void postOrden(const Nodo<T>* nodo, const std::function<void(const T&)>& visitar) const {
        if (!nodo) return;
        postOrden(nodo->izquierdo, visitar);
        postOrden(nodo->derecho, visitar);
        visitar(nodo->dato);
    }

    // ======================= LIBERAR MEMORIA =======================

    /**
     * Debe ser POST-ORDEN: primero se liberan los hijos y al final el
     * nodo. Si liberáramos el padre primero perderíamos los punteros a
     * sus hijos (fuga de memoria / acceso a memoria liberada).
     */
    void destruir(Nodo<T>* nodo) {
        if (!nodo) return;
        destruir(nodo->izquierdo);
        destruir(nodo->derecho);
        delete nodo;
    }

    // ======================= DEPURACIÓN =======================

    // Recorrido derecha -> raíz -> izquierda para dibujar el árbol girado 90°.
    void imprimirEstructura(const Nodo<T>* nodo, int nivel) const {
        if (!nodo) return;
        imprimirEstructura(nodo->derecho, nivel + 1);
        std::cout << std::string(nivel * 6, ' ') << nodo->dato
                  << " (fb=" << factorBalance(nodo) << ")\n";
        imprimirEstructura(nodo->izquierdo, nivel + 1);
    }
};
