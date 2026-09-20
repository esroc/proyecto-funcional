#ifndef COLERESERVAS_H
#define COLERESERVAS_H
#include "Reservas.h"
#include "ColeccionEsperas.h"
#include <string>

const int MAX_RESERVAS = 120;

class ColeReservas{
    private:
    Reserva* reservas[MAX_RESERVAS];
    int canti;
    static ColeccionEsperas* listaEspera;
    public:
    ColeReservas();
    bool agregarReserva(Reserva*reservas);
    void mostrarT();
    Reserva* buscarReserva(int num);
    void mostrarXcancha(string codigo);
    bool cancelarReserva(int num);
    Reserva* registrarReserva(Cliente* cli, Cancha* canch, int horaInicial, int cant);
    void mostrarReservasCliente(int idCliente) const;
    int getCanti() const;
    Reserva* getReserva(int posicion) const;
    static void setListaEspera(ColeccionEsperas* nuevaLista);
    static ColeccionEsperas* getListaEspera();
};
#endif
