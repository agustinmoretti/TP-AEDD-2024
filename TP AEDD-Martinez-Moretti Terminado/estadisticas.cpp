#include <iostream>
#include <windows.h>
#include <cstring>
#include "deportes.h"
#include "paises.h"
#include "mostrar_medallero.h"
#include "cargar_medallas.h"
#include "visual.h"

using namespace std;

void paises_premiados(int deporte_medallas[][3])
{
	barradecarga(1000, 60);
	Sleep(400);
	system("cls");
	cout << "--------------------" << endl;
	cout << "Paises Premiados del Deporte" << endl;
	cout << "--------------------" << endl;
	cout << endl;
	
	char letra;
	
	cout << "Ingrese una letra con la que comienza el deporte : ";
	cin >> letra;
	system("cls");
	letra = toupper(letra); // Convertir a mayuscula y comparo
	// Por defecto tomo el valor A para letradeporte
	char letradeporte = 'A';
	for (int i = 0; i < 87; i++)
	{
		// Obtengo Letra Deporte
		letradeporte = letra_deporte(i + 1);
		
		// Verifico Que Sea la misma que la introducida
		if (letra == letradeporte)
		{
			
			if (deporte_medallas[i][0] != 0 && deporte_medallas[i][1] != 0 && deporte_medallas[i][2] != 0)
			{
				cout << "DEPORTE -> ";
				imprimirDeporte(i + 1);
				Sleep(100);
				cout << "Podio: " << endl;
				cout << "PAIS -> ORO -> "; // modificado ultima entrega
				imprimirPais(deporte_medallas[i][0]);
				cout << endl;
				Sleep(100);
				cout << "PAIS -> PLATA ->  "; // modificado ultima entrega
				imprimirPais(deporte_medallas[i][1]);
				cout << endl;
				Sleep(500);
				cout << "PAIS -> BRONCE ->  "; // modificado ultima entrega
				imprimirPais(deporte_medallas[i][2]);
				cout << endl;
				cout << "-----------------------------" << endl;
			}
		}
	}
	system("pause");
}
void paismasmedallasindividuales(int deporte_medallas[][3])
{
	barradecarga(1000, 60);
	Sleep(400);
	system("cls");
	cout << "--------------------" << endl;
	cout << " Pais con mas Deportes Indiviuales" << endl;
	cout << "--------------------" << endl;
	cout << endl;
	
	// Obtengo las medallas totales de cada pais
	int medallasporpais[197][3];
	int medallastotal[197] = {0};
	
	// INnicializo en 0
	for (int a = 1; a < 197; a++)
	{ // pone en cero la matriz
		for (int j = 0; j < 3; j++)
		{
			medallasporpais[a][j] = 0;
		}
	}
	for (int j = 0; j < 3; j++)
	{ // setea los valores de las medallas que gano cada pais
		for (int i = 0; i < 87; i++)
		{
			if (deporte_medallas[i][j] != 0)
			{
				medallasporpais[deporte_medallas[i][j]][j]++;
			}
		}
	}
	// calculo medallas totales de cada pais
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 197; i++)
		{
			if (verificaIndividuales(i))
			{
				if (medallasporpais[i][j] != 0)
				{
					medallastotal[i]++;
				}
			}
		}
	}
	
	// Calculo el mayor
	int max = 0;
	int indice_pais = -1;
	
	for (int i = 0; i < 197; i++)
	{
		if (medallastotal[i] > max)
		{
			max = medallastotal[i];
			indice_pais = i;
		}
	}
	
	cout << "--------------------------------" << endl;
	cout << "       Categoria Individual     " << endl;
	cout << "--------------------------------" << endl;
	cout << "PAIS -> ";
	imprimirPais(indice_pais);
	cout << endl;
	
	cout << "TOTAL DE MEDALLAS -> " << max << endl;
	
	system("pause");
}
void medallasdelpais(int deporte_medallas[][3])
{
	barradecarga(1000, 60);
	Sleep(400);
	system("cls");
	cout << "--------------------" << endl;
	cout << " Medallas del Pais" << endl;
	cout << "--------------------" << endl;
	cout << endl;
	
	// Obtengo las medallas totales de cada pais
	int medallasporpais[197][3];
	int medallastotal[197] = {0};
	int id;
	// INnicializo en 0
	for (int a = 1; a < 197; a++)
	{ // pone en cero la matriz
		for (int j = 0; j < 3; j++)
		{
			medallasporpais[a][j] = 0;
		}
	}
	for (int j = 0; j < 3; j++)
	{ // setea los valores de las medallas que gano cada pais
		for (int i = 0; i < 87; i++)
		{
			if (deporte_medallas[i][j] != 0)
			{
				medallasporpais[deporte_medallas[i][j]][j]++;
			}
		}
	}
	// calculo medallas totales de cada pais
	for (int j = 0; j < 3; j++)
	{
		for (int i = 1; i < 197; i++)
		{
			if (medallasporpais[i][j] != 0)
			{
				medallastotal[i]++;
			}
		}
	}
	
	bool mostrado = false;
	
	do
	{
		listarPaises();
		cout << "--------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "Ingrese ID de Pais : ";
		cin >> id;
		system("cls");
		if (id >= 0 and id < 197)
		{
			cout << "PAIS -> ";
			imprimirPais(id);
			cout << endl;
			
			cout << "TOTAL DE MEDALLAS -> " << medallastotal[id] << endl;
			mostrado = true;
			system("pause");
		}
		else
		{
			
			cout << "ID no encontrado" << endl;
			Sleep(1000);
			system("cls");
		}
	} while (!mostrado);
}
void paisconmasmedallas(int deporte_medallas[][3])
{
	barradecarga(1000, 60);
	Sleep(400);
	system("cls");
	cout << "--------------------" << endl;
	cout << " Pais con mas Medallas" << endl;
	cout << "--------------------" << endl;
	cout << endl;
	// Obtengo las medallas totales de cada pais
	int medallasporpais[197][3];
	int medallastotal[197] = {0};
	// INnicializo en 0
	for (int a = 1; a < 197; a++)
	{ // pone en cero la matriz
		for (int j = 0; j < 3; j++)
		{
			medallasporpais[a][j] = 0;
		}
	}
	for (int j = 0; j < 3; j++)
	{ // setea los valores de las medallas que gano cada pais
		for (int i = 0; i < 87; i++)
		{
			if (deporte_medallas[i][j] != 0)
			{
				medallasporpais[deporte_medallas[i][j]][j]++;
			}
		}
	}
	// calculo medallas totales de cada pais
	for (int j = 0; j < 3; j++)
	{
		for (int i = 1; i < 197; i++)
		{
			if (medallasporpais[i][j] != 0)
			{
				medallastotal[i]++;
			}
		}
	}
	
	// Busco el mayor
	int max = 0;
	int indice_pais = -1;
	
	for (int i = 0; i < 197; i++)
	{
		if (medallastotal[i] > max)
		{
			max = medallastotal[i];
			indice_pais = i;
		}
	}
	// verifico si encontro o no el pais
	if (indice_pais != -1)
	{
		cout << "PAIS -> ";
		imprimirPais(indice_pais);
		cout << endl;
		cout << "TOTAL DE MEDALLAS -> " << max << endl;
	}
	else
	{
		cout << "No se encontraron Medallas" << endl;
	}
	system("pause");
}
void menu_estadisticas(int deporte_medallas[][3])
{
	char opcion;
	
	cout << "Menu Estadisticas ... " << endl;
	Sleep(1500);
	system("cls");
	
	do
	{
		cout << "Menu Estadisticas" << endl;
		cout << "==========================" << endl;
		cout << "1.- Pais con mas medallas" << endl;
		cout << "2.- Medallas del pais" << endl;
		cout << "3.- Pais con mas deportes individuales " << endl;
		cout << "4.- Paises premiados del deporte" << endl;
		cout << "X.- Volver al menu principal" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		system("cls");
		
		switch (opcion)
		{
		case '1':
		{
			// Pais con mas medallas
			paisconmasmedallas(deporte_medallas);
			system("cls");
		}
		break;
		case '2':
		{
			// Medallas del pais
			medallasdelpais(deporte_medallas);
			system("cls");
		}
		break;
		case '3':
		{
			// Pais con mas deportes individuales
			paismasmedallasindividuales(deporte_medallas);
			system("cls");
		}
		break;
		case '4':
		{
			// Paises Premiados del deporte
			paises_premiados(deporte_medallas);
			system("cls");
		}
		break;
		case 'x':
		{
		}
		case 'X':
		{
			system("cls");
			cout << " Volviendo al Menu Principal ..." << endl;
			Sleep(1000);
			system("cls");
		}
		break;
		
		default:
		{
			cout << "Opcion invalida, por favor intente nuevamente." << endl;
		}
			break;
		}
	} while (opcion != 'x' && opcion != 'X');
}
