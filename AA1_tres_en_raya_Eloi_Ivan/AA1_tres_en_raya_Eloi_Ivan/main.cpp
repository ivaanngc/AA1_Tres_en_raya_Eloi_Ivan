#include <iostream>
#include <fstream>
#define ANCHO 13
#define ALTO 7

void imprimirTablero(char tablero[ALTO][ANCHO]) {

	for (int i = 0; i < ALTO; i++) {
		for (int j = 0; j < ANCHO; j++)
		{
			tablero[i][j] = '-';
			tablero[1][0] = '|';
			tablero[1][4] = '|';

		}
	}

	for (int i = 0; i < ALTO; i++) {
		for (int j = 0; j < ANCHO; j++)
		{
			std::cout << tablero[i][j];

		}
		std::cout << std::endl;
	}

}

int main() {
	char tablero[ALTO][ANCHO];


	imprimirTablero(tablero);
	return 0;
}