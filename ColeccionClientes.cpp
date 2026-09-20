#include <iostream>
#include "ColeccionClientes.h"
using namespace std;

//coleccionclientes.cpp

ColeccionClientes::ColeccionClientes() {
    capacidad = 100;
    cantidad = 0;
    clientes = new Cliente*[capacidad];
    for(int i = 0; i < capacidad; i++) {
       clientes[i] = NULL;
    }
}
ColeccionClientes::~ColeccionClientes() { 
   for(int i = 0; i < cantidad; i++) {
        delete clientes[i];
    }
    delete[] clientes;
}

void ColeccionClientes::agregarCliente(Cliente* cliente) {
    if (cantidad < capacidad) {
    clientes[cantidad] = cliente;
    cantidad++;
    cout<<"cliente agregado correctamente.";
    } 
    else {
    cout << "No se puede agregar más clientes." << endl;
    }
}

void ColeccionClientes::mostrarClientes() {
    for (int i = 0; i < cantidad; i++) {
    cout << clientes[i]->toString() << endl;
    }
}

Cliente* ColeccionClientes::buscarCliente(int id) {
    for(int i = 0; i < cantidad; i++) {
        if(clientes[i]->getId() == id) {
            return clientes[i];
        }
    }
    return NULL;
}

