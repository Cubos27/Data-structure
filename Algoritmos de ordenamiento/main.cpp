#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lista.hpp"
#include "bubble_sort.hpp"
#include "shell_sort.hpp"
#include "quick_sort.hpp"

void mostrar_menu() {
    std::cout << "\n========= MENÚ ORDENAMIENTO =========\n";
    std::cout << " 1. Bubble Sort\n";
    std::cout << " 2. Shell Sort\n";
    std::cout << " 3. Quick Sort\n";
    std::cout << " 4. Regenerar datos aleatorios\n";
    std::cout << " 5. Ver datos\n";
    std::cout << " 0. Salir\n";
    std::cout << "=====================================\n";
    std::cout << "Opción: ";
}

int main() {
    std::srand(std::time(nullptr));

    // Siempre tendra un tamanho de 10 datos
    int n = 10;
    // Inicializacion de datos aleatorios
    ListaDoble *lista = new ListaDoble();
    for (int i = 0; i < n; i++) lista->insertarFinal(std::rand() % 100);

    int opcion;
    do {
        mostrar_menu();
        // Entrada con manejo de error
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (opcion >= 1 && opcion <= 3) {
            std::cout << "\nDatos originales: \n";
            lista->mostrarTodo();

            switch (opcion) {
                case 1: bubble_sort(lista, n); break;
                case 2: shell_sort_memoria_dinamica(lista, n); break;
                case 3: quicksort(lista, n); break;
            }

            std::cout << "Datos ordenados: \n";
            lista->mostrarTodo();
        }
        else if (opcion == 4) {
            lista->eliminarTodo();
            for (int i = 0; i < n; i++) lista->insertarFinal(std::rand() % 100);
            std::cout << "Datos regenerados.\n";
            lista->mostrarTodo();
        }
        else if (opcion == 5) {
            std::cout << "Datos actuales: ";
            lista->mostrarTodo();
        }
        else if (opcion != 0) {
            std::cout << "Opción no válida.\n";
        }

    } while (opcion != 0);

    std::cout << "Adiós.\n";
    return 0;
}

/* CONCLUSION
Esta practica fue muy importante para aprender a codificar los algoritmos de ordenamiento en
memoria dinamica haciendo uso de una lista doblemente enlazada.

Cada algoritmo de ordenamiento tiene sus ventajas y desventajas, esto es la causa
de que cada uno pueda ser utilizado en diversas situaciones dependiendo el problema a resolver.
Por ello, es importante saber implementar cada uno de ellos, tanto en memoria dinamica como en
memoria estatica.
*/