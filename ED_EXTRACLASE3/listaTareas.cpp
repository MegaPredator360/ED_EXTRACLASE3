#include "listaTareas.h"

void listaTareas::agregarTarea(tarea _tarea)
{
	try 
	{
		listaTarea.push(_tarea);
	}
	catch (exception& e)
	{
		throw e;
	}
}

bool listaTareas::verificarTarea(tarea _tarea)
{
	try
	{
		auxiliar = listaTarea;

		while (!auxiliar.empty())
		{
			if (auxiliar.top().getNombreTarea() == _tarea.getNombreTarea())
			{
				return true;
			}

			auxiliar.pop();
		}

		return false;
	}
	catch (exception& e)
	{
		throw e;
	}
}

void listaTareas::primerTarea()
{
	try
	{
		if (listaTarea.empty())
		{
			throw exception("¡No hay tareas registradas!");
		}

		cout << "Esta es la tarea más reciente:" << endl;
		cout << listaTarea.top().getNombreTarea() << endl;
	}
	catch (exception& e)
	{
		throw e;
	}
}

void listaTareas::eliminarTarea()
{
	try
	{
		listaTarea.pop();
	}
	catch (exception& e)
	{
		throw e;
	}
}

void listaTareas::tareasPendientes()
{
	try
	{
		if (listaTarea.empty())
		{
			throw exception("¡No hay tareas registradas!");
		}

		auxiliar = listaTarea;

		while (!auxiliar.empty())
		{
			cout << auxiliar.top().getNombreTarea() << endl;
			auxiliar.pop();
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void listaTareas::cargarArchivo()
{
	try
	{
		tarea _tarea;

		// Cargar datos del archivo
		ifstream cargarDatos("datosTareas.txt");
		if (cargarDatos.is_open())
		{
			string datos;
			while (getline(cargarDatos, datos))
			{
				_tarea.setNombreTarea(datos);
				agregarTarea(_tarea);
			}
		}
		cargarDatos.close();
	}
	catch (exception& e)
	{
		cout << RED << "Ha ocurrido un error durante la lectura del archivo: " << WHITE << e.what() << endl;
		cout << "-------------------------" << endl;
		system("pause");
	}
}

void listaTareas::guardarArchivo()
{
	try
	{
		ofstream archivoDatos("datosTareas.txt");
		vector<string> vectorTarea;					// Para guardar en la ultima linea del archivo

		auxiliar = listaTarea;

		while (!auxiliar.empty()) 
		{
			vectorTarea.push_back(auxiliar.top().getNombreTarea());
			auxiliar.pop();
		}

		while (!vectorTarea.empty())
		{
			archivoDatos << vectorTarea.back() << endl;
			vectorTarea.pop_back();
		}

		archivoDatos.close();
	}
	catch (exception& e)
	{
		cout << RED << "Ha ocurrido un error durante el guardado del archivo: " << WHITE << e.what() << endl;
		cout << "-------------------------" << endl;
		system("pause");
	}
}
