#include "defines.h"

void imprimirTablero(char tablero[TAM][TAM]) {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < TAM; i++) {
        std::cout << i << " ";
        for (int j = 0; j < TAM; j++) {
            std::cout << tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void inicializarTablero(char tablero[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tablero[i][j] = '-';
        }
    }
}