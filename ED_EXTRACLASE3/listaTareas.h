#include "tarea.h"

class listaTareas: public tarea
{
protected:
	stack<tarea> listaTarea;
	stack<tarea> auxiliar;

public:
	void agregarTarea(tarea);
	bool verificarTarea(tarea);
	void primerTarea();
	void eliminarTarea();
	void tareasPendientes();

	// Archivos
	void cargarArchivo();
	void guardarArchivo();
};

