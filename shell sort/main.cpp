#include <iostream>
#include <vector>

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


int main() {
    std::cout << "============ Ordenamiento Shell ============" << std::endl;

    std::vector<int> lista = {9, 8, 7, 1, 0, 2, 3, 4, 5, 6, 8, 1 , 4, 5, 1, 2, 4, 5, 6, 7, 3, 1};
    int n = static_cast<int>(lista.size());

    std::cout << "Datos sin ordenar:\n";
    for (int i=0; i<n; i++){
        std::cout << lista[i] << ", ";
    }
    
    shell_sort_knuth(lista, n);
    std::cout << "\nDatos ordenados:\n";
    for (int i=0; i<n; i++){
        std::cout << lista[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}