#include<iostream>
#include "ColeccionEsperas.h"
#include "ColeReservas.h"
#include <sstream>
using namespace std;

ColeccionEsperas::ColeccionEsperas(){
    esperas = new Espera*[20];
    cantidad = 0;
    contador = 0;
    for (int i=0;i<20;i++) {
        esperas[i] = NULL;
    }
}

ColeccionEsperas::~ColeccionEsperas() {
    for (int i=0;i<cantidad;i++) {
        delete esperas[i];
    }
    delete[] esperas;
}

void ColeccionEsperas::RegistrarCliente(Espera* clienteEspera) {
    if (cantidad < capacidad) {
        esperas[cantidad] = clienteEspera;
        cantidad++;
        contador++;
        cout << "Cliente registrado correctamente en la lista" << endl;
        clienteEspera->setConsecutivo(contador);
    } else {
        cout << "No se pudo agregar al cliente" << endl;
    }
}

string ColeccionEsperas::mostrarListado() {
    stringstream s;
    if (cantidad == 0) {
        s << "La lista esta vacia"<<endl;
    } else {
        for (int i =0;i<cantidad;i++) {
            if (esperas[i] != NULL) {
                s << esperas[i]->toString() << endl;
            }
        }
    }
    return s.str();
}

bool ColeccionEsperas::existeClienteEsperando(Cancha* cancha, int horaInicial, int franja) const {
    for (int i = 0; i < cantidad; i++) {
        if (esperas[i] != NULL &&
            esperas[i]->getCancha() == cancha &&
            esperas[i]->getHoraInicial() == horaInicial &&
            esperas[i]->getFranja() == franja &&
            esperas[i]->getEstado() == "esperando") {
            return true;
        }
    }
    return false;
}

bool ColeccionEsperas::existeClienteEsperandoEnRango(Cancha* cancha, int horaInicialReserva, int franjaReserva) const {
    if (franjaReserva <= 0) {
        return false;
    }

    int reservaInicio = horaInicialReserva;
    int reservaFin = horaInicialReserva + franjaReserva - 1;

    for (int i = 0; i < cantidad; i++) {
        if (esperas[i] != NULL &&
            esperas[i]->getCancha() == cancha &&
            esperas[i]->getEstado() == "esperando") {

            int esperaInicio = esperas[i]->getHoraInicial();
            int esperaFin = esperas[i]->getHoraInicial() + esperas[i]->getFranja() - 1;

            bool solapa = !(esperaFin < reservaInicio || esperaInicio > reservaFin);
            if (solapa) {
                return true;
            }
        }
    }
    return false;
}

string ColeccionEsperas::obtenerClientesEsperando(Cancha* cancha, int horaInicial, int franja) const {
    stringstream s;
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (esperas[i] != NULL &&
            esperas[i]->getCancha() == cancha &&
            esperas[i]->getHoraInicial() == horaInicial &&
            esperas[i]->getFranja() == franja &&
            esperas[i]->getEstado() == "esperando") {
            s << "- " << esperas[i]->getCliente()->getNombre() << " (" << esperas[i]->getEstado() << ")" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        return "No existen clientes esperando para esa cancha y franja horaria.";
    }

    return s.str();
}

string ColeccionEsperas::obtenerClientesEsperandoEnRango(Cancha* cancha, int horaInicialReserva, int franjaReserva) const {
    stringstream s;
    bool encontrado = false;

    if (franjaReserva <= 0) {
        return "No existen clientes esperando para esa cancha y franja horaria.";
    }

    int reservaInicio = horaInicialReserva;
    int reservaFin = horaInicialReserva + franjaReserva - 1;

    for (int i = 0; i < cantidad; i++) {
        if (esperas[i] != NULL &&
            esperas[i]->getCancha() == cancha &&
            esperas[i]->getEstado() == "esperando") {

            int esperaInicio = esperas[i]->getHoraInicial();
            int esperaFin = esperas[i]->getHoraInicial() + esperas[i]->getFranja() - 1;

            bool solapa = !(esperaFin < reservaInicio || esperaInicio > reservaFin);
            if (solapa) {
                s << "- " << esperas[i]->getCliente()->getNombre() << " (esperando)" << endl;
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        return "No existen clientes esperando para esa cancha y franja horaria.";
    }

    return s.str();
}

void ColeccionEsperas::cambiarEstado(ColeReservas* coleReservas) {
    int consecutivoBuscado;
    cout << "Ingrese el numero consecutivo de la espera a modificar: ";
    cin >> consecutivoBuscado;

    bool encontrado = false;
    for (int i=0;i<cantidad;i++) {
        if (esperas[i] != NULL && esperas[i]->getConsecutivo() == consecutivoBuscado) {
            encontrado = true;
            int opcion;
            cout<<"Seleccione el nuevo estado:"<<endl;
            cout<<"1. Esperando"<<endl;
            cout<<"2. Asignado"<<endl;
            cout<<"3. Cancelado"<<endl;
            cout<<"Opcion: ";
            cin >>opcion;

            if (opcion == 1) {
                esperas[i]->setEstado("esperando");
                cout << "Estado cambiado a: esperando"<<endl;
            } else if (opcion == 2) {
                esperas[i]->setEstado("asignado");

                Cancha* canchaAsignada = esperas[i]->getCancha();
                Cliente* clienteAsignado = esperas[i]->getCliente();
                int horaInicio = esperas[i]->getHoraInicial();
                int duracion = esperas[i]->getFranja();

                Reserva* reservaAsignada = new Reserva(clienteAsignado, canchaAsignada, horaInicio, duracion);

                if (coleReservas != nullptr) {
                    coleReservas->agregarReserva(reservaAsignada);
                }

                cout << "Se creo la reserva asignada con numero: " << reservaAsignada->getnumReser() << endl;
                cout << "Estado cambiado a: asignado"<<endl;
            } else if (opcion == 3) {
                esperas[i]->setEstado("cancelado");
                cout << "Estado cambiado a: cancelado"<<endl;
            } else {
                cout << "Opcion no valida";
            }
            break;
        }
    }

    if (encontrado == false) {
        cout << "No se encontro ningun registro de espera con ese consecutivo"<<endl;
    }
}