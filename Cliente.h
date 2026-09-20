#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
using namespace std;

//cliente.h

class Cliente{

private:
    string nombre;
    int numero;
    int id;
public:
    Cliente();
    Cliente(string nombre, int numero, int id);

    string getNombre() const;
    int getNumero() const;
    int getId() const;

    void setNombre(string nombre);
    void setNumero(int numero);
    void setId(int id);

    string toString();
};

#endif