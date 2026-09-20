#ifndef RESERVAS_H
#define RESERVAS_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Canchas.h"
using namespace std;
class Reserva {
private:
    int numReser;
    Cliente* cliente;
    Cancha* cancha;
    int horaInicial;
    int cant;
    double monto;
    string estado;
    static int consecutivo;
public:
    Reserva(Cliente* cli, Cancha* canch, int ini, int can);
    int getnumReser();
    Cliente* getCliente();
    Cancha* getCancha();
    int getInicial();
    int getCant();
    double getMonto();
    string getEstado();
    void mostrarReserva();
    void cancelarReserva();
};
#endif
