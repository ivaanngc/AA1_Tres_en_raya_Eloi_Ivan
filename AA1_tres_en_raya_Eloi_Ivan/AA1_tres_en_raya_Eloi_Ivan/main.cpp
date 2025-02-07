#include "defines.h"
#include "tablero.h"
#include "jugada.h"
#include "victoria.h"

int main() {
    srand(time(NULL));
	char tablero[TAM][TAM];
    inicializarTablero(tablero);
    bool game = true;
    bool turnoJugador = true;

    while(game){
        imprimirTablero(tablero);
        
        if (turnoJugador) {
            jugada(tablero);
        }
        else {
            jugadaIA(tablero);
        }
        system("pause");
        system("cls");
        turnoJugador = !turnoJugador;

        if (ganador(tablero, 'X')) {
            imprimirTablero(tablero);
            std::cout << "Has ganado jugador X\n";
            game = false;
            continue;
        }
        else if (ganador(tablero, 'O')) {
            imprimirTablero(tablero);
            std::cout << "Has ganado jugador O\n";
            game = false;
            continue;
        }
        if (empate(tablero)) {
            std::cout << "Empate\n";
            system("pause");
            system("cls");
            inicializarTablero(tablero);
        }
    }

	return 0;
}

