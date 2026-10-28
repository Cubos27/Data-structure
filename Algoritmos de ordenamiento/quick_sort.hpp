#include <iostream>
#include "lista.hpp"
#include "nodo.hpp"

int particion(ListaDoble* lista, int low, int high) {
    Nodo* pivotNodo = lista->buscar_posicion(high);
    int pivote = pivotNodo->dato;

    // frontera de los < pivote
    int i = low - 1;

    for (int j = low; j < high; j++) {
        Nodo* actual = lista->buscar_posicion(j);
        if (actual && actual->dato < pivote) {
            i++;
            lista->intercambio_pos(i, j);
        }
    }

    // Coloca el pivote en su lugar
    lista->intercambio_pos(i + 1, high);
    return i + 1;
}

// Quick sort recursivo
void quicksort(ListaDoble* lista, int low, int high) {
    if (low >= high) return; // 0 o 1 elemento ya ordenado

    int pi = particion(lista, low, high);

    // Recursividad
    quicksort(lista, low, pi - 1);
    quicksort(lista, pi + 1, high);
}

// Wrapper
void quicksort(ListaDoble* lista, int n) {
    if (n > 1) quicksort(lista, 0, n - 1);
}

// int main() {
//     std::cout << "============ Ordenamiento Shell ============" << std::endl;

//     ListaDoble *lista = new ListaDoble();
//     lista->insertarInicio(5);
//     lista->insertarInicio(2);
//     lista->insertarInicio(10);
//     lista->insertarInicio(22);
//     lista->insertarInicio(12);
//     lista->insertarFinal(3);
//     lista->insertarFinal(1);

//     std::cout << "Datos sin ordenar" << std::endl;
//     lista->mostrarTodo();
//     quicksort(lista, lista->tamanho());
//     std::cout << "Datos ordenados" << std::endl;
//     lista->mostrarTodo();
//     return 0;
// }