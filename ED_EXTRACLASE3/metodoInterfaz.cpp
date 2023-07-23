#include "metodoInterfaz.h"

void metodoInterfaz::color(int color)
{
	// Obtendrá el codigo de color para la consola
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void metodoInterfaz::goToXY(int x, int y)
{
	// Este tipo de dato indica las coordenadas de donde se escribirá el texto
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

string metodoInterfaz::confirmacionDefS()			// Utiliza la misma estructura que el de solo ingresarNumeros()
{
	int asciiChar = 0;
	string letra = "";
	do
	{
		asciiChar = _getch();
		if (asciiChar == 13 && letra == "")
		{
			letra = "S";
			break;
		}
		else if (asciiChar == 13 && letra != "")
		{
			cout << endl;
			break;
		}
		else if (asciiChar == 8 && letra == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 8)
		{
			cout << '\b';
			cout << " ";
			cout << '\b';
			letra = letra.substr(0, letra.size() - 1);
		}
		else if (letra.length() >= 1)
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 83)
		{
			cout << "S";
			letra = "S";
		}
		else if (asciiChar == 115)
		{
			cout << "s";
			letra = "S";
		}
		else if (asciiChar == 78)
		{
			cout << "N";
			letra = "N";
		}
		else if (asciiChar == 110)
		{
			cout << "n";
			letra = "N";
		}
	} while (1);

	return (letra);
}