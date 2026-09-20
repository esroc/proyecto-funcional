#include <iostream>
#include "Interfaz.h"

using namespace std;

Interfaz::Interfaz()
    : informes(&reservas, &canchas) {
    ColeReservas::setListaEspera(&esperas);
}


void Interfaz::centroDeportivo() {

    int opcionPrincipal;

    do {
        cout << "********************CENTRO DEPORTIVO ZONA ACTIVA**********************" << endl;
        cout << "1. Gestion de canchas" << endl;
        cout << "2. Gestion de clientes" << endl;
        cout << "3. Gestion de reservas" << endl;
        cout << "4. Listado de espera" << endl;
        cout << "5. Informes y estadisticas" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionPrincipal;

        if (opcionPrincipal == 1) {
            menuCanchas();
        }

        else if (opcionPrincipal == 2) {
            menuClientes();
        }

        else if (opcionPrincipal == 3) {
            menuReservas();
        }

        else if (opcionPrincipal == 4) {
            menuEsperas();
        }

        else if (opcionPrincipal == 5) {
            menuInformes();
        }

    } while (opcionPrincipal != 6);

    cout << "Programa finalizado." << endl;
}

void Interfaz::menuCanchas() {

    int opcionCanchas;

    do {
        cout << "********************GESTION DE CANCHAS*********************" << endl;
        cout << "1. Registrar cancha" << endl;
        cout << "2. Mostrar canchas" << endl;
        cout << "3. Buscar cancha" << endl;
        cout << "4. Modificar precio" << endl;
        cout << "5. Mostrar disponibilidad" << endl;
        cout << "6. Modificar disponibilidad" << endl;
        cout << "7. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcionCanchas;

        if (opcionCanchas == 1) {

            string codigo;
            string deporte;
            double precio;

            cout << "Codigo: ";
            cin >> codigo;

            cout << "Deporte: ";
            cin >> deporte;

            cout << "Precio por hora: ";
            cin >> precio;

            canchas.registrarCancha(codigo, deporte, precio);
        }

        else if (opcionCanchas == 2) {

            canchas.mostrarTodas();
        }

        else if (opcionCanchas == 3) {

            string codigo;

            cout << "Codigo de la cancha: ";
            cin >> codigo;

            Cancha* cancha = canchas.buscarPorCodigo(codigo);

            if (cancha != nullptr) {
                cancha->mostrarCancha();
            }
            else {
                cout << "Cancha no encontrada." << endl;
            }
        }

        else if (opcionCanchas == 4) {

            string codigo;
            double precio;

            cout << "Codigo de la cancha: ";
            cin >> codigo;

            cout << "Nuevo precio por hora: ";
            cin >> precio;

            canchas.modificarPrecio(codigo, precio);
        }

        else if (opcionCanchas == 5) {

            string codigo;

            cout << "Codigo de la cancha: ";
            cin >> codigo;

            canchas.mostrarDisponibilidad(codigo);
        }

        else if (opcionCanchas == 6) {

            string codigo;
            int horaInicial;
            int horaFinal;
            int opcionEstado;

            cout << "Codigo de la cancha: ";
            cin >> codigo;

            Cancha* cancha = canchas.buscarPorCodigo(codigo);
            if (cancha == nullptr) {
                cout << "Cancha no encontrada." << endl;
            }
            else {
                cout << "Franja inicial (0 a 11): ";
                cin >> horaInicial;

                cout << "Franja final (0 a 11): ";
                cin >> horaFinal;

                if (horaInicial < 0 || horaFinal > 11 || horaInicial > horaFinal) {
                    cout << "Rango de franjas invalido." << endl;
                }
                else {
                    cout << "Seleccione el nuevo estado:" << endl;
                    cout << "1. Libre" << endl;
                    cout << "2. Ocupado" << endl;
                    cout << "3. Mantenimiento" << endl;
                    cout << "4. Quitar mantenimiento" << endl;
                    cout << "Opcion: ";
                    cin >> opcionEstado;

                    if (opcionEstado == 1) {
                        cancha->liberar(horaInicial, horaFinal);
                        cout << "Franja marcada como libre." << endl;
                    }
                    else if (opcionEstado == 2) {
                        cancha->ocupado(horaInicial, horaFinal);
                        cout << "Franja marcada como ocupada." << endl;
                    }
                    else if (opcionEstado == 3) {
                        cancha->mantenimiento(horaInicial, horaFinal);
                        cout << "Franja marcada como mantenimiento." << endl;
                    }
                    else if (opcionEstado == 4) {
                        cancha->quitarMant(horaInicial, horaFinal);
                        cout << "Mantenimiento quitado." << endl;
                    }
                    else {
                        cout << "Opcion no valida." << endl;
                    }
                }
            }
        }

    } while (opcionCanchas != 7);
}


