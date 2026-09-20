#include <iostream>
#include <limits>
#include <string>

#include "nodo.hpp"
#include "listaSimple.hpp"

int menu() {
    int opcion = -1;

    std::cout << "\n========================================\n";
    std::cout << "  MENU - LISTA SIMPLE DE ALUMNOS\n";
    std::cout << "========================================\n";
    std::cout << " 1. Insertar al inicio\n";
    std::cout << " 2. Insertar al final\n";
    std::cout << " 3. Insertar en posicion\n";
    std::cout << " 4. Buscar alumno\n";
    std::cout << " 5. Eliminar alumno\n";
    std::cout << " 6. Eliminar todo\n";
    std::cout << " 7. Verificar si esta vacia\n";
    std::cout << " 8. Mostrar todos los alumnos\n";
    std::cout << " 9. Obtener primer alumno\n";
    std::cout << "10. Obtener ultimo alumno\n";
    std::cout << "11. Obtener alumno anterior\n";
    std::cout << "12. Obtener alumno siguiente\n";
    std::cout << "13. Obtener tamaño de la lista\n";
    std::cout << " 0. Salir\n";
    std::cout << "========================================\n";
    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;
    return opcion;
}

Alumno leerAlumno() {
    std::string nombre, codigo, carrera;
    int edad;
    float promedio;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese el codigo: ";
    std::getline(std::cin, codigo);

    std::cout << "Ingrese la edad: ";
    std::cin >> edad;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese la carrera: ";
    std::getline(std::cin, carrera);

    std::cout << "Ingrese el promedio: ";
    std::cin >> promedio;

    return Alumno(nombre, codigo, edad, carrera, promedio);
}

std::string leerCodigo() {
    std::string codigo;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese el codigo del alumno: ";
    std::getline(std::cin, codigo);

    return codigo;
}

int main() {
    int opcion, posicion;
    ListaSimple* lista = new ListaSimple();
    Nodo* nodo = nullptr;

    do {
        opcion = menu();

        switch (opcion) {
            case 1: {
                Alumno alumno = leerAlumno();
                lista->insertarInicio(alumno);
                std::cout << ">> Alumno insertado al inicio.\n";
                break;
            }
            case 2: {
                Alumno alumno = leerAlumno();
                lista->insertarFinal(alumno);
                std::cout << ">> Alumno insertado al final.\n";
                break;
            }
            case 3: {
                std::cout << "Ingrese la posicion (desde 0): ";
                std::cin >> posicion;

                if (posicion < 0 || posicion > lista->getTamanio()) {
                    std::cout << ">> Posicion invalida.\n";
                    break;
                }

                Alumno alumno = leerAlumno();
                lista->insertarPosicion(posicion, alumno);
                std::cout << ">> Alumno insertado en la posicion indicada.\n";
                break;
            }
            case 4: {
                std::string codigo = leerCodigo();
                nodo = lista->buscar(codigo);

                if (nodo != nullptr) {
                    std::cout << "\n>> Datos del alumno encontrado:\n";
                    nodo->dato.mostrarInformacion();
                }
                break;
            }
            case 5: {
                std::string codigo = leerCodigo();

                if (lista->eliminar(codigo)) {
                    std::cout << ">> Alumno eliminado correctamente.\n";
                }
                break;
            }
            case 6:
                lista->eliminarTodo(true);
                break;
            case 7:
                if (lista->vacia()) {
                    std::cout << ">> La lista esta vacia.\n";
                } else {
                    std::cout << ">> La lista contiene alumnos.\n";
                }
                break;
            case 8:
                lista->mostrarTodo();
                break;
            case 9:
                nodo = lista->primero();

                if (nodo != nullptr) {
                    std::cout << ">> Primer alumno:\n";
                    nodo->dato.mostrarInformacion();
                } else {
                    std::cout << ">> La lista esta vacia.\n";
                }
                break;
            case 10:
                nodo = lista->ultimo();

                if (nodo != nullptr) {
                    std::cout << ">> Ultimo alumno:\n";
                    nodo->dato.mostrarInformacion();
                } else {
                    std::cout << ">> La lista esta vacia.\n";
                }
                break;
            case 11: {
                std::string codigo = leerCodigo();
                nodo = lista->anterior(codigo);

                if (nodo != nullptr) {
                    std::cout << ">> Alumno anterior:\n";
                    nodo->dato.mostrarInformacion();
                } else {
                    std::cout << ">> No existe un alumno anterior para ese codigo.\n";
                }
                break;
            }
            case 12: {
                std::string codigo = leerCodigo();
                nodo = lista->siguiente(codigo);

                if (nodo != nullptr) {
                    std::cout << ">> Alumno siguiente:\n";
                    nodo->dato.mostrarInformacion();
                } else {
                    std::cout << ">> No existe un alumno siguiente para ese codigo.\n";
                }
                break;
            }
            case 13:
                std::cout << ">> Tamaño actual de la lista: "
                          << lista->getTamanio()
                          << " alumnos.\n";
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
