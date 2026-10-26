#include <iostream>
#include "pila/pila.hpp"
#include "pila/gato.hpp"
#include "cola/cola.hpp"
#include "cola/perro.hpp"


int menuCola() {
    int opcion = -1;
    std::cout << "\n========================================\n";
    std::cout << "  MENU - Perro\n";
    std::cout << "========================================\n";
    std::cout << " 1. Encolar (insertar al final)\n";
    std::cout << " 2. Desencolar (eliminar del frente)\n";
    std::cout << " 3. Ver el frente (primero)\n";
    std::cout << " 4. Ver el final (ultimo)\n";
    std::cout << " 5. Verificar si esta vacia\n";
    std::cout << " 6. Obtener tamaño de la cola\n";
    std::cout << " 7. Eliminar todos los elementos\n";
    std::cout << " 0. Salir\n";
    std::cout << "========================================\n";
    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;
    return opcion;
}

int menuPila() {
    int opcion = -1;
    std::cout << "\n========================================\n";
    std::cout << "  MENU - Gato\n";
    std::cout << "========================================\n";
    std::cout << " 1. Apilar (push)\n";
    std::cout << " 2. Desapilar (pop)\n";
    std::cout << " 3. Ver el tope (cima)\n";
    std::cout << " 4. Verificar si esta vacia\n";
    std::cout << " 5. Obtener tamaño de la pila\n";
    std::cout << " 6. Eliminar todos los elementos\n";
    std::cout << " 0. Salir\n";
    std::cout << "========================================\n";
    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;
    return opcion;
}

int menuPerroGato() {
    int op;
    do {
        std::cout << "Escribe 1 para elegir perros y 2 para gatos: \n";
        std::cin >> op;
        if (op != 1 && op != 2) std::cout << "Opcion invalida. Elige una opcion entre 1 y 2";
    } while (op != 1 && op != 2);
    return op;
}

void insertarPerro(Cola* cola) {
    std::string nombre;
    std::string raza;
    int edad;
    float peso;
    std::string color;

    std::cout << "\n=== DATOS DEL PERRO ===\n";

    std::cout << "Nombre: ";
    std::cin >> nombre;

    std::cout << "Raza: ";
    std::cin >> raza;

    std::cout << "Edad: ";
    std::cin >> edad;

    std::cout << "Peso: ";
    std::cin >> peso;

    std::cout << "Color: ";
    std::cin >> color;

    Perro perro(nombre, raza, edad, peso, color);

    cola->encolar(perro);

    std::cout << "\nPerro insertado correctamente.\n";
}

void insertarGato(Pila* pila) {
    std::string nombre;
    std::string raza;
    int edad;
    float peso;
    std::string color;

    std::cout << "\n=== DATOS DEL GATO ===\n";

    std::cout << "Nombre: ";
    std::cin >> nombre;

    std::cout << "Raza: ";
    std::cin >> raza;

    std::cout << "Edad: ";
    std::cin >> edad;

    std::cout << "Peso: ";
    std::cin >> peso;

    std::cout << "Color: ";
    std::cin >> color;

    Gato gato(nombre, raza, edad, peso, color);

    pila->apilar(gato);

    std::cout << "\nGato insertado correctamente.\n";
}

int main(){
    int animal = menuPerroGato();
    int opcion;

    if (animal == 1) { // Animal == perro
        Cola *cola = new Cola();
        do {
            opcion = menuCola();
            switch (opcion) {
            case 1: // Encolar
                insertarPerro(cola);
                break;
            case 2: // Desencolar
                if (!cola->vacia()) {
                    Perro *perro = cola->desencolar();
                    std::cout << "Perro desencolado:\n";
                    perro->mostrar();
                    delete perro;
                } else {
                    std::cout << "La cola esta vacia. No se puede desencolar.\n";
                }
                break;

            case 3: // Ver el frente
                if (!cola->vacia()) {
                    Perro *perro = cola->frente();
                    std::cout << "Perro en el frente:\n";
                    perro->mostrar();
                } else {
                    std::cout << "La cola esta vacia.\n";
                }
                break;

            case 4: // Ver el final
                if (!cola->vacia()) {
                    Perro *perro = cola->final();
                    std::cout << "Perro en el final:\n";
                    perro->mostrar();
                } else {
                    std::cout << "La cola esta vacia.\n";
                }
                break;

            case 5: // Verificar si esta vacia
                if (cola->vacia()) {
                    std::cout << "La cola SI esta vacia.\n";
                } else {
                    std::cout << "La cola NO esta vacia.\n";
                }
                break;

            case 6: // Tamanio
                std::cout << "El tamaño de la cola es: " << cola->getTamanio() << "\n";
                break;

            case 7: // Eliminar todos los elementos
                while (!cola->vacia()) {
                    cola->desencolar();
                }
                std::cout << "Todos los elementos han sido eliminados.\n";
                break;

            case 0: // Salir
                std::cout << "Saliendo del programa...\n";
                break;

            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
        } while (opcion != 0);
    } else { 
        // Animal == gato
        Pila *pila = new Pila();
        do {
            opcion = menuPila();
            switch (opcion) {
            case 1: // Apilar
                insertarGato(pila);
                break;

            case 2: // Desapilar
                if (!pila->vacia()) {
                    Gato *gato = pila->desapilar();
                    std::cout << "Gato desapilado:\n";
                    gato->mostrar();
                    delete gato;
                } else {
                    std::cout << "La pila esta vacia. No se puede desapilar.\n";
                }
                break;

            case 3: // Ver cima
                if (!pila->vacia()) {
                    Gato *gato = pila->cima();
                    std::cout << "Gato en la cima:\n";
                    gato->mostrar();
                } else {
                    std::cout << "La pila esta vacia.\n";
                }
                break;

            case 4: // Verificar si esta vacia
                if (pila->vacia()) {
                    std::cout << "La pila SI esta vacia.\n";
                } else {
                    std::cout << "La pila NO esta vacia.\n";
                }
                break;

            case 5: // Tamanio
                std::cout << "El tamaño de la pila es: " << pila->getTamanio() << "\n";
                break;

            case 6: // Eliminar todos los elementos
                while (!pila->vacia()) {
                    pila->desapilar();
                }
                std::cout << "Todos los elementos han sido eliminados.\n";
                break;

            case 0: // Salir
                std::cout << "Saliendo del programa...\n";
                break;

            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
                break;
            }
        } while (opcion != 0);
    }

    return 0;
}