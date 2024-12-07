#include<iostream>
#include<windows.h>
#include <iomanip>
//INCLUIR ARCHIVOS CABECERA ACA
#include"deportes.h"
#include"paises.h"
#include"mostrar_medallero.h"
#include"cargar_medallas.h"
#include"visual.h"
using namespace std;



int medallasPorPaises[197][3];
void medalleroPaises(){
	int medallasTotales[197];
	
	for(int a=1;a<197;a++){//pone en cero la matriz
		for(int j=0;j<3;j++){
			medallasPorPaises[a][j]=0;
		}
	}
	
	for(int j=0;j<3;j++){//setea los valores de las medallas que gano cada pais
		for(int i=1;i<88;i++){
			if(deporte_medallas[i][j]!=0){
				medallasPorPaises[deporte_medallas[i][j]][j]++;
			}
		}
	}
	
	for(int a=1;a<197;a++){
		medallasTotales[a]=0;
	}
	
	for(int j=0;j<3;j++){
		for(int i=1;i<197;i++){
			if(medallasPorPaises[i][j]!=0){
				medallasTotales[i]++;
			}
		}
	}
	
	barradecarga(1000,60);
	Sleep(400);
	system("cls");
	cout<<"--------------------"<<endl;
	cout<<" Medallero por Pais"<<endl;
	cout<<"--------------------"<<endl;
	cout<<endl;
	
	for(int i=1; i<197;i++){
		if(medallasTotales[i]!=0){
			cout<<"Pais: ";
			imprimirPais(i);
			cout<<" --> "<<medallasTotales[i]<<" medallas totales."<<endl;
			Sleep(100);
			cout<<endl;
		}
	}
	
	cin.get();
	system("pause");
	system("cls");
}
	
void medalleroDeportes(){
	barradecarga(1000,60);
	Sleep(400);
	system("cls");
	cout<<"-----------------------"<<endl;
	cout<<" Medallero por Deporte"<<endl;
	cout<<"-----------------------"<<endl;
	cout<<endl;
	for(int i=1; i<88;i++){
		if(deporte_medallas[i][0]!=0){
			cout<<"Deporte: ";
			imprimirDeporte(i);
			cout<<endl;
			Sleep(100);
			cout<<"ORO: ";
			imprimirPais(deporte_medallas[i][0]);
			Sleep(100);
			cout<<endl;
			cout<<"PLATA: ";
			imprimirPais(deporte_medallas[i][1]);
			Sleep(100);
			cout<<endl;
			cout<<"BRONCE: ";
			imprimirPais(deporte_medallas[i][2]);
			cout<<endl;
		}
	}
	
	cin.get();
	system("pause");
	system("cls");
}

void intercambio(int& a, int& b){
	int aux=a;
	a=b;
	b=aux;
}

void medalleroTop(){
	int top=0,medallasTotales[197],indicesPaises[197], oroPaises[197], plataPaises[197], broncePaises[197];//numero de medallas totales por pais
	int pasada=1, k, intercambios=1;
	for(int a=1;a<197;a++){
		medallasTotales[a]=0;
		indicesPaises[a]=a;
	}
	for(int j=0;j<3;j++){
		for(int i=1;i<197;i++){
			if(medallasPorPaises[i][j]!=0){
				medallasTotales[i]++;
			}
		}
	}
	
	for(int i=1;i<197;i++){
		oroPaises[i]=medallasPorPaises[i][0];
		plataPaises[i]=medallasPorPaises[i][1];
		broncePaises[i]=medallasPorPaises[i][2];
	}
	
	while(pasada<197 and intercambios){
		intercambios=0;
		for(k=1;k<197-pasada;k++){
			if (oroPaises[k] < oroPaises[k + 1] or // Más medallas de oro primero
				(oroPaises[k] == oroPaises[k + 1] and plataPaises[k] < plataPaises[k + 1]) or // Más medallas de plata si empatan en oro
				(oroPaises[k] == oroPaises[k + 1] and plataPaises[k] == plataPaises[k + 1] and broncePaises[k] < broncePaises[k + 1]) // Más medallas de bronce si empatan en oro y plata
				){
				intercambio(oroPaises[k], oroPaises[k + 1]);
				intercambio(plataPaises[k], plataPaises[k + 1]);
				intercambio(broncePaises[k], broncePaises[k + 1]);
				intercambio(medallasTotales[k], medallasTotales[k+1]);
				intercambio(indicesPaises[k], indicesPaises[k + 1]);
				intercambios = 1;
			}
		}
		pasada=pasada+1;
	}
	barradecarga(1000,60);
	Sleep(400);
	system("cls");
	cout<<"Ingrese la cantidad de posiciones que desea ver: ";
	cin>>top;
	system("cls");
	cout<<endl;
	
	cout << setw(9) << "Posicion" << setw(17) << left << "Pais" 
		<< setw(8) << right << "Oro" 
		<< setw(8) << "Plata" 
		<< setw(8) << "Bronce" 
		<< setw(8) << "Total" << endl;
	
	cout << "----------------------------------------------------------" << endl;
	
	for (int i = 1; i <= top; i++) {
		cout << setw(9) << right << i << ". ";
		Sleep(50);
		cout << setw(17) << left; // Alinear el nombre del país a la izquierda
		imprimirPais(indicesPaises[i]); // Imprime el nombre del país
		cout << setw(8) << right << oroPaises[i]   // Valores alineados a la derecha
			<< setw(8) << plataPaises[i]
			<< setw(8) << broncePaises[i]
			<< setw(8) << medallasTotales[i] << endl;
		Sleep(50);
	}
	
	cin.get();
	system("pause");
	system("cls");
}				

void mostrarmedallas(){
	
	char opcion;
	do{
		cout << "===========================" << endl;
		cout << "         Menu Medallero" << endl;
		cout << "===========================" << endl;
		cout << "1.- Medallero por Pais" << endl;
		cout << "2.- Medallero por Deporte" << endl;
		cout << "3.- Top Medallero" << endl;
		cout << "X.- Volver al menu principal" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case '1':
			// Lógica para Medallero por País
			cout << "Mostrando Medallero por Pais..." << endl;
			Sleep(1000);
			medalleroPaises();
			break;
		case '2':
			// Lógica para Medallero por Deporte
			cout << "Mostrando Medallero por Deporte..." << endl;
			Sleep(1000);
			medalleroDeportes();
			break;
		case '3':
			// Lógica para Top Medallero
			cout << "Mostrando Top Medallero..." << endl;
			Sleep(1000);
			medalleroTop();
			break;
		case 'X':
		case 'x':
			cout << "Volviendo al menu principal..." << endl;
			Sleep(1000);
			system("cls");
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
			break;
		}
	}while(opcion != 'X' && opcion != 'x');
	
}
