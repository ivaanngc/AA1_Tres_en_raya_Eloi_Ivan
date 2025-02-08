#include "defines.h"
#include "tablero.h"
#include "jugada.h"
#include "victoria.h"

int main() {
    srand(time(NULL));
	char tablero[TAM][TAM];
    inicializarTablero(tablero);
    bool gameplay = true;
    bool turnoJugador = true;
    bool juego = true;
    short opcion = 0; {};

    std::cout << "Bienvenido al juego del tres en raya\n";
    std::cout << std::endl;
    std::cout << "1 - Nueva partida\n";
    std::cout << "2 - Cargar partida guardada\n";
    std::cout << "3 - Salir\n";
    std::cout << std::endl;
    std::cout << "Escoje una opcion: ";
    std::cin >> opcion;

    while (juego) {

        switch (opcion) {
        case 1:

            system("cls");

            while (gameplay) {
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
                    gameplay = false;
                    continue;
                }
                else if (ganador(tablero, 'O')) {
                    imprimirTablero(tablero);
                    std::cout << "Has ganado jugador O\n";
                    gameplay = false;
                    continue;
                }
                if (empate(tablero)) {
                    std::cout << "Empate\n";
                    system("pause");
                    system("cls");
                    inicializarTablero(tablero);
                }
            }
            
            break;

        case 2:
            break;

        case 3:
            juego = false;
            break;

        default:
            std::cout << "Introduce una opcion correcta: ";
            std::cin >> opcion;
            break;
        }
    }

	return 0;
}