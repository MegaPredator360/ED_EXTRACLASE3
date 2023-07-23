#include "interfaz.h"

int main()
{
	// Metodo para poder mostrar caracteres especiales en consola
	setlocale(LC_ALL, "");

	// Llamado a la clase interfaz
	interfaz _interfaz;

	// Llamado al metodo del menú principal
	_interfaz.menuPrincipal();

	return 0;
}