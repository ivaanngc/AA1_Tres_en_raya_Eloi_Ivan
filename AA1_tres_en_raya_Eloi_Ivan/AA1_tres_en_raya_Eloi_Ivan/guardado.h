#pragma once
#include "defines.h"
#include <string>

void nombrarFichero(std::string& nombreFichero);
bool ficheroExiste(std::string& nombreFichero);
void guardarPartida(char tablero[TAM][TAM]);
bool cargarPartida(char tablero[TAM][TAM]);