#pragma once
#include <iostream>
#include "node.hpp"

class ListaDoblementeEnlazada {
    public:
        Node *head = nullptr;
        Node *tail = nullptr;

        void crear() {
            Node *aux = new Node(nullptr, nullptr, 5);
        }
};