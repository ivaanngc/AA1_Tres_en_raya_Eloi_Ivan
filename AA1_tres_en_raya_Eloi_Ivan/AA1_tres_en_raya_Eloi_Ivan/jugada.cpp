#include "defines.h"
#include "tablero.h"
#include <stdlib.h>
#include "victoria.h"
#include "jugada.h"

void jugada(char tablero[TAM][TAM]) {
    bool jugada = false;

    while (!jugada) {
        int X, Y;
        std::cout << "Dime la posicion de columnas (Y): ";
        std::cin >> Y;
        std::cout << "Dime la posicion de filas (X): ";
        std::cin >> X;
        if (X >= 0 && X < TAM && Y >= 0 && Y < TAM) {
            if (tablero[X][Y] == ' ') {
                tablero[X][Y] = 'X';
                jugada = true;
            }
            else {
                std::cout << "Casilla ocupada\n";
            }
        }
        else {
            std::cout << "Posicion fuera de rango\n";
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