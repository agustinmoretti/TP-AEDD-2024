#include <iostream>
#include <windows.h>
using namespace std;
// INCLUIR ARCHIVOS CABECERA ACA
#include "menu.h"
#include "cargar_medallas.h"
#include "deportes.h"
#include "paises.h"
#include "gen_competencia.h"
#include "visual.h"

void cargaPorDeporteIndividual(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia)
{
	// Carga inicial de datos
	cout << "Cargando listado Deportes Individuales" << endl;
	Sleep(1000);
	barradecarga(1000, 60);
	Sleep(1000);
	system("cls");
	
	mostrarDeportesIndividuales();
	int id, idPais1, idPais2, idPais3;
	bool encon = false, var1 = false, var2 = false, var3 = false;
	bool cancelado = false;
	
	do
	{
		// Selección de deporte
		cout << "Ingrese ID del Deporte a cargar: ";
		cin >> id;
		system("cls");
		
		// Verificar si el ID está en los deportes individuales
		encon = verificaIndividuales(id);
		
		if (encon)
		{
			// Validar si ya fue cargado
			if (deporteCargado(id, deporte_medallas))
			{
				cout << "El deporte ya tiene medallas asignadas. No se puede cargar nuevamente." << endl;
				continue;
			}
			
			cout << "Listado de países participantes:" << endl;
			imprimircompetencia(id, competencia);
			
			cout << "Ingrese -1 para cancelar la carga de medallas." << endl;
			cout << endl;
			
			// PAIS 1 (ORO)
			do
			{
				cout << "MEDALLA DE ORO --> ID País: ";
				cin >> idPais1;
				if (idPais1 == -1)
				{
					for (int i = 0; i < 3; i++)
					{
						deporte_medallas[id - 1][i] = 0;
						file_competencia.deporte_medallas[id - 1][i] = 0;
					}
					cout << "Carga de medallas cancelada." << endl;
					cancelado = true;
					break;
				}
				else
				{
					for (int a = 0; a < 16; a++)
					{
						if (idPais1 == competencia[id - 1].paises[a])
						{
							deporte_medallas[id - 1][0] = idPais1;
							file_competencia.deporte_medallas[id - 1][0] = deporte_medallas[id - 1][0];
							var1 = true;
							break;
						}
					}
					if (!var1)
					{
						cout << "ID de pais erroneo o medallero repetido" << endl;
						Sleep(700); // Pausa después de un mensaje de error
					}
				}
			} while (!var1);
			if (cancelado)
				break;
			
			// PAIS 2 (PLATA)
			do
			{
				cout << "MEDALLA DE PLATA --> ID País: ";
				cin >> idPais2;
				if (idPais2 == -1)
				{
					for (int i = 0; i < 3; i++)
					{
						deporte_medallas[id - 1][i] = 0;
						file_competencia.deporte_medallas[id - 1][i] = 0;
					}
					cout << "Carga de medallas cancelada." << endl;
					cancelado = true;
					break;
				}
				else
				{
					for (int a = 0; a < 16; a++)
					{
						if (idPais2 == competencia[id - 1].paises[a])
						{
							deporte_medallas[id - 1][1] = idPais2;
							file_competencia.deporte_medallas[id - 1][1] = deporte_medallas[id - 1][1];
							var2 = true;
							break;
						}
					}
					if (!var2)
					{
						cout << "ID de pais erroneo o medallero repetido" << endl;
						Sleep(700); // Pausa después de un mensaje de error
					}
				}
			} while (!var2);
			if (cancelado)
				break;
			
			// PAIS 3 (BRONCE)
			do
			{
				cout << "MEDALLA DE BRONCE --> ID País: ";
				cin >> idPais3;
				if (idPais3 == -1)
				{
					for (int i = 0; i < 3; i++)
					{
						deporte_medallas[id - 1][i] = 0;
						file_competencia.deporte_medallas[id - 1][i] = 0;
					}
					cout << "Carga de medallas cancelada." << endl;
					cancelado = true;
					break;
				}
				else
				{
					for (int a = 0; a < 16; a++)
					{
						if (idPais3 == competencia[id - 1].paises[a])
						{
							deporte_medallas[id - 1][2] = idPais3;
							file_competencia.deporte_medallas[id - 1][2] = deporte_medallas[id - 1][2];
							var3 = true;
							break;
						}
					}
					if (!var3)
					{
						cout << "ID de pais erroneo o medallero repetido" << endl;
						Sleep(700); // Pausa después de un mensaje de error
					}
				}
			} while (!var3);
			if (cancelado)
				break;
			
			// MUESTRO LOS DEPORTES CARGADOS
			cout << "\nMedallas Cargadas: ";
			for (int i = 0; i < 3; i++)
			{
				cout << deporte_medallas[id - 1][i] << (i < 2 ? ", " : " ");
			}
			cout << endl;
			Sleep(2000);
		}
		else
		{
			cout << "Deporte no encontrado." << endl;
		}
	} while (!encon);
}

