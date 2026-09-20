#include <iostream>
#include "Cliente.h"
#include <sstream>
using namespace std;

//cliente.cpp

Cliente::Cliente(string _nombre, int _numero, int _id) {
    nombre = _nombre;
    numero = _numero;
    id = _id;
}

Cliente::Cliente() {
    nombre = "Vacio";
    numero = 0;
    id = 0;
}

string Cliente::getNombre() const {
    return nombre;
}

int Cliente::getNumero() const {
    return numero;
}

int Cliente::getId() const {
    return id;
}

void Cliente::setNombre(string _nombre) {
    nombre = _nombre;
}

void Cliente::setNumero(int _numero) {
    numero = _numero;
}

void Cliente::setId(int _id) {
    id = _id;
}

string Cliente::toString() {
    stringstream ss;
    ss << "Nombre: " << nombre << ", Numero: " << numero <<", Id:"<<id<<endl;
    return ss.str();
}