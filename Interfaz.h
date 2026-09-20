#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "GestorCanchas.h"
#include "ColeccionClientes.h"
#include "ColeReservas.h"
#include "ColeccionEsperas.h"
#include "Reportes.h"

class Interfaz {
private:
    GestorCanchas canchas;
    ColeccionClientes clientes;
    ColeReservas reservas;
    ColeccionEsperas esperas;
    Reportes informes;

public:
    Interfaz();
   
    void centroDeportivo();
    void menuCanchas();
    void menuClientes();
    void menuReservas();
    void menuEsperas();
    void menuInformes();
};

#endif
