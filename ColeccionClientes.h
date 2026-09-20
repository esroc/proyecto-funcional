#ifndef COLECCIONCLIENTES_H
#define COLECCIONCLIENTES_H

#include <iostream>
#include "Cliente.h"
using namespace std;

//coleccionclientes.h

class ColeccionClientes{
private:
    Cliente** clientes;
    int capacidad = 100;
    int cantidad;

public:
    ColeccionClientes();
    ~ColeccionClientes();

    void agregarCliente(Cliente* cliente);
    void mostrarClientes();
    Cliente* buscarCliente(int id);
};

#endif