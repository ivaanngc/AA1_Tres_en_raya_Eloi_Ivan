#include "guardado.h"
#include <fstream>

void nombrarFichero(std::string& nombreFichero) {
	bool nombreCorrecto = true;

	do {
		nombreCorrecto = true;
		std::cout << "\nIntroduce el nombre para el fichero: "<< std::flush;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		std::getline(std::cin, nombreFichero);
		if (nombreFichero == "menu" || std::cin.fail() || nombreFichero.empty()) {
			std::cout << "Nombre no valido" << std::endl;
			nombreCorrecto = false;
		}
	} while (!nombreCorrecto);

	nombreFichero.append(".tictacsave");
	std::cout << "\nEn nombre del fichero es: " << nombreFichero << std::endl;
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
	bool sobreescribe = false;

	while (ficheroExiste(saveName) && !sobreescribe) {
		do {
			std::cout << "\nQuieres sobreescribir la partida existente? (si/no)" << std::endl;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::getline(std::cin, respuesta);
		} while ((respuesta != "si" && respuesta != "no") || std::cin.fail());
		if (respuesta == "no") {
			nombrarFichero(saveName);
		}
		else {
			sobreescribe = true;
		}
	}

	std::ofstream fGuarda;
	fGuarda.open(saveName, std::ios::trunc);
	if (!fGuarda.is_open()) {
		std::cout << "Error al guardar el fichero" << std::endl;
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

	std::cout << "Introduce el nombre del fichero (sin extension): " << std::flush;
	if (!std::cin.good())
	{
		std::cin.clear();
	}
	std::cin.ignore(1000, '\n');
	std::getline(std::cin, nombreFichero);
	nombreFichero.append(".tictacsave");

	std::ifstream fCarga;
	fCarga.open(nombreFichero);

	if (!fCarga.is_open()) {
		std::cout << "Error al cargar el fichero" << std::endl;
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
	std::cout << "Partida cargada" << std::endl;
	fCarga.close();

	return true;
}