#include <iostream>
using namespace std;
#include "ColeReservas.h"

ColeccionEsperas* ColeReservas::listaEspera = nullptr;

ColeReservas::ColeReservas(){
    canti=0;
    for(int i=0;i<MAX_RESERVAS;i++){
        reservas[i]=nullptr;
    }
}
bool ColeReservas::agregarReserva(Reserva* reserva){
    if(canti<MAX_RESERVAS){
        reservas[canti]=reserva;
        canti++;
        return true;
    }else{
        return false;
    }
}
void ColeReservas::mostrarT(){
    if(canti==0){
        cout<<"No hay reservas"<<endl;
    }else{
        for(int i=0;i<canti;i++){
            if(reservas[i]!=nullptr){
            reservas[i]->mostrarReserva();
            }
        }
    }
}
Reserva* ColeReservas::buscarReserva(int num){
    for(int i=0;i<canti;i++){
        if(reservas[i]!=nullptr&&reservas[i]->getnumReser()==num){
            return reservas[i];
        }
    }
    return nullptr;
}
void ColeReservas::mostrarXcancha(string codigo){
    bool encontro=false;
    for(int i=0;i<canti;i++){
        if(reservas[i]!=nullptr&&reservas[i]->getCancha()->getCodigo()==codigo){
            reservas[i]->mostrarReserva();
            encontro=true;
        }
    }
    if(encontro==false){
        cout<<"No hay reservas para esa cancha"<<endl;
    }
}
void ColeReservas::mostrarReservasCliente(int idCliente) const {
    bool encontro = false;

    for (int i = 0; i < canti; i++) {
        if (reservas[i] != nullptr && reservas[i]->getCliente()->getId() == idCliente) {
            reservas[i]->mostrarReserva();
            encontro = true;
        }
    }

    if (!encontro) {
        cout << "El cliente no tiene reservas registradas." << endl;
    }
}
int ColeReservas::getCanti() const {
    return canti;
}

Reserva* ColeReservas::getReserva(int posicion) const {
    if (posicion >= 0 && posicion < canti) {
        return reservas[posicion];
    }
    return nullptr;
}

void ColeReservas::setListaEspera(ColeccionEsperas* nuevaLista) {
    listaEspera = nuevaLista;
}
ColeccionEsperas* ColeReservas::getListaEspera() {
    return listaEspera;
}
bool ColeReservas::cancelarReserva(int num){
    Reserva* reserva=buscarReserva(num);
    if(reserva!=NULL){
        reserva->cancelarReserva();

        if (listaEspera != NULL) {
            int horaInicial = reserva->getInicial();
            int franja = reserva->getCant();
            Cancha* cancha = reserva->getCancha();

            if (listaEspera->existeClienteEsperandoEnRango(cancha, horaInicial, franja)) {
                cout << "Existen clientes esperando para la cancha " << cancha->getCodigo()
                     << " dentro del rango horario " << horaInicial << "-" << (horaInicial + franja - 1) << ":" << endl;
                cout << listaEspera->obtenerClientesEsperandoEnRango(cancha, horaInicial, franja);
            } else {
                cout << "No existen clientes esperando para la cancha " << cancha->getCodigo()
                     << " dentro del rango horario " << horaInicial << "-" << (horaInicial + franja - 1) << "." << endl;
            }
        } else {
            cout << "No hay lista de espera registrada para verificar clientes pendientes." << endl;
        }

        return true;
    }
    cout<<"La reserva no se encontro"<<endl;
        return false;
    }
   Reserva* ColeReservas::registrarReserva(Cliente* cli, Cancha* canch, int horaInicial, int cant) {
    if (canti >= MAX_RESERVAS) {
        cout << "No se pueden registrar mas reservas. Limite alcanzado." << endl;
        return nullptr;
    }
    if (horaInicial < 0 || cant <= 0 || horaInicial + cant > 12) {
        cout << "Franja horaria invalida." << endl;
        return nullptr;
    }
    if (!canch->libre(horaInicial, horaInicial + cant - 1)) {
        cout << "Alguna de las franjas solicitadas no esta libre." << endl;
        return nullptr;
    }

    Reserva* nueva = new Reserva(cli, canch, horaInicial, cant);
    agregarReserva(nueva);
    return nueva;
}
