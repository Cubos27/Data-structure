#pragma once

#include <iostream>

class Negado {
    public:
        std::string nombre;
        int anosCondena;
        bool confesion;
        
        Negado(std::string _nombre) {
            nombre = _nombre;
            anosCondena = 0;
            confesion = false;
        }

        bool decidirAccion() {
            std::cout << nombre << " no confiesa.\n";
            return confesion;
        }

        void setCondena(int condena) {
            anosCondena = condena;
        }

        int getCondena() {
            return anosCondena;
        }
};