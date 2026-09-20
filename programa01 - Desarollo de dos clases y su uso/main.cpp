/*
Debera de hacer un proyecto con las siguentes especificaciones:

    Realizar dos clases cada uno: con 3 atributos, y 4 metodos
    El nivel de acceso de todos sus elementos debera ser publico 
    Realice dos instancias/objetos en el archivo main.cpp 
    Utilice todos los metodos de las dos instacias que creo en el main

Nota 01: 
Sus dudas y errores, discutalo en la clase para que se pueda resolverel problema; en caso de tener mas dudas, 
apúntelas para poder discutirlas y resolverlas en clase. 

Nota 02: 
Este ejercio lo entregara en un archivo comprimido, el cual tendra la extension .zip
*/

#include <iostream>
#include <cstdlib>
#include "confiesa.hpp"
#include "negado.hpp"

using namespace std;

int procesoDilema(bool desicion, bool desicionComplice) {
    if (desicionComplice == true && desicion == true)
        return 6;
    if (desicionComplice == true && desicion == false)
        return 10;
    if (desicionComplice == false && desicion == true)
        return 0;
    if (desicionComplice == false && desicion == false)
        return 1;
    return -1;
}

void menu() {
    cout << "==========================" << endl;
    cout << "   DILEMA DEL PRISIONERO  " << endl;
    cout << "==========================" << endl;

    cout << "La policía arresta a dos sospechosos." << endl;
    cout << "No hay pruebas suficientes para condenarlos y, tras haberlos separado, los visita a cada uno y les ofrece el mismo trato." << endl;
    cout << "Si uno confiesa y su cómplice no, el cómplice será condenado a la pena total, diez años, y el primero será liberado." << endl;
    cout << "Si uno calla y el cómplice confiesa, el primero recibirá esa pena y será el cómplice quien salga libre." << endl;
    cout << "Si ambos confiesan, ambos serán condenados a seis años." << endl;
    cout << "Si ambos lo niegan, todo lo que podrán hacer será encerrarlos durante un año por un cargo menor." << endl;

    cout << "1. Ningún prisionero confiesa" << endl;
    cout << "2. Ambos prisioneros confiesan" << endl;
    cout << "3. Un prisionero confiesa y el otro no" << endl;
    cout << "4. Salir" << endl;
    cout << "Selecciona una opción (1-4): ";
}

void pausarYLimpiar() {
    cout << "Presiona ENTER para continuar...";
    
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    
    cin.get();
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int opcion;
    Negado juan = Negado("Juan");
    Negado jose = Negado("Jose");

    do {
        opcion = 0;
        menu();
        cin >> opcion;

        juan.setCondena(0);
        jose.setCondena(0);
        switch (opcion) {
            case 1: {
                juan.setCondena(procesoDilema(juan.decidirAccion(), jose.confesion));
                jose.setCondena(procesoDilema(jose.decidirAccion(), juan.confesion));
                break;
            }
            case 2: {
                juan.setCondena(procesoDilema(juan.decidirAccion(), jose.confesion));
                jose.setCondena(procesoDilema(jose.decidirAccion(), juan.confesion));
                break;
            }
            case 3: {
                juan.setCondena(procesoDilema(juan.decidirAccion(), jose.confesion));
                jose.setCondena(procesoDilema(jose.decidirAccion(), juan.confesion));
                break;
            }
            case 4: {
                cout << "\nSaliendo del programa\n";
                break;
            }
            default:
                cout << "\nOpcion inválida.\n";
        }

        if (opcion != 4){
            cout << "\nEl primero recibió " << juan.getCondena() << " años de prisión" << endl;
            cout << "El complice recibió " << jose.getCondena() << " años de prisión\n" << endl;
        }

        pausarYLimpiar();
    } while (opcion != 4);
    return 0;
}