void Interfaz::menuClientes() {

    int opcionClientes;

    do {
        cout << "******************GESTION DE CLIENTES********************" << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Mostrar clientes" << endl;
        cout << "3. Buscar cliente" << endl;
        cout << "4. Mostrar reservas de un cliente" << endl;
        cout << "5. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcionClientes;

        if (opcionClientes == 1) {

            string nombre;
            int telefono;
            int id;

            cout << "Identificacion: ";
            cin >> id;

            if (clientes.buscarCliente(id) != nullptr) {

                cout << "Ese cliente ya existe." << endl;
            }
            else {

                cout << "Nombre: ";
                cin.ignore();
                getline(cin, nombre);

                cout << "Telefono: ";
                cin >> telefono;

                Cliente* nuevo =
                    new Cliente(nombre, telefono, id);

                clientes.agregarCliente(nuevo);

                cout << "Cliente registrado." << endl;
            }
        }

        else if (opcionClientes == 2) {

            clientes.mostrarClientes();
        }

        else if (opcionClientes == 3) {

            int id;

            cout << "Identificacion: ";
            cin >> id;

            Cliente* cliente =
                clientes.buscarCliente(id);

            if (cliente != nullptr) {

                cout << cliente->toString() << endl;
            }
            else {

                cout << "Cliente no encontrado." << endl;
            }
        }

        else if (opcionClientes == 4) {

            int id;
            cout << "Identificacion del cliente: ";
            cin >> id;

            if (clientes.buscarCliente(id) == nullptr) {
                cout << "Cliente no encontrado." << endl;
            }
            else {
                reservas.mostrarReservasCliente(id);
            }
        }

    } while (opcionClientes != 5);
}


