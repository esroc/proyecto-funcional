#ifndef COLECCIONESPERAS_H
#define COLECCIONESPERAS_H

#include <iostream>
#include "Espera.h"
#include "Cliente.h"
using namespace std;

class ColeReservas;

//coleccionespera.h
/*Cuando una cancha se encuentre ocupada en la franja de tiempo deseada por un cliente, el sistema permitirá al usuario
registrar al cliente en un listado de espera, cada registro de espera deberá almacenar:
− Número consecutivo.
− Puntero a cliente interesado.
− Puntero a cancha solicitada.
− Posición de la franja horaria.
− Estado: esperando, atendido o cancelado.
Nota: Se aclara que el “listado de espera” corresponde a un arreglo unidimensional de 10 campos y no a una lista
enlazada.
Un mismo cliente no podrá aparecer dos veces en estado de espera para la misma cancha y franja horaria.
Solo podrán incorporarse clientes al listado de espera cuando la franja solicitada se encuentre ocupada (O). Las franjas que se
encuentren en mantenimiento (M) no generarán registros en el listado de espera.
Las operaciones mínimas serán:
− Registrar un cliente en listado de espera
− Mostrar el listado de espera.
− Cambiar el estado (esperando, asignado o cancelado.) Nota: “asignado” significa que, al liberarse la cancha, ese
cliente obtuvo la reserva, “cancelado” significa que el cliente ya no desea reservar una cancha
Cuando en el modulo de reservas, se cancele una reserva, en ese momento el sistema deberá informar si existen clientes
esperando por esa cancha y franja horaria. */

class ColeccionEsperas{
    private:
    Espera** esperas;
    int const capacidad = 20;
    int cantidad;
    int contador;

    public:
    ColeccionEsperas();
    ~ColeccionEsperas();

    void RegistrarCliente(Espera* clienteEspera);
    string mostrarListado();
    void cambiarEstado(ColeReservas* coleReservas = nullptr);
    bool existeClienteEsperando(Cancha* cancha, int horaInicial, int franja) const;
    string obtenerClientesEsperando(Cancha* cancha, int horaInicial, int franja) const;
    bool existeClienteEsperandoEnRango(Cancha* cancha, int horaInicialReserva, int franjaReserva) const;
    string obtenerClientesEsperandoEnRango(Cancha* cancha, int horaInicialReserva, int franjaReserva) const;

};

#endif