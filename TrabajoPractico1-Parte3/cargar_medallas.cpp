#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;
//INCLUIR ARCHIVOS CABECERA ACA
#include"cargar_medallas.h"
#include"deportes.h"
#include"paises.h"
#include"gen_competencia.h"
#include"submenu_gen_competencia.h"
#include"visual.h"

bool deporteCargado(int id){//funcion que se encarga de verificar si un deporte ya fue cargado
	return deporte_medallas[id][0] != 0 || deporte_medallas[id][1] != 0 || deporte_medallas[id][2] != 0;
}

bool paisRecibioMedalla(int id, int idPais){//
	for (int j = 0; j < 3; j++) {
		if (deporte_medallas[id][j] == idPais){
			return true;
		}
	}
	return false;
}

void cargaPorDeporteIndividual(){
	// Carga inicial de datos
	cout<< "Cargando listado Deportes Individuales" <<endl;
	Sleep(1000);
	barradecarga(1000, 60);
	Sleep(1000);
	system("cls");
	
	mostrarDeportesIndividuales();
	int id, idPais1, idPais2, idPais3;
	bool encon=false, var1=false, var2=false, var3=false;
	
	do {
		// Selección de deporte
		cout<< "Ingrese ID del Deporte a cargar: ";
		cin>>id;
		system("cls");
		
		// Verificar si el ID está en los deportes individuales
		for (int j = 0; j < 53; j++){
			if (id == indicesIndividuales[j]){
				encon = true;
				break;
			}
		}
		
		if (encon){
			// Validar si ya fue cargado
			if (deporteCargado(id)){
				cout << "El deporte ya tiene medallas asignadas. No se puede cargar nuevamente." << endl;
				continue;
			}
			
			cout<< "Listado de países participantes:" <<endl;
			imprimircompetencia(id);
			
			cout<<"Ingrese -1 para cancelar la carga de medallas."<<endl;
			cout<<endl;
			
			// PAIS 1 (ORO)
			do {
				cout<< "MEDALLA DE ORO --> ID País: ";
				cin>>idPais1;
				if(idPais1 == -1){
					for(int i=0;i<3;i++){
						deporte_medallas[id][i] = 0;
						file_competencia.deporte_medallas[id][i] = 0;
					}
					cout<< "Carga de medallas cancelada." <<endl;
					return;
				}else{
					if (!paisRecibioMedalla(id, idPais1)){
						deporte_medallas[id][0] = idPais1;
						file_competencia.deporte_medallas[id][0]=deporte_medallas[id][0];
						var1 = true;
					}else{
						cout << "ID de país inválido o repetido." << endl;
					}
				}
			}while (!var1);
			
			// PAIS 2 (PLATA)
			do {
				cout<< "MEDALLA DE PLATA --> ID País: ";
				cin>>idPais2;
				if(idPais2 == -1){
					for(int i=0;i<3;i++){
						deporte_medallas[id][i] = 0;
						file_competencia.deporte_medallas[id][i] = 0;
					}
					cout<< "Carga de medallas cancelada." <<endl;
					return;
				}else{
					if (!paisRecibioMedalla(id, idPais2)){
						deporte_medallas[id][1] = idPais2;
						file_competencia.deporte_medallas[id][1]=deporte_medallas[id][1];
						var2 = true;
					}else{
						cout << "ID de país inválido o repetido." << endl;
					}
				}
			}while (!var2);
			
			// PAIS 3 (BRONCE)
			do {
				cout<< "MEDALLA DE BRONCE --> ID País: ";
				cin>>idPais3;
				if(idPais3 == -1){
					for(int i=0;i<3;i++){
						deporte_medallas[id][i] = 0;
						file_competencia.deporte_medallas[id][i] = 0;
					}
					cout<< "Carga de medallas cancelada." <<endl;
					return;
				}else{
					if (!paisRecibioMedalla(id, idPais3)){
						deporte_medallas[id][2] = idPais3;
						file_competencia.deporte_medallas[id][2]=deporte_medallas[id][2];
						var3 = true;
					}else{
						cout << "ID de país inválido o repetido." << endl;
					}
				}
			}while (!var3);
			
			// MUESTRO LOS DEPORTES CARGADOS
			cout<< "\nMedallas Cargadas: ";
			for (int i = 0; i < 3; i++){
				cout<<deporte_medallas[id][i]<<(i < 2 ? ", " : " ");
			}
			cout<<endl;
			Sleep(2000);
		}else{
			cout<< "Deporte no encontrado." <<endl;
		}
	}while (!encon);
}

