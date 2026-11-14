#include <iostream>
#include "ArbolAVL.h"

static void imprimirInOrden(const ArbolAVL<int>& arbol) {
    std::cout << "In-orden: ";
    arbol.inOrden([](const int& v) { std::cout << v << ' '; });
    std::cout << "\n";
}

int main() {
    ArbolAVL<int> arbol;

    // Inserción ascendente: en un BST normal esto crearía una lista de
    // 7 niveles; en el AVL las rotaciones mantienen la altura en 3.
    std::cout << "=== Insertando 10..70 en orden ascendente ===\n";
    for (int v = 10; v <= 70; v += 10) arbol.insertar(v);
    arbol.imprimirEstructura();
    std::cout << "Altura: " << arbol.altura() << ", tamanio: " << arbol.tamanio() << "\n";
    imprimirInOrden(arbol);

    std::cout << "\n=== Duplicado (20) ===\n";
    std::cout << (arbol.insertar(20) ? "Insertado" : "Rechazado (ya existe)") << "\n";

    std::cout << "\n=== Busquedas ===\n";
    for (int v : {40, 99}) {
        const int* r = arbol.buscar(v);
        std::cout << v << (r ? " encontrado" : " NO encontrado") << "\n";
    }
    std::cout << "Minimo: " << arbol.minimo() << ", Maximo: " << arbol.maximo() << "\n";

    std::cout << "\n=== Eliminando 40 (nodo con dos hijos) ===\n";
    arbol.eliminar(40);
    arbol.imprimirEstructura();
    imprimirInOrden(arbol);

    std::cout << "\n=== Eliminando 10, 20 y 30 (provoca rotaciones) ===\n";
    arbol.eliminar(10);
    arbol.eliminar(20);
    arbol.eliminar(30);
    arbol.imprimirEstructura();
    std::cout << "Altura: " << arbol.altura() << ", tamanio: " << arbol.tamanio() << "\n";

    std::cout << "\n=== Eliminar inexistente (999) ===\n";
    std::cout << (arbol.eliminar(999) ? "Eliminado" : "No existe") << "\n";

    // El destructor libera toda la memoria dinámica automáticamente.
    return 0;
}
