#include <iostream>
#include "GestorCanchas.h"

using namespace std;

GestorCanchas::GestorCanchas() {
    cantidad = 0;
    for (int i = 0; i < MAX_CANCHAS; i++) {
        canchas[i] = nullptr;
    }
}

GestorCanchas::~GestorCanchas() {
    for (int i = 0; i < cantidad; i++) {
        delete canchas[i];
        canchas[i] = nullptr;
    }
}

bool GestorCanchas::existeCodigo(const string& codigo) const {
    for (int i = 0; i < cantidad; i++) {
        if (canchas[i]->getCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

bool GestorCanchas::estaLlena() const {
    return cantidad >= MAX_CANCHAS;
}

bool GestorCanchas::registrarCancha(const string& codigo, const string& tipoDeporte, double precioPorHora) {
    if (estaLlena()) {
        cout << "No se pueden registrar mas canchas. Limite alcanzado (" << MAX_CANCHAS << ")." << endl;
        return false;
    }
    if (codigo.empty()) {
        cout << "El codigo no puede estar vacio." << endl;
        return false;
    }
    if (existeCodigo(codigo)) {
        cout << "Ya existe una cancha con el codigo " << codigo << "." << endl;
        return false;
    }
    if (precioPorHora <= 0) {
        cout << "El precio por hora debe ser mayor que cero." << endl;
        return false;
    }

    canchas[cantidad] = new Cancha(codigo, tipoDeporte, precioPorHora);
    cantidad++;
    cout << "Cancha " << codigo << " registrada exitosamente." << endl;
    return true;
}

Cancha* GestorCanchas::buscarPorCodigo(const string& codigo) const {
    for (int i = 0; i < cantidad; i++) {
        if (canchas[i]->getCodigo() == codigo) {
            return canchas[i];
        }
    }
    return nullptr;
}

void GestorCanchas::mostrarTodas() const {
    if (cantidad == 0) {
        cout << "No hay canchas registradas." << endl;
        return;
    }
    cout << "\n--- Listado de canchas (" << cantidad << ") ---" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". Codigo: " << canchas[i]->getCodigo()
             << " | Deporte: " << canchas[i]->getDeporte()
             << " | Precio/hora: " << canchas[i]->getPrecio() << endl;
    }
}

bool GestorCanchas::modificarPrecio(const string& codigo, double nuevoPrecio) {
    if (nuevoPrecio <= 0) {
        cout << "El precio debe ser mayor que cero." << endl;
        return false;
    }
    Cancha* c = buscarPorCodigo(codigo);
    if (c == nullptr) {
        cout << "No se encontro una cancha con el codigo " << codigo << "." << endl;
        return false;
    }
    c->setPrecio(nuevoPrecio);
    cout << "Precio actualizado correctamente." << endl;
    return true;
}

void GestorCanchas::mostrarDisponibilidad(const string& codigo) const {
    Cancha* c = buscarPorCodigo(codigo);
    if (c == nullptr) {
        cout << "No se encontro una cancha con el codigo " << codigo << "." << endl;
        return;
    }
    c->mostrarDis();
}

int GestorCanchas::getCantidad() const {
    return cantidad;
}
Cancha* GestorCanchas::getCancha(int i) const {
    if (i >= 0 && i < cantidad) {
        return canchas[i];
    }
    return nullptr;
}