// Función para cargar deportes colectivos
void cargaPorDeporteColectivo(){
	// Carga inicial de datos
	cout<< "Cargando listado Deportes Colectivos" <<endl;
	Sleep(1000);
	barradecarga(1000, 60);
	Sleep(1000);
	system("cls");
	
	mostrarDeportesColectivos();
	int id, idPais1, idPais2, idPais3;
	bool encon=false, var1=false, var2=false, var3=false;
	
	do {
		// Selección de deporte
		cout<< "Ingrese ID del Deporte a cargar: ";
		cin>>id;
		system("cls");
		
		// Verificar si el ID está en los deportes colectivos
		for (int j = 0; j < 53; j++){
			if (id == indicesColectivos[j]){
				encon = true;
				break;
			}
		}
		
		if (encon){
			// Validar si ya fue cargado
			if (deporteCargado(id)){
				cout << "El deporte ya tiene medallas asignadas. No se puede cargar nuevamente." << endl;
				continue;
			}
			
			cout<< "Listado de países participantes:" <<endl;
			imprimircompetencia(id);
			
			cout<<"Ingrese -1 para cancelar la carga de medallas."<<endl;
			cout<<endl;
			
			// PAIS 1 (ORO)
			do {
				cout<< "MEDALLA DE ORO --> ID País: ";
				cin>>idPais1;
				if(idPais1 == -1){
					for(int i=0;i<3;i++){
						deporte_medallas[id][i] = 0;
						file_competencia.deporte_medallas[id][i] = 0;
					}
					cout<< "Carga de medallas cancelada." <<endl;
					return;
				}else{
					if (!paisRecibioMedalla(id, idPais1)){
						deporte_medallas[id][0] = idPais1;
						file_competencia.deporte_medallas[id][0]=deporte_medallas[id][0];
						var1 = true;
					}else{
						cout << "ID de país inválido o repetido." << endl;
					}
				}
			}while (!var1);
			
			// PAIS 2 (PLATA)
			do {
				cout<< "MEDALLA DE PLATA --> ID País: ";
				cin>>idPais2;
				if(idPais2 == -1){
					for(int i=0;i<3;i++){
						deporte_medallas[id][i] = 0;
						file_competencia.deporte_medallas[id][i] = 0;
					}
					cout<< "Carga de medallas cancelada." <<endl;
					return;
				}else{
					if (!paisRecibioMedalla(id, idPais2)){
						deporte_medallas[id][1] = idPais2;
						file_competencia.deporte_medallas[id][1]=deporte_medallas[id][1];
						var2 = true;
					}else{
						cout << "ID de país inválido o repetido." << endl;
					}
				}
			}while (!var2);
			
			// PAIS 3 (BRONCE)
			do {
				cout<< "MEDALLA DE BRONCE --> ID País: ";
				cin>>idPais3;
				if(idPais3 == -1){
					for(int i=0;i<3;i++){
						deporte_medallas[id][i] = 0;
						file_competencia.deporte_medallas[id][i] = 0;
					}
					cout<< "Carga de medallas cancelada." <<endl;
					return;
				}else{
					if (!paisRecibioMedalla(id, idPais3)){
						deporte_medallas[id][2] = idPais3;
						file_competencia.deporte_medallas[id][2]=deporte_medallas[id][2];
						var3 = true;
					}else{
						cout << "ID de país inválido o repetido." << endl;
					}
				}
			}while (!var3);
			
			// MUESTRO LOS DEPORTES CARGADOS
			cout<< "\nMedallas Cargadas: ";
			for (int i = 0; i < 3; i++){
				cout<<deporte_medallas[id][i]<<(i < 2 ? ", " : " ");
			}
			cout<<endl;
			Sleep(2000);
		}else{
			cout<< "Deporte no encontrado." << endl;
		}
	}while (!encon);
}	
	
bool cargar_medallas(){
	char opcion;
	
	bool cargaExitosa = false;
	cout<<"Menu Carga de Medallas por Deporte ..."<<endl;
	Sleep(1500);
	system("cls");
	do {
		
		cout << "Menu Carga Medallas por Deporte" << endl;
		cout << "==========================" << endl;
		cout << "1.- Carga por Deporte Individual" << endl;
		cout << "2.- Carga por Deporte Colectivo" << endl;
		cout << "X.- Volver al menu principal" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		system("cls");
		
		switch (opcion) {
		case '1':{
			cargaPorDeporteIndividual();
			cargaExitosa = true;
			cout<<"Carga por deporte individual con exito"<<endl;
			
			char nombreArchivo[30];
			strftime(nombreArchivo, sizeof(nombreArchivo), "%Y-%m-%d-%H-%M-%S.bin", &file_competencia.fechaCreacion);
			
			//Reescribe competencia y guarda las medallas cargadas en los procesos anteriores en el archivo.bin con en nombre pedido
			ofstream archivo(nombreArchivo, ios::binary | ios::out | ios::trunc);
			if (archivo) {
				archivo.write((char*)(&file_competencia), sizeof(file_competencia));
				archivo.close();
				cout << "Archivo sobrescrito exitosamente: " << nombreArchivo << endl;
				Sleep(1000);
				system("cls");
			} else {
				cout << "Error al sobrescribir el archivo." << endl;
				Sleep(1000);
				system("cls");
			}
			
			Sleep(2000);
			system("cls");
		}
			break;
		case '2':{
			cargaPorDeporteColectivo();
			cargaExitosa = true;
			cout<<"Carga por deporte colectivo con exito"<<endl;
			
			char nombreArchivo[30];
			strftime(nombreArchivo, sizeof(nombreArchivo), "%Y-%m-%d-%H-%M-%S.bin", &file_competencia.fechaCreacion);
			
			//Reescribe competencia y guarda las medallas cargadas en los procesos anteriores en el archivo.bin con en nombre pedido
			ofstream archivo(nombreArchivo, ios::binary | ios::out | ios::trunc);
			if (archivo) {
				archivo.write((char*)(&file_competencia), sizeof(file_competencia));
				archivo.close();
				cout << "Archivo sobrescrito exitosamente: " << nombreArchivo << endl;
				Sleep(1000);
				system("cls");
			} else {
				cout << "Error al sobrescribir el archivo." << endl;
				Sleep(1000);
				system("cls");
			}
			
			Sleep(2000);
			system("cls");
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
	
	return cargaExitosa;
}
