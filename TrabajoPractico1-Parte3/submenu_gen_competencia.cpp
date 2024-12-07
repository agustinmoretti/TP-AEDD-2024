#include<iostream>
#include<windows.h>
#include<ctime>
#include<fstream>
using namespace std;

#include"deportes.h"
#include"paises.h"
#include"submenu_gen_competencia.h"
#include"gen_competencia.h"
#include"visual.h"

archivoCompetencia file_competencia;

bool cargarCompetencia(){ // SE ENCARGA DE CARGAR LOS DATOS GUARDADOS EN LOS ARCHIVOS BINARIOS
	char nombreArchivo[30];
	bool cargado=false;
	
	// El usuario ingresa el nombre del archivo
	cout<<"Ingrese el nombre del archivo (AAAA-MM-DD-HH-MM-SS): ";
	cin>>nombreArchivo;
	
	// Leer archivo con el nombre ingresado
	ifstream archivo(nombreArchivo, ios::binary);
	if (archivo) {
		archivo.read((char*)(&file_competencia), sizeof(file_competencia));
		archivo.close();
		
		// Mostrar detalles de la competencia cargada
		cout << "Archivo cargado exitosamente." << endl;
		cout << "Numero de Legajo del creador: " << file_competencia.legajo << endl;
		cout << "Fecha de creación del archivo: " << file_competencia.fechaCreacion.tm_mday << "/" << file_competencia.fechaCreacion.tm_mon + 1 << "/" << file_competencia.fechaCreacion.tm_year + 1900 << endl;
		Sleep(500);
		system("cls");
		cargado=true;
	}
	
	return cargado;
}

bool submenuCompetencia(){
	char opcion;
	bool competenciaGenerada = false, competenciaCargada=false;
	time_t ahora = time(0);
	
	cout<<"Menu generar competencia ..."<<endl;
	Sleep(1500);
	system("cls");
	
	do {
		
		cout << "Menu generar competencia" << endl;
		cout << "==========================" << endl;
		cout << "1.- Generar Competencia" << endl;
		cout << "2.- Cargar Competencia" << endl;
		cout << "X.- Volver al menu principal" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		system("cls");
		
		switch (opcion) {
		case '1':{  //FALTA AGREGARLE QUE CREE EL ARCHIVO BINARIO CORRESPONDIENTE, GUARDANDO LOS DATOS DE LA COMPETENCIA GENERADA Y LOS MEDALLEROS
			if(competenciaGenerada) {
				cout<<"Ya se genero anteriormente "<<endl;
				Sleep(1000);
				system("cls");
				cout<<"Volviendo al Menu Principal ..."<<endl;
				Sleep(500);
				system("cls");
			}else{
				competenciaGenerada = generarCompetencia();
				
				for(int i = 0; i <= totalDeportes; i++){
					file_competencia.competencia[i]=competencia[i];
				}
				for(int i = 0; i <= totalDeportes; i++){
					for(int j=0; j<3; j++){
						file_competencia.deporte_medallas[i][j]=deporte_medallas[i][j];
					}
				}
				
				file_competencia.fechaCreacion = *localtime(&ahora);
				
				cout<<"Ingrese su numero de legajo: ";
				cin>>file_competencia.legajo;
				system("cls");
				
				//asigna la fechaCreacion a el nombre del archivo
				char nombreArchivo[30];
				strftime(nombreArchivo, sizeof(nombreArchivo), "%Y-%m-%d-%H-%M-%S.bin", &file_competencia.fechaCreacion);
				
				//Guarda competencia en el archivo.bin con en nombre pedido
				ofstream archivo(nombreArchivo, ios::binary);
				if (archivo) {
					archivo.write((char*)(&file_competencia), sizeof(file_competencia));
					archivo.close();
					cout << "Archivo generado exitosamente: " << nombreArchivo << endl;
					Sleep(1000);
					system("cls");
				} else {
					cout << "Error al crear el archivo." << endl;
					Sleep(1000);
					system("cls");
				}
				
				if (competenciaGenerada) {
					cout << "Competencia generada correctamente." << endl;
					Sleep(1000);
					system("cls");
				} else {
					cout << "Error al generar la competencia." << endl;
					Sleep(1000);
					system("cls");
				}
			}
		}
			break;
		case '2':{
			if(competenciaCargada) {
				cout<<"Ya se cargo anteriormente "<<endl;
				Sleep(1000);
				system("cls");
				cout<<"Volviendo al Menu Principal ..."<<endl;
				Sleep(500);
				system("cls");
			}
			else{
				competenciaCargada = cargarCompetencia();
				
				//Asignamos los valores cargados desde al archivo a las variables y estructuras que manipulamos en el programa
				for(int i = 0; i <= totalDeportes; i++){
					competencia[i]=file_competencia.competencia[i];
				}
				for(int i = 0; i <= totalDeportes; i++){
					for(int j=0; j<3; j++){
						deporte_medallas[i][j]=file_competencia.deporte_medallas[i][j];
					}
				}
				
				if (competenciaCargada) {
					cout << "Competencia cargada correctamente." << endl;
					Sleep(1000);
					system("cls");
				} else {
					cout << "Error al cargar la competencia." << endl;
					Sleep(1000);
					system("cls");
				}
			}
		}
			break;
		case 'X':
		case 'x':{
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
	
	return competenciaGenerada or competenciaCargada;
}
