#include "defines.h"
#include "tablero.h"
#include <stdlib.h>
#include "victoria.h"
#include "jugada.h"

void jugada(char tablero[TAM][TAM]) {
    bool jugada = false;

    while (!jugada) {
        int X, Y;
        std::cout << "Dime la posicion de la columna (Y): " << std::flush;
        std::cin >> Y;
        while (std::cin.fail() || (Y < 0 || Y > TAM - 1)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << std::endl;
            std::cout << "Introduce una posicion valida: " << std::flush;
            std::cin >> Y;
        }
        std::cout << "Dime la posicion de la fila (X): " << std::flush;
        std::cin >> X;
        while (std::cin.fail() || (X < 0 || X > TAM - 1)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << std::endl;
            std::cout << "Introduce una posicion valida: " << std::flush;
            std::cin >> X;
        }
        
        if (tablero[X][Y] == ' ') {
            tablero[X][Y] = 'X';
            jugada = true;
        }
        else {
            std::cout << "Casilla ocupada\n";
        }  
    }
}

void jugadaIA(char  tablero[TAM][TAM]) {
    bool jugada = false;

    while (!jugada) {

        int Xrandom, Yrandom;

        Xrandom = rand() % 3;
        Yrandom = rand() % 3;

        if (Xrandom >= 0 && Xrandom < TAM && Yrandom >= 0 && Yrandom < TAM) {
            if (tablero[Xrandom][Yrandom] == ' ') {
                tablero[Xrandom][Yrandom] = 'O';
                jugada = true;
                std::cout << "\n Turno de la IA...\n";
            }
        }
    }
}

short elejirAccion() {
    short opcion;

    std::cout << "Que queres hacer?";
    std::cout << std::endl;
    std::cout << "1 - Poner ficha\n";
    std::cout << "2 - Guardar partida\n";
    std::cout << "3 - Volver al menu\n";
    std::cout << std::endl;
    std::cout << "Escoje una opcion: " << std::flush;
    std::cin >> opcion;

    while (std::cin.fail() || opcion < 0 || opcion > 3) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << std::endl;
        std::cout << "Introduce una opcion correcta: " << std::flush;
        std::cin >> opcion;
    }
    system("cls");

    return opcion;
}