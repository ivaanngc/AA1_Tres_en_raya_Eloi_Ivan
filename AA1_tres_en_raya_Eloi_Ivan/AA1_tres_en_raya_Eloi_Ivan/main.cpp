<<<<<<< Updated upstream
=======
#include "defines.h"
#include "tablero.h"
#include "jugada.h"
#include "victoria.h"

int main() {
	char tablero[TAM][TAM];
    inicializarTablero(tablero);
    bool game = true;
    while(game){
        imprimirTablero(tablero);
        jugada(tablero);

        if (ganador(tablero, 'X')) {
            imprimirTablero(tablero);
            std::cout << "Has ganado jugador X\n";
            game = false;
        }
        else if (ganador(tablero, 'O')) {
            imprimirTablero(tablero);
            std::cout << "Has ganado jugador O\n";
            game = false;
        }
    }
	return 0;
}
>>>>>>> Stashed changes
