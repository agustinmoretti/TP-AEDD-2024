#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
// INCLUIR ARCHIVOS CABECERA ACA
#include "menu.h"
#include "deportes.h"
#include "paises.h"
#include "visual.h"

void imprimircompetencia(int indice, competidores competencia[])
{
	cout << "Disciplina --> ";
	imprimirDeporte(indice);
	Sleep(100);
	cout << "ID Pais : ";
	for (int j = 0; j < 16; j++)
	{
		if (competencia[indice - 1].paises[j] != 0)
		{
			cout << competencia[indice - 1].paises[j] << " ";
			Sleep(100);
		}
	}
	cout << endl;
	cout << "--------------------------" << endl;
}

void imprimircompetencias(competidores competencia[])
{
	for (int i = 0; i < 87; i++)
	{
		cout << "Disciplina --> ";
		imprimirDeporte(i); // Cambiado de i a i+1 para que los �ndices empiecen en 1
		cout << "-- " << i << endl;
		for (int j = 0; j < 16; j++)
		{
			if (competencia[i].paises[j])
			{
				cout << competencia[i].paises[j] << " ";
			}
		}
		cout << endl;
		cout << "--------------------------" << endl;
	}
}
void cargaAleatoria(competidores competencia[])
{
	srand(time(NULL)); // Inicializar la semilla del generador de n�meros aleatorios
	
	// Para cada disciplina, seleccionar entre 4 y 16 pa�ses aleatoriamente
	for (int i = 0; i < 87; i++)
	{
		// Generar aleatoriamente el n�mero de pa�ses participantes entre 4 y 16
		int numPaisesSeleccionados = rand() % 13 + 4; // 4 + (0 a 12) -> rango [4, 16]
		competencia[i].tl = numPaisesSeleccionados;
		
		// ASIGNA PAIS ALEATORIO SIN MEZCLAR
		for (int j = 0; j < numPaisesSeleccionados; j++)
		{
			competencia[i].paises[j] = rand() % 196 + 1; // Generar pa�ses del 1 al numPaises
		}
		
		// Si no se seleccionan los 16 pa�ses, rellenar con 0
		for (int j = numPaisesSeleccionados; j < 16; j++)
		{
			competencia[i].paises[j] = 0;
		}
	}
}

bool generarCompetencia(competidores competencia[], int deporte_medallas[][3])
{
	bool cargado = false;
	
	cout << "Cargando Competencia ... " << endl;
	Sleep(1000);
	cargaAleatoria(competencia);
	
	for (int i = 0; i < 87; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			deporte_medallas[i][j] = 0;
		}
	}
	
	cargado = true;
	
	// imprimircompetencias(competencia);
	
	return cargado;
}
