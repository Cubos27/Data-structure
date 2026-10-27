#include <iostream>
#include "lista.hpp"

void bubble_sort(ListaDoble *lista, int n){
    bool bandera;

    for (int i=0; i<n; i++){
        bandera = false;
        for (int j=0; j < n-1; j++){
            if (1 == 1) {
                lista->intercambio(0);
                bandera = true;
            }
        }
    }
    lista->intercambio(5);
}

int main(){
    ListaDoble *lista = new ListaDoble();
    lista->insertarInicio(5);
    lista->insertarInicio(2);
    lista->insertarInicio(10);
    lista->insertarInicio(22);
    lista->insertarInicio(12);
    lista->mostrarTodo();
    bubble_sort(lista, lista->tamanho());
    lista->mostrarTodo();
    return 0;
}
