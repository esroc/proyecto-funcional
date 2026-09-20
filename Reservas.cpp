#include <iostream>
using namespace std;

#include "Reservas.h"

int Reserva::consecutivo = 1;

Reserva::Reserva(Cliente* cli, Cancha* canch, int ini, int can) {

    numReser = consecutivo;
    consecutivo++;

    cliente = cli;
    cancha = canch;
    horaInicial = ini;
    cant = can;

    monto = cancha->getPrecio() * cant;
    estado = "activa";

    cancha->ocupado(horaInicial, horaInicial + cant - 1);
}

int Reserva::getnumReser() {
    return numReser;
}

Cliente* Reserva::getCliente() {
    return cliente;
}

Cancha* Reserva::getCancha() {
    return cancha;
}

int Reserva::getInicial() {
    return horaInicial;
}

int Reserva::getCant() {
    return cant;
}

double Reserva::getMonto() {
    return monto;
}

string Reserva::getEstado() {
    return estado;
}

void Reserva::mostrarReserva() {

    cout << "****************Reserva*************************" << endl;
    cout << "Cliente: " << cliente->getNombre() << endl;
    cout << "Numero: " << cliente->getNumero() << endl;
    cout << "Cancha: " << cancha->getCodigo() << endl;
    cout << "Deporte: " << cancha->getDeporte() << endl;
    cout << "Hora Inicial: " << horaInicial << endl;
    cout << "Cantidad: " << cant << endl;
    cout << "Monto: " << monto << endl;
    cout << "Estado: " << estado << endl;
}

void Reserva::cancelarReserva() {

    if (estado == "activa") {

        cancha->liberar(horaInicial, horaInicial + cant - 1);
        estado = "cancelada";

        cout << "Reserva cancelada" << endl;

    } else {

        cout << "La reserva ya esta cancelada" << endl;
    }
}
