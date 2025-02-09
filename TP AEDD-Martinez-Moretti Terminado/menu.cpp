//BIBLIOTECAS ESTANDAR C++
#include<iostream>
#include<windows.h>
#include<fstream>

using namespace std;
//INCLUIR CABECERAS ACA
#include"menu.h"
#include"deportes.h"
#include"paises.h"
#include"gen_competencia.h"
#include"cargar_medallas.h"
#include"visual.h"
#include"mostrar_medallero.h"
#include"estadisticas.h"
bool medallas_cargadas(int deporte_medallas[][3]){
	for(int i=0; i<87; i++){
		for(int j=0; j<3; j++){
			if(deporte_medallas[i][j] != 0){
				return true;
			}
		}
	}
	return false;
}
	void menuPrincipal(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia) {
		char opcion, opSalida;             // Para capturar la opción del usuario
		bool competenciaGenerada = false; // Bandera para saber si la competencia ha sido generada
		bool medallasIngresadas = false;    // Bandera para saber si las medallas han sido cargadas correctamente
		bool medallasCargadas = false; //Bandera para saber si al cargar una competencia, esta tiene cargada medallas o no
		
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
				//ingreso al menu de competencias generadas
				competenciaGenerada = submenuCompetencia(competencia, deporte_medallas, file_competencia);
				Sleep(1000);
				system("cls");
				
				break;
				
			case '2':{
				if (competenciaGenerada) {
					medallasIngresadas = cargar_medallas(competencia, deporte_medallas, file_competencia);
					if (medallasIngresadas) {
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
				medallasCargadas = medallas_cargadas(deporte_medallas); //1->cargado , 0->sin cargar
				if (competenciaGenerada && (medallasIngresadas || medallasCargadas)) {
					mostrarmedallas(deporte_medallas);
				} else if (!competenciaGenerada) {
					cout << "Primero debe generar la competencia antes de mostrar el medallero." << endl;
					Sleep(2000);
					system("cls");
				} else if (!medallasIngresadas && !medallasCargadas) {
					cout << "Primero debe cargar las medallas antes de mostrar el medallero." << endl;
					Sleep(2000);
					system("cls");
				}
			}
				
				break;
				
			case '4':{
				medallasCargadas = medallas_cargadas(deporte_medallas); //1->cargado , 0->sin cargar
				if(competenciaGenerada && (medallasIngresadas || medallasCargadas)){
					menu_estadisticas(deporte_medallas);
				}
				else if(!competenciaGenerada){
					cout << "Primero debe generar la competencia antes de mostrar el medallero." << endl;
					Sleep(2000);
					system("cls");
				}
				else if(!medallasIngresadas && !medallasCargadas){
					cout << "Primero debe cargar las medallas antes de mostrar el medallero." << endl;
					Sleep(2000);
					system("cls");
				}
				//Estadisticas
				
				system("cls");
			}
			break;
			
			case 'X':
			case 'x':
				
				cout<<"Desea salir de la aplicacion? (s/n): ";
				cin>>opSalida;
				system("cls");
				
				if(opSalida=='s'){
					char nombreArchivo[30];
					strftime(nombreArchivo, sizeof(nombreArchivo), "%Y-%m-%d-%H-%M-%S.bin", &file_competencia.fechaCreacion);
					
					//Reescribe competencia y guarda las medallas cargadas en los procesos anteriores en el archivo.bin con en nombre pedido
					ofstream archivo(nombreArchivo, ios::binary | ios::out | ios::trunc);
					if (archivo) {
						archivo.write(reinterpret_cast<char*>(&file_competencia), sizeof(file_competencia));
						archivo.close();
						cout << "Archivo sobrescrito exitosamente: " << nombreArchivo << endl;
						Sleep(2000);
						system("cls");
					} else {
						cout << "Error al sobrescribir el archivo." << endl;
						Sleep(2000);
						system("cls");
					}
					
					cout << "Saliendo de la aplicacion..." << endl;
					break;
				}else if(opSalida=='n'){
					opSalida='0';
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
	