// Función para cargar deportes colectivos
void cargaPorDeporteColectivo(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia)
{
	// Carga inicial de datos
	cout << "Cargando listado Deportes Colectivos" << endl;
	Sleep(1000);
	barradecarga(1000, 60);
	Sleep(1000);
	system("cls");
	
	mostrarDeportesColectivos();
	int id, idPais1, idPais2, idPais3;
	bool encon = false, var1 = false, var2 = false, var3 = false;
	bool cancelado = false;
	
	do
	{
		// Selección de deporte
		cout << "Ingrese ID del Deporte a cargar: ";
		cin >> id;
		system("cls");
		
		// Verificar si el ID está en los deportes colectivos
		encon = verificaColectivos(id);
		
		if (encon)
		{
			// Validar si ya fue cargado
			if (deporteCargado(id, deporte_medallas))
			{
				cout << "El deporte ya tiene medallas asignadas. No se puede cargar nuevamente." << endl;
				continue;
			}
			
			cout << "Listado de países participantes:" << endl;
			imprimircompetencia(id, competencia);
			
			cout << "Ingrese -1 para cancelar la carga de medallas." << endl;
			cout << endl;
			
			// PAIS 1 (ORO)
			do
			{
				cout << "MEDALLA DE ORO --> ID País: ";
				cin >> idPais1;
				if (idPais1 == -1)
				{
					for (int i = 0; i < 3; i++)
					{
						deporte_medallas[id - 1][i] = 0;
						file_competencia.deporte_medallas[id - 1][i] = 0;
					}
					cout << "Carga de medallas cancelada." << endl;
					cancelado = true;
					break;
				}
				else
				{
					for (int a = 0; a < 16; a++)
					{
						if (idPais1 == competencia[id - 1].paises[a])
						{
							deporte_medallas[id - 1][0] = idPais1;
							file_competencia.deporte_medallas[id - 1][0] = deporte_medallas[id - 1][0];
							var1 = true;
							break;
						}
					}
					if (!var1)
					{
						cout << "ID de pais erroneo o medallero repetido" << endl;
						Sleep(700); // Pausa después de un mensaje de error
					}
				}
			} while (!var1);
			if (cancelado)
				break;
			
			// PAIS 2 (PLATA)
			do
			{
				cout << "MEDALLA DE PLATA --> ID País: ";
				cin >> idPais2;
				if (idPais2 == -1)
				{
					for (int i = 0; i < 3; i++)
					{
						deporte_medallas[id - 1][i] = 0;
						file_competencia.deporte_medallas[id - 1][i] = 0;
					}
					cout << "Carga de medallas cancelada." << endl;
					cancelado = true;
					break;
				}
				else
				{
					for (int a = 0; a < 16; a++)
					{
						if (idPais2 == competencia[id - 1].paises[a])
						{
							deporte_medallas[id - 1][1] = idPais2;
							file_competencia.deporte_medallas[id - 1][1] = deporte_medallas[id - 1][1];
							var2 = true;
							break;
						}
					}
					if (!var2)
					{
						cout << "ID de pais erroneo o medallero repetido" << endl;
						Sleep(700); // Pausa después de un mensaje de error
					}
				}
			} while (!var2);
			if (cancelado)
				break;
			
			// PAIS 3 (BRONCE)
			do
			{
				cout << "MEDALLA DE BRONCE --> ID País: ";
				cin >> idPais3;
				if (idPais3 == -1)
				{
					for (int i = 0; i < 3; i++)
					{
						deporte_medallas[id - 1][i] = 0;
						file_competencia.deporte_medallas[id - 1][i] = 0;
					}
					cout << "Carga de medallas cancelada." << endl;
					cancelado = true;
					break;
				}
				else
				{
					for (int a = 0; a < 16; a++)
					{
						if (idPais3 == competencia[id - 1].paises[a])
						{
							deporte_medallas[id - 1][2] = idPais3;
							file_competencia.deporte_medallas[id - 1][2] = deporte_medallas[id - 1][2];
							var3 = true;
							break;
						}
					}
					if (!var3)
					{
						cout << "ID de pais erroneo o medallero repetido" << endl;
						Sleep(700); // Pausa después de un mensaje de error
					}
				}
			} while (!var3);
			if (cancelado)
				break;
			
			// MUESTRO LOS DEPORTES CARGADOS
			cout << "\nMedallas Cargadas: ";
			for (int i = 0; i < 3; i++)
			{
				cout << deporte_medallas[id - 1][i] << (i < 2 ? ", " : " ");
			}
			cout << endl;
			Sleep(2000);
		}
		else
		{
			cout << "Deporte no encontrado." << endl;
		}
	} while (!encon);
}

bool cargar_medallas(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia)
{
	char opcion;
	
	bool cargaExitosa = false;
	cout << "Menu Carga de Medallas por Deporte ..." << endl;
	Sleep(1500);
	system("cls");
	do
	{
		
		cout << "Menu Carga Medallas por Deporte" << endl;
		cout << "==========================" << endl;
		cout << "1.- Carga por Deporte Individual" << endl;
		cout << "2.- Carga por Deporte Colectivo" << endl;
		cout << "X.- Volver al menu principal" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		system("cls");
		
		switch (opcion)
		{
		case '1':
		{
			cargaPorDeporteIndividual(competencia, deporte_medallas, file_competencia);
			cargaExitosa = true;
			cout << "Carga por deporte individual con exito" << endl;
			
			Sleep(2000);
			system("cls");
		}
		break;
		case '2':
		{
			cargaPorDeporteColectivo(competencia, deporte_medallas, file_competencia);
			cargaExitosa = true;
			cout << "Carga por deporte colectivo con exito" << endl;
			
			Sleep(2000);
			system("cls");
		}
		break;
		case 'X':
		case 'x':
		{
			system("cls");
			
			cout << "Volviendo al menu principal..." << endl;
			Sleep(1000);
		}
		break;
		default:
			cout << "Opcion invalida, por favor intente nuevamente." << endl;
			break;
		}
	} while (opcion != 'X' && opcion != 'x');
	
	return cargaExitosa;
}
