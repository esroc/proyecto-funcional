#include <iostream>
#include "Reportes.h"
#include "ColeReservas.h"
using namespace std;
Reportes::Reportes(ColeReservas* c,GestorCanchas* g){
    cole=c;
    gestor=g;
}
void Reportes::canchaMayor(){
    Cancha* mayor=nullptr;
    int mayorCant=0;
    for(int i=0;i<gestor->getCantidad();i++){
        Cancha* can=gestor->getCancha(i);
        int contador=0;
        
        for(int j=0;j<cole->getCanti();j++){
            Reserva* reserv= cole->getReserva(j);

            if(reserv !=nullptr && reserv->getEstado()=="activa" && reserv->getCancha()->getCodigo()==can->getCodigo()){
                contador++;
            }
        }
        if(contador>mayorCant){
            mayorCant=contador;
            mayor=can;
        }
    }
    cout<<"****************Cancha Con Más Reservas*******************"<<endl;
    if(mayor!=nullptr){
        mayor->mostrarCancha();
        cout<<"Reservas activas: "<<mayorCant<<endl;
    }else{
        cout<<"No hay reservas activas"<<endl;
    }
}
void Reportes::clienteMayor(){
    Cliente* mayor=nullptr;
    int mayorCant=0;

    for(int i=0;i<cole->getCanti();i++){
        Reserva* reserv1=cole->getReserva(i);
        if(reserv1!= nullptr && reserv1->getEstado() == "activa") {
            Cliente* cli = reserv1->getCliente();
            int contador = 0;

            for (int j = 0; j < cole->getCanti(); j++) {
                Reserva* reser2 = cole->getReserva(j);

                if (reser2 != nullptr && reser2->getEstado() == "activa" && reser2->getCliente()->getId() == cli->getId()) {
                    contador++;
                }
            }

            if (contador > mayorCant) {
                mayorCant = contador;
                mayor = cli;
            }
        }
    }
    cout<<"******** Cliente Con Mas Reservas ********"<<endl;
    if (mayor != nullptr) {
        cout<<"Nombre: "<<mayor->getNombre()<<endl;
        cout<<"Numero: "<<mayor->getNumero()<<endl;
        cout<<"ID: "<<mayor->getId()<<endl;
        cout<<"Reservas activas: "<<mayorCant<<endl;

    } else {

        cout<<"No hay reservas activas"<<endl;
    }
}


void Reportes::ingresoTotal() {
    double total = 0;

    cout<<"******** Ingresos ********"<<endl;

    for (int i = 0; i<cole->getCanti(); i++) {
        Reserva* reser = cole->getReserva(i);

        if (reser != nullptr && reser->getEstado() == "activa") {
            cout<<"Reserva: "<< reser->getnumReser()<<endl;
            cout<<"Cliente: "<< reser->getCliente()->getNombre()<<endl;
            cout<<"Monto: "<< reser->getMonto()<<endl;
            cout<<"------------------------"<<endl;

            total = total + reser->getMonto();
        }
    }

    cout<<"Ingreso total: "<< total<<endl;
}
void Reportes::porcentajeOcupacion() {

    cout<<"******** Porcentaje De Ocupacion ********"<<endl;

    for (int i = 0;i<gestor->getCantidad();i++) {
        Cancha* can = gestor->getCancha(i);
        int ocupadas = 0;

        for (int j = 0; j < cole->getCanti(); j++) {
            Reserva* reser = cole->getReserva(j);

            if (reser != nullptr && reser->getEstado() == "activa" && reser->getCancha()->getCodigo() == can->getCodigo()) {
                ocupadas = ocupadas + reser->getCant();
            }
        }

        double porcentaje=(ocupadas * 100.0) / 12;

        cout<<"Cancha: "<< can->getCodigo()<< endl;
        cout<<"Deporte: "<< can->getDeporte()<< endl;
        cout<<"Franjas ocupadas: "<<ocupadas<<" de 12"<< endl;
        cout<<"Porcentaje: "<<porcentaje<<"%"<< endl;
        cout<<"**********************************************"<< endl;
    }
}

void Reportes::horasMayorMenor() {
    int horas[12];
    for (int i = 0; i < 12; i++) {
        horas[i] = 0;
    }
    for (int i = 0; i<cole->getCanti(); i++) {
        Reserva* reser=cole->getReserva(i);
        if (reser != nullptr && reser->getEstado() == "activa") {
            int inicio=reser->getInicial();
            int cant=reser->getCant();
            for(int j=inicio;j<inicio+cant;j++) {
                if (j >= 0 && j < 12) {
                    horas[j]++;
                }
            }
        }
    }
    int mayor = horas[0];
    int menor = horas[0];
    for (int i = 1; i < 12; i++) {
        if (horas[i] > mayor) {
            mayor = horas[i];
        }
        if (horas[i] < menor) {
            menor = horas[i];
        }
    }
    cout<<"******** Horas Con Mayor Y Menor Cantidad ********"<<endl;
    cout<<"Hora con mayor cantidad:"<<endl;
    for (int i = 0; i < 12; i++) {
        if (horas[i] == mayor) {
            cout<<i + 8<<":00 - "<<i + 9<<":00";
            cout<<" | Reservas: "<< horas[i]<<endl;
        }
    }
    cout<< endl;
    cout<<"Hora con menor cantidad:"<<endl;
    for (int i = 0; i < 12; i++) {
        if (horas[i] == menor) {
            cout<< i + 8 << ":00 - "<< i + 9 << ":00";
            cout<<" | Reservas: "<<horas[i]<<endl;
        }
    }
}
    
