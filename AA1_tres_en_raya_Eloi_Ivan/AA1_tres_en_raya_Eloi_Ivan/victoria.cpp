#include "defines.h"
#include "tablero.h"
#include "victoria.h"

bool ganador(char tablero[TAM][TAM], char jugador) {
	for (int i = 0; i < TAM; i++) {
		if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
			return true;
		}
		if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) {
			return true;
		}
	}

	if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
		return true;
	}
	if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
		return true;
	}
	return false;
}

bool empate(char tablero[TAM][TAM]) {
	bool lleno = true;

	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			if (tablero[i][j] == ' ') {
				lleno = false;
			}
		}
	}

	return lleno;
}
