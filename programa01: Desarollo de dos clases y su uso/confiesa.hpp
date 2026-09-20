#pragma once

#include <iostream>

class Confiesa {
    public:
        std::string nombre;
        int anosCondena;
        bool confesion;
        
        Confiesa(std::string _nombre) {
            nombre = _nombre;
            anosCondena = 0;
            confesion = true;
        }

        bool decidirAccion() {
            std::cout << nombre << " confiesa el crimen.\n";
            return confesion;
        }

        void setCondena(int condena) {
            anosCondena = condena;
        }

        int getCondena() {
            return anosCondena;
        }
};