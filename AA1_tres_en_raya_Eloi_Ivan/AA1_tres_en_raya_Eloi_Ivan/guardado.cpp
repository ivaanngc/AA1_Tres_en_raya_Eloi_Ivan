#include "guardado.h"
#include <fstream>

void nombrarFichero(std::string& nombreFichero) {
	bool nombreCorrecto = true;

	do {
		nombreCorrecto = true;
		std::cout << "Introduce el nombre de la partida: ";
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, nombreFichero);
		if (nombreFichero == "menu") {
			std::cout << "Nombre no valido\n";
			nombreCorrecto = false;
		}
	} while (!nombreCorrecto);

	nombreFichero.append(".tictacsave");
}

bool ficheroExiste(std::string& nombreFichero) {
	std::ifstream fExiste(nombreFichero);
	bool existe = fExiste.good();
	fExiste.close();

	return existe;
}

void guardarPartida(char tablero[TAM][TAM]) {
	std::string saveName;
	nombrarFichero(saveName);
	std::string respuesta;

	while (ficheroExiste(saveName) || respuesta == "si") {

		do {
			std::cout << "\nQuieres sobreescribir la partida existente? (si/no)\n";
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, respuesta);
		} while (respuesta != "si" || respuesta != "no");
		if (respuesta == "no") {
			nombrarFichero(saveName);
		}
	}

	std::ofstream fGuarda;
	fGuarda.open(saveName, std::ios::trunc);
	if (!fGuarda.is_open()) {
		std::cout << "Error al guardar el fichero\n";
		return;
	}
	for (short i = 0; i < TAM; i++) {
		for (short j = 0; j < TAM; j++) {
			fGuarda << tablero[i][j];
		}
		fGuarda << "\n";
	}
	std::cout << "Partida guardada\n";
	fGuarda.close();
}


bool cargarPartida(char tablero[TAM][TAM]) {
	std::string nombreFichero;

	std::cout << "Introduce el nombre del fichero (sin extension): ";
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, nombreFichero);
	nombreFichero.append(".tictacsave");

	std::ifstream fCarga;
	fCarga.open(nombreFichero);

	if (!fCarga.is_open()) {
		std::cout << "Error al cargar el fichero\n";
		return false;
	}
	char caracter;
	for (short i = 0; i < TAM; i++) {
		for (short j = 0; j < TAM; j++) {
			fCarga >> std::noskipws >> caracter; //para tenga en cuenta los espacios
			tablero[i][j] = caracter;
		}
		
		fCarga >> std::noskipws >> caracter; //para que tenga en cuenta el \n pero no lo lea para el tablero
	}
	std::cout << "Partida cargada\n";
	fCarga.close();

	return true;
}