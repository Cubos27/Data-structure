#include <iostream>
#include <vector>

// Se le da la dirección de memoria del vector para
// poder modificarlo directamente
void shell_sort(std::vector<int> &lista, int n) {
    for (int salto = n/2; salto > 0; salto/=2){
        bool intercambio = false;

        for (int i=salto; i<n; i++){
            int temp = lista[i];
            int j = i;

            while (j+salto < n) {
                if (lista[j] > lista[j+salto]) {
                    // Se hace el intercambio
                    lista[j] = lista[j+salto];
                    lista[j+salto] = temp;
                    // Hubo intercambio, entonces
                    // se cambia la bandera
                    intercambio = true;
                }
                std::cout << "\ni: " << i << " j: " << j << std::endl;
                for (int k=0; k<10; k++){
                    std::cout << lista[i] << ", ";
                }
                // Añadimos uno al contador j
                j++;
            }
        }
        // Si no hubo intercambios, terminamos el bucle
        // porque la lista ya esta ordenada
        if (!intercambio) break;
    }
}

int main() {
    std::cout << "============ Ordenamiento Shell ============" << std::endl;

    std::vector<int> lista = {9, 8, 7, 1, 0, 2, 3, 4, 5, 6};
    int n = static_cast<int>(lista.size());

    std::cout << "Datos sin ordenar:\n";
    for (int i=0; i<n; i++){
        std::cout << lista[i] << ", ";
    }
    
    shell_sort(lista, n);
    std::cout << "\nDatos ordenados:\n";
    for (int i=0; i<10; i++){
        std::cout << lista[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}