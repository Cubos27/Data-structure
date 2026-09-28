#include <iostream>
#include "nodo.hpp"
#include "listaSimple.hpp"

int menu(){
    int opcion = -1;
    std::cout << "\n========================================\n";
    std::cout << "  MENU - LISTA SIMPLEMENTE ENLAZADA\n";
    std::cout << "========================================\n";
    std::cout << " 1. Insertar al inicio\n";
    std::cout << " 2. Insertar al final\n";
    std::cout << " 3. Insertar en posicion\n";
    std::cout << " 4. Buscar elemento\n";
    std::cout << " 5. Eliminar elemento\n";
    std::cout << " 6. Eliminar todo\n";
    std::cout << " 7. Verificar si esta vacia\n";
    std::cout << " 8. Mostrar todos los elementos\n";
    std::cout << " 9. Obtener primer elemento\n";
    std::cout << "10. Obtener ultimo elemento\n";
    std::cout << "11. Obtener elemento anterior\n";
    std::cout << "12. Obtener elemento siguiente\n";
    std::cout << "13. Obtener tamaño de la lista\n";
    std::cout << " 0. Salir\n";
    std::cout << "========================================\n";
    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;
    return opcion;
}

int main(){
    int opcion, posicion, valor;
    ListaSimple *lista = new ListaSimple();
    Nodo *nodo = nullptr;

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                std::cout << "Ingrese el valor a insertar: ";
                std::cin >> valor;
                lista->insertarInicio(valor);
                break;
            case 2:
                std::cout << "Ingrese el valor a insertar: ";
                std::cin >> valor;
                lista->insertarFinal(valor);
                break;
            case 3:
                std::cout << "Ingrese la posicion (desde 0): ";
                std::cin >> posicion;
                std::cout << "Ingrese el valor a insertar: ";
                std::cin >> valor;
                lista->insertarPosicion(posicion, valor);
                break;
            case 4: {
                std::cout << "Ingrese el valor a buscar: ";
                std::cin >> valor;
                Nodo *nodo = lista->buscar(valor);
                break;
            }
            case 5:
                std::cout << "Ingrese el valor a eliminar: ";
                std::cin >> valor;
                lista->eliminar(valor);
                break;
            case 6:
                lista->eliminarTodo(true);
                std::cout << ">> Todos los elementos fueron eliminados.\n";
                break;
            case 7:
                if (lista->vacia()) {
                    std::cout << ">> La lista esta vacia.\n";
                } else {
                    std::cout << ">> La lista contiene elementos.\n";
                }
                break;
            case 8:
                lista->mostrarTodo();
                break;
            case 9:
                nodo = lista->primero();
                std::cout << ">> El primer valor es " << nodo->dato << std::endl;
                break;
            case 10:
                nodo = lista->ultimo();
                std::cout << ">> El ultimo valor es " << nodo->dato << std::endl;
                break;
            case 11:
                std::cout << "Ingrese el valor de referencia: ";
                std::cin >> valor;
                nodo = lista->anterior(valor);
                std::cout << ">> El valor anterior es " << nodo->dato << std::endl;
                break;
            case 12:
                std::cout << "Ingrese el valor de referencia: ";
                std::cin >> valor;
                nodo = lista->siguiente(valor);
                std::cout << ">> El valor siguiente es " << nodo->dato << std::endl;
                break;
            case 13:
                std::cout << ">> Tamaño actual de la lista: " << lista->getTamanio() << " elementos.\n";
                break;
            case 0:
                std::cout << ">> Saliendo del programa...\n";
                break;
            default:
                std::cout << ">> Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    delete lista;
    return 0;
}