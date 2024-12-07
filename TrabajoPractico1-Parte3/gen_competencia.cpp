#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
//INCLUIR ARCHIVOS CABECERA ACA 
#include"deportes.h"
#include"paises.h"
#include"visual.h"

void imprimircompetencia(int indice){
	cout << "Disciplina --> ";
	imprimirDeporte(indice);
	Sleep(100);
	cout<<"ID Pais : ";
	for(int j = 0; j < 16; j++){
		if(competencia[indice].paises[j] != 0){
			cout << competencia[indice].paises[j] << " ";
			Sleep(100);
		}
		
	}
	cout << endl;
	cout << "--------------------------" << endl;
}
	
void imprimircompetencias(){
	for(int i = 1; i <= totalDeportes; i++){
		cout << "Disciplina --> ";
		imprimirDeporte(i); // Cambiado de i a i+1 para que los índices empiecen en 1
		cout<<"-- "<<i<<endl;
		for(int j = 0; j < 16; j++){
			if(competencia[i].paises[j]){
				cout << competencia[i].paises[j] << " ";
			}
			
		}
		cout << endl;
		cout << "--------------------------" << endl;
	}
}		
void cargaAleatoria() {
	srand(time(NULL));  // Inicializar la semilla del generador de números aleatorios
	
	// Para cada disciplina, seleccionar entre 4 y 16 países aleatoriamente
	for (int i = 0; i <= totalDeportes; i++) {
		// Generar aleatoriamente el número de países participantes entre 4 y 16
		int numPaisesSeleccionados = rand() % 13 + 4;  // 4 + (0 a 12) -> rango [4, 16]
		competencia[i].tl = numPaisesSeleccionados;
		
		// ASIGNA PAIS ALEATORIO SIN MEZCLAR
		for (int j = 0; j < numPaisesSeleccionados; j++) {
			competencia[i].paises[j] = rand() % numPaises + 1;  // Generar países del 1 al numPaises
		}
		
		// Si no se seleccionan los 16 países, rellenar con 0
		for (int j = numPaisesSeleccionados; j < 16; j++) {
			competencia[i].paises[j] = 0;
		}
	}
}
	
bool generarCompetencia(){
	bool cargado = false;
	
	cout << "Cargando Competencia ... " << endl;
	Sleep(1000);
	cargaAleatoria();
	cargado = true;
	
	//imprimircompetencias();
	
	return cargado;
}
