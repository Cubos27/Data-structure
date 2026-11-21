#include <iostream>
#include <string>
#include "Grafo.hpp"

using namespace std;

string leerTexto(const string& mensaje) {
    string s;
    cout << mensaje;
    getline(cin, s);
    return s;
}

int leerOpcion() {
    try {
        return stoi(leerTexto(""));
    } catch (...) {
        return -1;
    }
}

double leerPeso() {
    while (true) {
        try {
            return stod(leerTexto("Peso: "));
        } catch (...) {
            cout << "Peso no valido, intente de nuevo.\n";
        }
    }
}

void mostrarMenu() {
    cout << "\n===== MENU - GRAFO PONDERADO =====\n";
    cout << "1. Insertar vertice\n";
    cout << "2. Insertar arista\n";
    cout << "3. Eliminar vertice\n";
    cout << "4. Eliminar arista\n";
    cout << "5. Imprimir listado de vertices/aristas\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    Grafo grafo(false);  // false = no dirigido, true = dirigido
    int opcion;

    do {
        mostrarMenu();
        opcion = leerOpcion();

        switch (opcion) {
            case 1: {
                string nombre = leerTexto("Nombre del vertice: ");
                cout << (grafo.insertarVertice(nombre)
                             ? "Vertice insertado.\n"
                             : "No se pudo insertar: ya existe.\n");
                break;
            }
            case 2: {
                string origen = leerTexto("Vertice origen: ");
                string destino = leerTexto("Vertice destino: ");
                double peso = leerPeso();
                cout << (grafo.insertarArista(origen, destino, peso)
                             ? "Arista insertada.\n"
                             : "No se pudo insertar: algun vertice no existe o la arista ya existe.\n");
                break;
            }
            case 3: {
                string nombre = leerTexto("Vertice a eliminar: ");
                cout << (grafo.eliminarVertice(nombre)
                             ? "Vertice eliminado.\n"
                             : "No se pudo eliminar: el vertice no existe.\n");
                break;
            }
            case 4: {
                string origen = leerTexto("Vertice origen: ");
                string destino = leerTexto("Vertice destino: ");
                cout << (grafo.eliminarArista(origen, destino)
                             ? "Arista eliminada.\n"
                             : "No se pudo eliminar: algun vertice no existe o no hay arista.\n");
                break;
            }
            case 5:
                grafo.imprimir();
                break;
            case 0:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpcion no valida, intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
