#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include "deportes.h"
#include "paises.h"
#include "submenu_gen_competencia.h"
#include "gen_competencia.h"
#include "visual.h"
#include <time.h>
using namespace std;
void cargar_variable(competidores competencia[], int deporte_medallas[][3], archivoCompetencia file_competencia)
{
	for (int i = 0; i < 87; i++)
	{
		competencia[i] = file_competencia.competencia[i];
	}
	for (int i = 0; i < 87; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			deporte_medallas[i][j] = file_competencia.deporte_medallas[i][j];
		}
	}
}
void cargar_archivo(string nombrearchivo, archivoCompetencia &file_competencia)
{
	// cargo el archivo
	// Guarda competencia en el archivo.bin con en nombre pedido
	ofstream archivo(nombrearchivo, ios::binary);
	if (archivo)
	{
		archivo.write(reinterpret_cast<char *>(&file_competencia), sizeof(file_competencia));
		archivo.close();
		cout << "Archivo generado exitosamente: " << nombrearchivo << endl;
		Sleep(3000);
		system("cls");
	}
	else
	{
		cout << "Error al crear el archivo." << endl;
		Sleep(1500);
		system("cls");
	}
}
void asignar_var_archivo(archivoCompetencia &file_competencia, competidores competencia[], int deporte_medallas[][3])
{
	for (int i = 0; i < 87; i++)
	{
		file_competencia.competencia[i] = competencia[i];
	}
	for (int i = 0; i < 87; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			file_competencia.deporte_medallas[i][j] = deporte_medallas[i][j];
		}
	}
}

string crearfecha(archivoCompetencia &file_competencia)
{
	time_t ahora;
	struct tm *fecha;
	time(&ahora);
	fecha = localtime(&ahora);
	file_competencia.fechaCreacion = *fecha;
	// Convertir la fecha a string
	string segundos = to_string(fecha->tm_sec);
	string minutos = to_string(fecha->tm_min);
	string hora = to_string(fecha->tm_hour);
	string dia = to_string(fecha->tm_mday);
	string mes = to_string(fecha->tm_mon + 1);
	string anio = to_string(fecha->tm_year + 1900);
	
	// Asegurar que los valores sean siempre de dos digitos
	if (segundos.length() < 2)
		segundos = "0" + segundos;
	if (minutos.length() < 2)
		minutos = "0" + minutos;
	if (hora.length() < 2)
		hora = "0" + hora;
	if (mes.length() < 2)
		mes = "0" + mes;
	
	// Crear el nombre del archivo
	string nombrearchivo = anio + "-" + mes + "-" + dia + "-" + hora + "-" + minutos + "-" + segundos + ".bin";
	
	return nombrearchivo;
}

bool cargarCompetencia(archivoCompetencia &file_competencia)
{ // SE ENCARGA DE CARGAR LOS DATOS GUARDADOS EN LOS ARCHIVOS BINARIOS
	char nombreArchivo[30];
	bool cargado = false;
	
	// El usuario ingresa el nombre del archivo
	cout << "Ingrese el nombre del archivo (AAAA-MM-DD-HH-MM-SS.bin): ";
	cin >> nombreArchivo; // IMPORTANTE, TIENE QUE AGREGARSE EL .bin AL NOMBRE DEL ARCHIVO PARA QUE FUNCIONE LA BUSQUEDA
	
	// Leer archivo con el nombre ingresado
	ifstream archivo(nombreArchivo, ios::binary);
	if (archivo)
	{
		archivo.read(reinterpret_cast<char *>(&file_competencia), sizeof(file_competencia));
		archivo.close();
		cargado = true;
		// Mostrar detalles de la competencia cargada
		cout << "Archivo cargado exitosamente." << endl;
		cout << "Numero de Legajo del creador: " << file_competencia.legajo << endl;
		cout << "Fecha de creación del archivo: " << file_competencia.fechaCreacion.tm_mday << "/" << file_competencia.fechaCreacion.tm_mon + 1 << "/" << file_competencia.fechaCreacion.tm_year + 1900 << endl;
		Sleep(3500);
		system("cls");
	}
	
	return cargado;
}

bool submenuCompetencia(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia)
{
	char opcion;
	bool competenciaGenerada = false, competenciaCargada = false;
	
	cout << "Menu generar competencia ..." << endl;
	Sleep(1500);
	system("cls");
	
	do
	{
		
		cout << "Menu generar competencia" << endl;
		cout << "==========================" << endl;
		cout << "1.- Generar Competencia" << endl;
		cout << "2.- Cargar Competencia" << endl;
		cout << "X.- Volver al menu principal" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		system("cls");
		
		switch (opcion)
		{
		case '1':
		{
			if (competenciaGenerada or competenciaCargada)
			{
				cout << "Ya se genero anteriormente " << endl;
				Sleep(1000);
				system("cls");
				cout << "Volviendo al Menu Generar Competencias ..." << endl;
				Sleep(500);
				system("cls");
			}
			else
			{
				competenciaGenerada = generarCompetencia(competencia, deporte_medallas); // genero la competencia
				
				// asigno la competencia y medallas a la variable
				asignar_var_archivo(file_competencia, competencia, deporte_medallas);
				// creo la hora actual
				string nombrearchivo = crearfecha(file_competencia);
				// cargo variable en el archivo
				cargar_archivo(nombrearchivo, file_competencia);
				
				if (competenciaGenerada)
				{
					cout << "Competencia generada correctamente." << endl;
					Sleep(1000);
					system("cls");
				}
				else
				{
					cout << "Error al generar la competencia." << endl;
					Sleep(1000);
					system("cls");
				}
			}
		}
		break;
		case '2':
		{
			if (competenciaGenerada or competenciaCargada)
			{
				cout << "Ya se cargo anteriormente " << endl;
				Sleep(1000);
				system("cls");
				cout << "Volviendo al Menu Generar Competencias ..." << endl;
				Sleep(500);
				system("cls");
			}
			else
			{
				competenciaCargada = cargarCompetencia(file_competencia);
				
				// Asignamos los valores cargados desde al archivo a las variables y estructuras que manipulamos en el programa
				cargar_variable(competencia, deporte_medallas, file_competencia);
				
				if (competenciaCargada)
				{
					cout << "Competencia cargada correctamente." << endl;
					Sleep(1000);
					system("cls");
				}
				else
				{
					cout << "Error al cargar la competencia." << endl;
					Sleep(1000);
					system("cls");
				}
			}
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
	
	return (competenciaGenerada or competenciaCargada);
}

