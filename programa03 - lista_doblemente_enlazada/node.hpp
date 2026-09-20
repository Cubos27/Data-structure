#pragma once

class Node {
    public:
        Node *ant;
        int dato;
        Node *sig;

        Node(Node *ant, Node *sig, int dato){
            this->ant = ant;
            this->dato = dato;
            this->sig = sig;
        }
};