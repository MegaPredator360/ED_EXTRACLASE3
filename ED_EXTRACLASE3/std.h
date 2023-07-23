#pragma once
#include <string>			// Para poder usar el tipo de dato "string"
#include <iostream>			// Permite al usuario interactuar con la aplicacion de consola
#include <wchar.h>			// Para caracteres especiales
#include <conio.h>			// Para obtener caracter en formato ASCII
#include <stack>			// Para poder realizar listas en pilas
#include <Windows.h>		// Libreria de C++ exclusiva para Windows
#include <fstream>			// Libreria para interacción con archivos
#include <vector>			// Usado para escribir en la ultima linea del archivo

#pragma comment (lib, "winmm.lib")	// Vincular las funciones multimedia de Windows con el programa

// Colores de letra para la consola
#define RED     "\033[31m"
#define YELLOW	"\x1B[33m"
#define GREEN	"\x1B[32m"
#define WHITE   "\033[0m"

using namespace std;