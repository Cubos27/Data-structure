#include <iostream>
#include <vector>
#include "lista.hpp"
#include "nodo.hpp"

void shell_sort(std::vector<int> &lista, int n) {
    // Bucle 1: Controla el tamaño del salto
    for (int salto = n/2; salto > 0; salto/=2){

        // Bucle 2: Va moviendo las comparaciones
        for (int i=salto; i<n; i++){
            int temp = lista[i];
            int j;

            // Hace el swipe las veces necesarias para el elemento en posicion i
            for (j=i; j >= salto && lista[j-salto] >= temp; j -= salto) {
                lista[j] = lista[j-salto];
            }
            lista[j] = temp;
        }
    }
}

void shell_sort_knuth(std::vector<int> &lista, int n) {
    // inicializacion de salto
    int salto = 1;
    while (salto < n / 3) {
        salto = 3 * salto + 1;
    }

    // Bucle 1: Controla el tamaño del salto
    while (salto > 0) {

        // Bucle 2: Va moviendo las comparaciones
        for (int i=salto; i<n; i++){
            int temp = lista[i];
            int j;

            // Hace el swipe las veces necesarias para el elemento en posicion i
            for (j=i; j >= salto && lista[j-salto] >= temp; j -= salto) {
                lista[j] = lista[j-salto];
            }
            lista[j] = temp;
        }

        salto = (salto - 1) / 3;
    }
}

void shell_sort_memoria_dinamica(ListaDoble *lista, int n) {
    // Version del salto Knuth
    int salto = 1;
    while (salto < n / 3) {
        salto = 3 * salto + 1;
    }

    // Bucle 1: Controla el tamaño del salto
    while (salto > 0){

        // Bucle 2: Va moviendo las comparaciones
        for (int i=salto; i<n; i++){
            int j=i;

            // Bucle 3: Realiza los intercambios
            for (j; j >= salto; j-=salto){
                Nodo *izq = lista->buscar_posicion(j - salto);
                Nodo *der = lista->buscar_posicion(j);

                if (izq && der && izq->dato > der->dato){
                    lista->intercambio_pos(j-salto, j);

                }
            }
        }
        
        salto = (salto - 1) / 3;
    }
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

//     std::cout << "Datos sin ordenar" << std::endl;
//     lista->mostrarTodo();
//     shell_sort_memoria_dinamica(lista, lista->tamanho());
//     std::cout << "Datos ordenados" << std::endl;
//     lista->mostrarTodo();
//     return 0;
// }