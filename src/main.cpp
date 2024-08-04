#include "estructuras.h"
#include "panel.h"
#include "mantenimiento.h"
#include "gestion.h"
#include "tienda.h"
#include "registros.h"
#include "clientes.h"
#include <iostream>
#include <algorithm>

// Definir vectores globales
std::vector<Usuario> usuarios;
std::vector<Disposicion> habitaciones;
std::vector<Tienda> productos;
std::vector<int> pisos;
std::vector<Categoria> categorias;
Hotel hotel;

void inicializarDatosHotel() {
    std::cout << "Bienvenido. Por favor, ingrese los datos del hotel:\n";
    std::cout << "Nombre del administrador: ";
    std::cin.ignore(); // Para limpiar el buffer de entrada
    std::getline(std::cin, hotel.nombreAdmin);
    std::cout << "Contraseña del administrador: ";
    std::getline(std::cin, hotel.contrasenaAdmin);
    std::cout << "Nombre del hotel: ";
    std::getline(std::cin, hotel.nombreHotel);
}

void crearPisos() {
    int opcion;
    do {
        std::cout << "Crear/Eliminar Pisos:\n";
        std::cout << "1. Añadir piso\n";
        std::cout << "2. Eliminar piso\n";
        std::cout << "0. Volver al menú anterior\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int nuevoPiso;
                std::cout << "Ingrese el número del nuevo piso: ";
                std::cin >> nuevoPiso;
                if (std::find(pisos.begin(), pisos.end(), nuevoPiso) == pisos.end()) {
                    pisos.push_back(nuevoPiso);
                } else {
                    std::cout << "El piso ya existe.\n";
                }
                break;
            }
            case 2: {
                int pisoEliminar;
                std::cout << "Ingrese el número del piso a eliminar: ";
                std::cin >> pisoEliminar;
                auto it = std::find(pisos.begin(), pisos.end(), pisoEliminar);
                if (it != pisos.end()) {
                    pisos.erase(it);
                } else {
                    std::cout << "El piso no existe.\n";
                }
                break;
            }
            case 0:
                std::cout << "Volviendo al menú anterior...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);
}

void crearCategorias() {
    int opcion;
    do {
        std::cout << "Crear/Eliminar Categorías:\n";
        std::cout << "1. Crear categoría\n";
        std::cout << "2. Eliminar categoría\n";
        std::cout << "0. Volver al menú anterior\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                Categoria nuevaCategoria;
                std::cout << "Ingrese el nombre de la nueva categoría: ";
                std::cin.ignore();
                std::getline(std::cin, nuevaCategoria.nombreCategoria);
                std::cout << "Ingrese el precio de la nueva categoría: ";
                std::cin >> nuevaCategoria.precio;
                auto it = std::find_if(categorias.begin(), categorias.end(), 
                                       [&](const Categoria& cat) { return cat.nombreCategoria == nuevaCategoria.nombreCategoria; });
                if (it == categorias.end()) {
                    categorias.push_back(nuevaCategoria);
                } else {
                    std::cout << "La categoría ya existe.\n";
                }
                break;
            }
            case 2: {
                std::string categoriaEliminar;
                std::cout << "Ingrese el nombre de la categoría a eliminar: ";
                std::cin.ignore();
                std::getline(std::cin, categoriaEliminar);
                auto it = std::find_if(categorias.begin(), categorias.end(), 
                                       [&](const Categoria& cat) { return cat.nombreCategoria == categoriaEliminar; });
                if (it != categorias.end()) {
                    categorias.erase(it);
                } else {
                    std::cout << "La categoría no existe.\n";
                }
                break;
            }
            case 0:
                std::cout << "Volviendo al menú anterior...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);
}

void crearHabitaciones() {
    int opcion;
    do {
        std::cout << "Crear Habitaciones:\n";
        std::cout << "1. Crear habitación\n";
        std::cout << "0. Volver al menú anterior\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                if (pisos.empty()) {
                    std::cout << "No hay pisos disponibles. Por favor, cree al menos un piso primero.\n";
                    break;
                }

                if (categorias.empty()) {
                    std::cout << "No hay categorías disponibles. Por favor, cree al menos una categoría primero.\n";
                    break;
                }

                Disposicion nuevaHabitacion;
                std::cout << "Ingrese el piso: ";
                std::cin >> nuevaHabitacion.piso;
                if (std::find(pisos.begin(), pisos.end(), nuevaHabitacion.piso) == pisos.end()) {
                    std::cout << "El piso no existe. Por favor, seleccione un piso válido.\n";
                    break;
                }
                std::cout << "Ingrese el número de habitación: ";
                std::cin >> nuevaHabitacion.numeroHabitacion;
                std::cout << "Ingrese la categoría (entre las disponibles): ";
                std::cin.ignore();
                std::getline(std::cin, nuevaHabitacion.categoria);
                auto it = std::find_if(categorias.begin(), categorias.end(), 
                                       [&](const Categoria& cat) { return cat.nombreCategoria == nuevaHabitacion.categoria; });
                if (it == categorias.end()) {
                    std::cout << "La categoría no existe. Por favor, seleccione una categoría válida.\n";
                    break;
                }
                nuevaHabitacion.ocupada = false;
                habitaciones.push_back(nuevaHabitacion);
                break;
            }
            case 0:
                std::cout << "Volviendo al menú anterior...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);
}

int main() {
    inicializarDatosHotel();

    std::cout << "Antes de empezar, configure los datos iniciales del hotel.\n";

    int opcionInicial;
    do {
        std::cout << "Configuración Inicial:\n";
        std::cout << "1. Crear/Eliminar Pisos\n";
        std::cout << "2. Crear/Eliminar Categorías\n";
        std::cout << "3. Crear Habitaciones\n";
        std::cout << "0. Finalizar configuración inicial\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcionInicial;

        switch (opcionInicial) {
            case 1:
                crearPisos();
                break;
            case 2:
                crearCategorias();
                break;
            case 3:
                crearHabitaciones();
                break;
            case 0:
                std::cout << "Configuración inicial completada.\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcionInicial != 0);

    std::cout << "Ya está todo listo.\n";

    int opcion;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Mantenimiento\n";
        std::cout << "2. Panel\n";
        std::cout << "3. Gestion\n";
        std::cout << "4. Tienda\n";
        std::cout << "5. Registros\n";
        std::cout << "6. Clientes\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                mantenimiento();
                break;
            case 2:
                panel();
                break;
            case 3:
                gestion();
                break;
            case 4:
                tienda();
                break;
            case 5:
                registros();
                break;
            case 6:
                clientes();
                break;
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 0);

    return 0;
}
