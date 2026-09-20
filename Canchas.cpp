#include <iostream>
#include "Canchas.h"
using namespace std;

const int MAX = 10;   // maximo de canchas

// Constructor por defecto: todo libre
Cancha::Cancha() {
    codigo[0] = '\0';
    deporte[0] = '\0';
    precio = 0.0;
    for (int i = 0; i < 12; i++) v[i] = 'L';
}

// Constructor con datos: todo libre
Cancha::Cancha(char cod[], char dep[], double pre) {
    int i = 0;
    while (cod[i] != '\0' && i < LARGO - 1) {
        codigo[i] = cod[i];
        i++;
    }
    codigo[i] = '\0';

    i = 0;
    while (dep[i] != '\0' && i < LARGO - 1) {
        deporte[i] = dep[i];
        i++;
    }
    deporte[i] = '\0';

    precio = pre;
    for (int i = 0; i < 12; i++) v[i] = 'L';
}

Cancha::Cancha(const std::string& cod, const std::string& dep, double pre) {
    int i = 0;
    for (i = 0; i < LARGO - 1 && i < (int)cod.size(); i++) {
        codigo[i] = cod[i];
    }
    codigo[i] = '\0';

    i = 0;
    for (i = 0; i < LARGO - 1 && i < (int)dep.size(); i++) {
        deporte[i] = dep[i];
    }
    deporte[i] = '\0';

    precio = pre;
    for (int i = 0; i < 12; i++) v[i] = 'L';
}

// Getters: devuelven el arreglo interno
char* Cancha::getCodigo() { return codigo; }
char* Cancha::getDeporte() { return deporte; }
double Cancha::getPrecio() { return precio; }

// Setter del precio
void Cancha::setPrecio(double nuevoPrecio) {
    precio = nuevoPrecio;
}

// Mostrar los datos de la cancha
void Cancha::mostrarCancha() {
    cout << "Codigo: " << codigo << endl;
    cout << "Deporte: " << deporte << endl;
    cout << "Precio x hora: " << precio << endl;
}

// Mostrar las 12 franjas (horas, estados, posiciones)
void Cancha::mostrarDis() {
    cout << "Disponibilidad de la cancha " << codigo << endl;
    cout << "********************************" << endl;

    int hora = 8;
    for (int i = 0; i < 12; i++) {
        cout << hora << ":00  ";
        hora++;
    }
    cout << endl;

    for (int i = 0; i < 12; i++) {
        cout << " " << v[i] << "    ";
    }
    cout << endl;

    for (int i = 0; i < 12; i++) {
        cout << "[" << i << "]  ";
    }
    cout << endl;
}

// Ver si un rango de franjas esta libre (todas en L)
bool Cancha::libre(int horaInicial, int horaFinal) {
    if (horaInicial < 0 || horaFinal > 11 || horaInicial > horaFinal) {
        return false;
    }
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] != 'L') {
            return false;
        }
    }
    return true;
}

// Marcar un rango como ocupado (O)
void Cancha::ocupado(int horaInicial, int horaFinal) {
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] == 'L') v[i] = 'O';
    }
}

// Volver un rango a libre (L)
void Cancha::liberar(int horaInicial, int horaFinal) {
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] == 'O') v[i] = 'L';
    }
}

// Marcar un rango como mantenimiento (M)
void Cancha::mantenimiento(int horaInicial, int horaFinal) {
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] == 'L') v[i] = 'M';
    }
}

// Quitar mantenimiento (volver a L)
void Cancha::quitarMant(int horaInicial, int horaFinal) {
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] == 'M') v[i] = 'L';
    }
}

// Comparar dos cadenas de char (devuelve true si son iguales)
bool sonIguales(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

// Buscar una cancha por codigo; devuelve la posicion o -1
int buscarCancha(Cancha canchas[], int total, char codigo[]) {
    for (int i = 0; i < total; i++) {
        if (sonIguales(canchas[i].getCodigo(), codigo)) return i;
    }
    return -1;
}


