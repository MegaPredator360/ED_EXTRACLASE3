#include "interfaz.h"

void interfaz::menuPrincipal()
{
	_listaTareas.cargarArchivo();
	Set[0] = 23;

	while (1)
	{
		system("cls");

		cout << endl;
		cout << "		[]------------------------------------------[]" << endl;
		cout << "		|               Menú Principal               |" << endl;
		cout << "		[]------------------------------------------[]" << endl;
		cout << "		|                                            |" << endl;
		cout << "		|           Selecciona una opción:           |" << endl;
		cout << "		|                                            |" << endl;
		cout << "		|";

		for (int i = 0;;)
		{
			// Indica la posicion de donde se escribirá el texto
			goToXY(32, 7);
			// Inidicará el color a ingresar marcar si la opcion es seleccionada
			color(Set[0]);
			// Texto de la opción
			cout << "Agregar tarea";

			cout << WHITE << "	             |" << endl;
			cout << "		|";

			goToXY(31, 8);
			color(Set[1]);
			cout << "Completar tarea";

			cout << WHITE << "	             |" << endl;
			cout << "		|";

			goToXY(26, 9);
			color(Set[2]);
			cout << "Mostrar tareas pendientes";

			cout << WHITE << "	     |" << endl;
			cout << "		|";

			goToXY(36, 10);
			color(Set[3]);
			cout << "Salir";

			cout << WHITE << "		     |" << endl;
			cout << "		|                                            |" << endl;
			cout << "		[]------------------------------------------[]" << endl;

			key = _getch();

			if (key == 72 && (counter >= 1 && counter <= 4))		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
			{
				counter--;

				if (counter == 0)
				{
					counter = 4;
				}
			}
			else if (key == 80 && (counter >= 1 && counter <= 4))	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
			{
				counter++;

				if (counter == 5)
				{
					counter = 1;
				}
			}
			else if (key == '\r')	// Identifica si la tecla ENTER fue pulsada
			{
				switch (counter)
				{
				case 1:
					try
					{
						// Agregar tarea
						system("cls");
						cout << endl;
						cout << "		[]--------------------------------------------[]" << endl;
						cout << "		|                Agregar tarea                 |" << endl;
						cout << "		[]--------------------------------------------[]" << endl;
						cout << endl;

						cout << "Ingresa el nombre de la tarea:" << endl;
						// No avanzará si la variable no esta vacia
						while (getline(cin, nombre) && nombre == "") {}
						_tarea.setNombreTarea(nombre);

						while (_listaTareas.verificarTarea(_tarea))
						{
							cout << RED << "La tarea ingresada ya existe, favor ingresa otro nombre:" << WHITE << endl;
							while (getline(cin, nombre) && nombre == "") {}
							_tarea.setNombreTarea(nombre);
						}

						_listaTareas.agregarTarea(_tarea);
						_listaTareas.guardarArchivo();

						cout << "----------------------------------------" << endl;
						cout << GREEN << "¡La tarea ha sido ingresada con exito!" << WHITE << endl;
						system("pause");
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 2:
					try
					{
						// Completar tarea
						system("cls");
						cout << endl;
						cout << "		[]-------------------------------------------[]" << endl;
						cout << "		|               Completar tarea               |" << endl;
						cout << "		[]-------------------------------------------[]" << endl;
						cout << endl;

						_listaTareas.primerTarea();

						cout << endl << "¿Has completado la tarea? [S/n]" << endl;
						confirmacion = confirmacionDefS();

						if (confirmacion == "S")
						{
							_listaTareas.eliminarTarea();
							_listaTareas.guardarArchivo();

							cout << "----------------------------------------" << endl;
							cout << GREEN << "¡La tarea ha sido ingresada con exito!" << WHITE << endl;
							system("pause");
						}
						else
						{
							cout << "----------------------------------------" << endl;
							cout << "¡Date prisa en terminar la tarea!" << endl;
							system("pause");
						}
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 3:
					try
					{
						// Mostrar tareas pendientes
						system("cls");
						cout << endl;
						cout << "		[]-------------------------------------------[]" << endl;
						cout << "		|          Mostrar tareas pendientes          |" << endl;
						cout << "		[]-------------------------------------------[]" << endl;
						cout << endl;

						_listaTareas.tareasPendientes();

						cout << "----------------------------------------" << endl;
						cout << GREEN << "¡Las tareas han sido cargadas con exito!" << WHITE << endl;
						system("pause");
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 4:
					try
					{
						// Salir del programa
						string confirmacion;

						system("cls");
						cout << endl;
						cout << "		[]--------------------------------------------[]" << endl;
						cout << "		|              Salir del programa              |" << endl;
						cout << "		[]--------------------------------------------[]" << endl;
						cout << endl;

						cout << "¿Deseas salir del programa? [S/n]" << endl;
						confirmacion = confirmacionDefS();

						if (confirmacion == "S")
						{
							cout << "-----------------------------------" << endl;
							cout << GREEN << "¡Gracias por usar el programa!" << WHITE << endl;
							system("pause");
							exit(0);
						}
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				default:
					cout << RED << "Seleccione una opcion valida. " << WHITE << endl;
				}

				break; // Pasa salir del ciclo for
			}

			// Color por defecto de todas las opciones
			Set[0] = 7;			// 7 es el color blanco
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;

			// Cambiar color basado en la opcion seleccionada
			switch (counter)
			{
			case 1:
				// Se indica el codigo de color con el que se usará en el texto
				// si la opciön está seleccionada
				Set[0] = 23;
				break;

			case 2:
				Set[1] = 23;
				break;

			case 3:
				Set[2] = 23;
				break;

			case 4:
				Set[3] = 23;
				break;
			}
		}
	}
}
