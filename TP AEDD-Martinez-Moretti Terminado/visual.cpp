#include <iostream>
#include <cstdlib>

// INCLUIR ARCHIVOS CABECERA ACA
#include "visual.h"
#include "windows.h"
using namespace std;

void limpiar()
{
	system("cls");
}
void pausar()
{
	cout << "Presione enter para continuar ..." << endl;
	cin.ignore(10000, '\n');
}

void barradecarga(int duracionTotal, int longitudBarra)
{
	cout << "Cargando: ";
	
	for (int i = 0; i < longitudBarra; i++)
	{
		cout << "_"; // Inicialmente, la barra está vacía
	}
	cout.flush(); // Asegurarse de que se muestre todo el contenido inmediatamente
	
	for (int i = 0; i <= longitudBarra; i++)
	{
		// Simula el tiempo que toma cada paso en la carga
		Sleep(duracionTotal / longitudBarra);
		
		// Mueve el cursor hacia la izquierda para actualizar la barra
		cout << "\rCargando: ";
		for (int j = 0; j < i; j++)
		{
			cout << "#"; // Llena la barra con "#"
		}
		for (int j = i; j < longitudBarra; j++)
		{
			cout << "_"; // Mantiene el resto de la barra vacía con "_"
		}
		
		cout.flush(); // Asegurarse de que la barra se actualice en tiempo real
	}
	
	cout << "\nCarga completa!" << endl;
}

void mostrarEspiral()
{
	char matriz[10][10];
	int inicioFila = 0, finFila = 9, inicioColumna = 0, finColumna = 9;
	char caracter = 'A'; // Iniciamos con la letra 'A'
	
	// Inicializamos la matriz con espacios
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matriz[i][j] = ' ';
		}
	}
	
	// Llenar la matriz en espiral
	while (inicioFila <= finFila && inicioColumna <= finColumna)
	{
		// Llenar la primera fila de izquierda a derecha
		for (int i = inicioColumna; i <= finColumna; i++)
		{
			matriz[inicioFila][i] = caracter;
			caracter = (caracter == 'Z') ? 'A' : caracter + 1; // Ciclo A-Z
			Sleep(40);                                         // Velocidad de visualización
			system("cls");                                     // Limpiar la pantalla
			for (int a = 0; a < 10; a++)
			{
				for (int b = 0; b < 10; b++)
				{
					cout << matriz[a][b] << " ";
				}
				cout << endl;
			}
		}
		inicioFila++;
		
		// Llenar la última columna de arriba a abajo
		for (int i = inicioFila; i <= finFila; i++)
		{
			matriz[i][finColumna] = caracter;
			caracter = (caracter == 'Z') ? 'A' : caracter + 1;
			Sleep(40);
			system("cls");
			for (int a = 0; a < 10; a++)
			{
				for (int b = 0; b < 10; b++)
				{
					cout << matriz[a][b] << " ";
				}
				cout << endl;
			}
		}
		finColumna--;
		
		// Llenar la última fila de derecha a izquierda
		for (int i = finColumna; i >= inicioColumna; i--)
		{
			matriz[finFila][i] = caracter;
			caracter = (caracter == 'Z') ? 'A' : caracter + 1;
			Sleep(40);
			system("cls");
			for (int a = 0; a < 10; a++)
			{
				for (int b = 0; b < 10; b++)
				{
					cout << matriz[a][b] << " ";
				}
				cout << endl;
			}
		}
		finFila--;
		
		// Llenar la primera columna de abajo a arriba
		for (int i = finFila; i >= inicioFila; i--)
		{
			matriz[i][inicioColumna] = caracter;
			caracter = (caracter == 'Z') ? 'A' : caracter + 1;
			Sleep(40);
			system("cls");
			for (int a = 0; a < 10; a++)
			{
				for (int b = 0; b < 10; b++)
				{
					cout << matriz[a][b] << " ";
				}
				cout << endl;
			}
		}
		inicioColumna++;
	}
}
