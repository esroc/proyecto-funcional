#include<iostream>
#include "Cliente.h"
#include "Canchas.h"
using namespace std;

//espera.h

class Espera{
private:
    int consecutivo;
    Cliente* cliente;
    Cancha* cancha;
    int horaInicial;
    int horaFinal;
public:
    Espera();
    Espera(Cliente* _cliente, Cancha* _cancha, int _horaInicial, int _horaFinal);

    void mostrarReservas();
    //Registrar reservas verificando la existencia del cliente y de la cancha, la validez de las franjas solicitadas y su disponibilidad.
    void buscarReserva(int consecutivo);
    void reservasCancha(Cancha* _cancha);

};