void Interfaz::menuReservas() {

    int opcionReservas;

    do {
        cout << "******************GESTION DE RESERVAS******************" << endl;
        cout << "1. Registrar reserva" << endl;
        cout << "2. Mostrar reservas" << endl;
        cout << "3. Buscar reserva" << endl;
        cout << "4. Mostrar reservas de una cancha" << endl;
        cout << "5. Cancelar reserva" << endl;
        cout << "6. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcionReservas;

        if (opcionReservas == 1) {

            int id;
            string codigo;
            int horaInicial;
            int cantidad;

            cout << "Identificacion del cliente: ";
            cin >> id;

            Cliente* cliente =
                clientes.buscarCliente(id);

            if (cliente == nullptr) {

                cout << "Cliente no encontrado." << endl;
            }
            else {

                cout << "Codigo de la cancha: ";
                cin >> codigo;

                Cancha* cancha =
                    canchas.buscarPorCodigo(codigo);

                if (cancha == nullptr) {

                    cout << "Cancha no encontrada." << endl;
                }
                else {

                    cancha->mostrarDis();

                    cout << "Franja inicial (0 a 11): ";
                    cin >> horaInicial;

                    cout << "Cantidad de horas: ";
                    cin >> cantidad;

                    if (horaInicial < 0 || cantidad <= 0 || horaInicial + cantidad > 12) {
                        cout << "Franja horaria invalida." << endl;
                    }
                    else if (cancha->libre(horaInicial, horaInicial + cantidad - 1)) {
                        Reserva* nueva =
                            reservas.registrarReserva(
                                cliente,
                                cancha,
                                horaInicial,
                                cantidad
                            );

                        if (nueva != nullptr) {
                            cout << "Reserva registrada con numero: "
                                 << nueva->getnumReser()
                                 << endl;
                        }
                    }
                    else {
                        char respuesta;
                        cout << "La franja ya esta ocupada, desea agregarlo a la lista de espera? (s/n): ";
                        cin >>respuesta;

                        if (respuesta == 's') {
                            if (esperas.existeClienteEsperando(cancha, horaInicial, cantidad)) {
                                cout << "Ese cliente ya se encuentra en lista de espera para esa cancha y franja." << endl;
                            }
                            else {
                                Espera* nuevo = new Espera(0, cliente, cancha, horaInicial, cantidad, "esperando");
                                esperas.RegistrarCliente(nuevo);
                                cout << "Cliente agregado a la lista de espera." << endl;
                            }
                        }
                        else {
                            cout << "Reserva no realizada." << endl;
                        }
                    }
                }
            }
        }

        else if (opcionReservas == 2) {

            reservas.mostrarT();
        }

        else if (opcionReservas == 3) {

            int numero;

            cout << "Numero de reserva: ";
            cin >> numero;

            Reserva* reserva =
                reservas.buscarReserva(numero);

            if (reserva != nullptr) {

                reserva->mostrarReserva();
            }
            else {

                cout << "Reserva no encontrada." << endl;
            }
        }

        else if (opcionReservas == 4) {

            string codigo;

            cout << "Codigo de la cancha: ";
            cin >> codigo;

            reservas.mostrarXcancha(codigo);
        }

        else if (opcionReservas == 5) {

            int numero;

            cout << "Numero de reserva: ";
            cin >> numero;

            reservas.cancelarReserva(numero);
        }

    } while (opcionReservas != 6);
}
void Interfaz::menuEsperas() {

    int lista;

   do {
        cout << "***********LISTA DE ESPERA **********" << endl;
        cout << "1. Registrar cliente en lista de espera" << endl;
        cout << "2. Mostrar lista de espera" << endl;
        cout << "3. Cambiar estado" << endl;
        cout << "4. Volver" << endl;
        cout << "Opcion: ";
        cin >> lista;

        if (lista == 1) {

            int idCliente;
            string codigoCancha;
            int horaInicial;
            int cantidadHoras;

            cout << "Identificacion del cliente: ";
            cin >> idCliente;

            Cliente* cliente = clientes.buscarCliente(idCliente);
            if (cliente == nullptr) {
                cout << "Cliente no encontrado." << endl;
            }
            else {
                cout << "Codigo de la cancha: ";
                cin >> codigoCancha;

                Cancha* cancha = canchas.buscarPorCodigo(codigoCancha);
                if (cancha == nullptr) {
                    cout << "Cancha no encontrada." << endl;
                }
                else {
                    cout << "Franja inicial (0 a 11): ";
                    cin >> horaInicial;

                    cout << "Cantidad de horas: ";
                    cin >> cantidadHoras;

                    if (horaInicial < 0 || cantidadHoras <= 0 || horaInicial + cantidadHoras > 12) {
                        cout << "Franja horaria invalida." << endl;
                    }
                    else if (cancha->libre(horaInicial, horaInicial + cantidadHoras - 1)) {
                        cout << "La franja solicitada no esta ocupada; no puede registrarse en espera." << endl;
                    }
                    else if (esperas.existeClienteEsperando(cancha, horaInicial, cantidadHoras)) {
                        cout << "Ese cliente ya se encuentra en espera para esa cancha y franja." << endl;
                    }
                    else {
                        Espera* nuevo = new Espera(0, cliente, cancha, horaInicial, cantidadHoras, "esperando");
                        esperas.RegistrarCliente(nuevo);
                    }
                }
            }
        }

        else if (lista == 2) {

            cout << esperas.mostrarListado();
        }

        else if (lista == 3) {

            esperas.cambiarEstado(&reservas);
        }

    } while (lista != 4);
}
void Interfaz::menuInformes() {

    int opcionInformes;

    do {
        cout << "***************INFORMES*************" << endl;
        cout << "1. Cancha con mas reservas activas" << endl;
        cout << "2. Cliente con mas reservas activas" << endl;
        cout << "3. Ingreso total" << endl;
        cout << "4. Porcentaje de ocupacion" << endl;
        cout << "5. Horas con mas y menos reservas" << endl;
        cout << "6. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcionInformes;

        if (opcionInformes == 1) {

            informes.canchaMayor();
        }

        else if (opcionInformes == 2) {

            informes.clienteMayor();
        }

        else if (opcionInformes == 3) {

            informes.ingresoTotal();
        }

        else if (opcionInformes == 4) {

            informes.porcentajeOcupacion();
        }

        else if (opcionInformes == 5) {

            informes.horasMayorMenor();
        }

    } while (opcionInformes != 6);
}
