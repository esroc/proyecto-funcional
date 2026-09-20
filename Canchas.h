#ifndef CANCHA_H
#define CANCHA_H

#include <iostream>
#include <string>

using namespace std;

const int LARGO = 30;
const int CANCHAS = 10;

class Cancha {
private:
    char codigo[LARGO];
    char deporte[LARGO];
    double precio;
    char v[12];  // Guarda: L, O, M

public:
    Cancha();
    Cancha(char cod[], char dep[], double pre);
    Cancha(const std::string& cod, const std::string& dep, double pre);

    char* getCodigo();
    char* getDeporte();
    double getPrecio();
    void setPrecio(double nuevoPrecio);

    void mostrarCancha();
    void mostrarDis();  // las 12

    bool libre(int horaInicial, int horaFinal);
    void ocupado(int horaInicial, int horaFinal);      // marca como O
    void liberar(int horaInicial, int horaFinal);      // marca como L
    void mantenimiento(int horaInicial, int horaFinal);// marca como M
    void quitarMant(int horaInicial, int horaFinal);   // vuelve a L
};

#endif