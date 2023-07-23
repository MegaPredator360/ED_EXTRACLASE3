#include "listaTareas.h"
#include "metodoInterfaz.h"

class interfaz: protected metodoInterfaz
{
protected:
	// Para el menú
	int counter = 1;
	int key;
	int Set[4] = { 7, 7, 7, 7 };
	string confirmacion;

	// Ingresar datos
	string nombre;

	// Llamado a clases
	listaTareas _listaTareas;
	tarea _tarea;

public:
	void menuPrincipal();
};

