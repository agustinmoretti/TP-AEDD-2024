//BIBLIOTECAS ESTANDAR C++
#include<iostream>

using namespace std;
//INCLUIR CABECERAS ACA
#include"deportes.h"
#include"paises.h"
#include"gen_competencia.h"
#include"submenu_gen_competencia.h"
#include"cargar_medallas.h"
#include"visual.h"
#include"mostrar_medallero.h"
#include<windows.h>

void menuPrincipal() {
	char opcion, opSalida;             // Para capturar la opción del usuario
	bool competenciaGenerada = false; // Bandera para saber si la competencia ha sido generada
	bool medallasCargadas = false;    // Bandera para saber si las medallas han sido cargadas correctamente
	
	do {
		// Mostrar el menú principal
		cout << "Menu Principal" << endl;
		cout << "==========================" << endl;
		cout << "1.- Generar Competencia" << endl;
		cout << "2.- Cargar Medallas por Deporte" << endl;
		cout << "3.- Mostrar Medallero" << endl;
		cout << "4.- Mostrar Estadisticas" << endl;
		cout << "X.- Salir de la aplicacion" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		
		// Procesar la opción ingresada
		switch (opcion) {
		case '1':
			competenciaGenerada = submenuCompetencia();
			Sleep(1000);
			system("cls");
			
			break;
			
		case '2':{
			if (competenciaGenerada) {
				medallasCargadas = cargar_medallas();
				if (medallasCargadas) {
					cout << "Medallas cargadas correctamente." << endl;
					Sleep(1000);
					system("cls");
				} else {
					cout << "Error al cargar las medallas." << endl;
					Sleep(1000);
					system("cls");
				}
			} else {
				cout << "Primero debe generar la competencia antes de cargar medallas." << endl;
				Sleep(1000);
				system("cls");
			}
		}
			
			break;
			
		case '3':{
			if (competenciaGenerada && medallasCargadas) {
				mostrarmedallas();
			} else if (!competenciaGenerada) {
				cout << "Primero debe generar la competencia antes de mostrar el medallero." << endl;
				Sleep(2000);
				system("cls");
			} else if (!medallasCargadas) {
				cout << "Primero debe cargar las medallas antes de mostrar el medallero." << endl;
				Sleep(2000);
				system("cls");
			}
		}
			
			break;
			
		case '4':{
			
			
		}
			break;
		
		case 'X':
		case 'x':
			
			cout<<"Desea salir de la aplicacion? (s/n): ";
			cin>>opSalida;
			system("cls");
			
			if(opSalida=='s'){
				cout << "Saliendo de la aplicacion..." << endl;
				break;
			}else{
				break;
			}
			
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
			Sleep(2000);
			system("cls");
		}
		
		cout << endl;  // Línea en blanco para mejor visualización
		
	} while (opSalida != 'S' && opSalida != 's');
}
