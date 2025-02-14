#include "defines.h"
#include "tablero.h"
#include "jugada.h"
#include "victoria.h"
#include "guardado.h"

int main() {
    srand(time(NULL));
	char tablero[TAM][TAM];
    bool gameplay = true;
    bool turnoJugador = true;
    bool juego = true;
    short opcion = 0;
    bool carga = false;
    

    while (juego) {

        switch (opcion) {
        case 0:
            system("cls");

            std::cout << "Bienvenido al juego del tres en raya\n";
            std::cout << std::endl;
            std::cout << "1 - Nueva partida\n";
            std::cout << "2 - Cargar partida guardada\n";
            std::cout << "3 - Salir\n";
            std::cout << std::endl;
            std::cout << "Escoje una opcion: " << std::flush;
            std::cin >> opcion;

            while (std::cin.fail() || opcion < 0 || opcion > 3) {
                std::cin.clear();   //eliminar el error en el cin si se ha introducido mal input (p.e. un char en vez de un numero)
                std::cin.ignore(1000, '\n');  //ignorar el ultimo input
                std::cout << "Introduce una opcion correcta: " << std::flush;
                std::cin >> opcion;
            }
            break;

        case 1:

            system("cls");
            gameplay = true;
            if (!carga) {
                inicializarTablero(tablero);
            }
            carga = false;

            while (gameplay) {
                imprimirTablero(tablero);

                switch (elejirAccion()) {
                case 1: {
                    bool jugada_IA = false;
                    do {

                        imprimirTablero(tablero);
                        if (turnoJugador) {
                            jugada(tablero);
                        }
                        else {
                            jugadaIA(tablero);
                            jugada_IA = true;
                        }
                        system("pause");
                        system("cls");
                        turnoJugador = !turnoJugador;

                        if (ganador(tablero, 'X')) {
                            imprimirTablero(tablero);
                            std::cout << "Has ganado jugador X\n";
                            gameplay = false;
                            turnoJugador = true;
                            std::cout << "Juego treminado, pulsa cualquier tecla para volver al menu principal." << std::endl;
                            system("pause");
                            opcion = 0;
                            jugada_IA = true;
                            continue;
                        }
                        else if (ganador(tablero, 'O')) {
                            imprimirTablero(tablero);
                            std::cout << "Has ganado jugador O\n";
                            gameplay = false;
                            turnoJugador = true;
                            std::cout << "Juego treminado, pulsa cualquier tecla para volver al menu principal." << std::endl;
                            system("pause");
                            opcion = 0;
                            jugada_IA = true;
                            continue;
                        }
                        if (empate(tablero)) {
                            std::cout << "Empate" << std::endl;
                            system("pause");
                            system("cls");
                            inicializarTablero(tablero);
                            turnoJugador = true;
                            jugada_IA = true;
                        }
                    } while (!jugada_IA);

                    break;
                }
                case 2:
                    std::cin.ignore(1000, '\n');
                    guardarPartida(tablero);
                    break;

                case 3:
                    opcion = 0;
                    gameplay = false;

                    break;
                }
            }
            
            break;

        case 2:
            carga = cargarPartida(tablero);
            opcion = carga ? 1 : 0; //si hay un error al cargar vuelve al menu
            system("pause");

            break;

        case 3:
            std::cout << "Juego terminado" << std::endl;
            juego = false;
            break;
        }
    }

	return 0;
}