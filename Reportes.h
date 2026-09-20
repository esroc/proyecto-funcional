#ifndef REPORTES_H
#define REPORTES_H
#include<iostream>
#include "ColeReservas.h"
#include "GestorCanchas.h"
using namespace std;
class Reportes{
    private:
    ColeReservas* cole;
    GestorCanchas* gestor;
    public:
    Reportes(ColeReservas* c, GestorCanchas* g);
    void canchaMayor();
    void clienteMayor();
    void ingresoTotal();
    void porcentajeOcupacion();
    void horasMayorMenor();
};
#endif