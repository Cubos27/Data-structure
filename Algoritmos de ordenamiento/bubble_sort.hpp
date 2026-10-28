#include <iostream>
#include "nodo.hpp"
#include "lista.hpp"

void bubble_sort(ListaDoble *lista, int n){
    bool bandera;

    for (int i=0; i<n; i++){
        bandera = false;

        for (int j=0; j < n-1; j++){
            Nodo *a = lista->buscar_posicion(j);
            Nodo *b = lista->buscar_posicion(j+1);

            if (a && b && a->dato > b->dato) {
                lista->intercambio(j);
                bandera = true;
            }
        }
    }
}

// int main(){
//     std::cout << "============ Ordenamiento burbuja mejorada ============" << std::endl;

//     ListaDoble *lista = new ListaDoble();
//     lista->insertarInicio(5);
//     lista->insertarInicio(2);
//     lista->insertarInicio(10);
//     lista->insertarInicio(22);
//     lista->insertarInicio(12);
//     lista->insertarFinal(3);

//     std::cout << "Datos sin ordenar" << std::endl;
//     lista->mostrarTodo();
//     bubble_sort(lista, lista->tamanho());
//     std::cout << "Datos ordenados" << std::endl;
//     lista->mostrarTodo();
//     return 0;
// }
