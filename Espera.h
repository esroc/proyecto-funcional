#ifndef ESPERA_H
#define ESPERA_H

#include<iostream>
#include "Cliente.h"
#include "Canchas.h"
using namespace std;

//espera.h

class Espera{
private:
    int consecutivo = 0;
    Cliente* cliente;
    Cancha* cancha;
    int horaInicial;
    int franja;
    string estado;

public:
    Espera();
    Espera(int consecutivo, Cliente* _cliente, Cancha* _cancha, int _horaInicial, int _franja, string _estado);

    int getConsecutivo() const;
    Cliente* getCliente() const;
    Cancha* getCancha() const;
    int getHoraInicial() const;
    int getFranja() const;
    string getEstado() const;

    void setHoraInicial(int _horaInicial);
    void setFranja(int _franja);
    void setEstado(string _estado);
    void setConsecutivo(int consecutivo);

    string toString() const;
};

#endif