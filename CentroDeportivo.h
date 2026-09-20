#ifndef CENTRO_DEPORTIVO_H
#define CENTRO_DEPORTIVO_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#include "Cliente.h"
#include "Canchas.h"
#include "ColeccionClientes.h"
#include "ColeReservas.h"
#include "ColeccionEsperas.h"

using namespace std;

class CentroDeportivo {
private:
    ColeccionClientes clientes;
    vector<Cancha> canchas;
    ColeReservas reservas;
    ColeccionEsperas espera;
    int siguienteIdCliente;

    Cancha* buscarCanchaPorCodigo(const string& codigo);
    Cliente* buscarClientePorId(int id);

public:
    CentroDeportivo();

    void registrarCancha(const string& codigo, const string& deporte, double precio);
    void mostrarCanchas();
    void mostrarDisponibilidad(const string& codigo);

    void registrarCliente(const string& nombre, int numero);
    void mostrarClientes();

    void registrarReserva(int idCliente, const string& codigoCancha, int horaInicio, int duracion);
    void mostrarReservas();
    void cancelarReserva(int numeroReserva);

    void registrarEspera(int idCliente, const string& codigoCancha, int horaInicio, int franja);
    void mostrarListaEspera();

    void menu();
};

#endif
