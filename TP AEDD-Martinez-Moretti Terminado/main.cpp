#include<iostream>
//INCLUIR ARCHIVOS CABECERA ACA 
#include"deportes.h"
#include"menu.h"
#include"bienvenida.h"
#include"login.h"
#include"paises.h"
#include"mostrar_medallero.h"
#include"cargar_medallas.h"
#include"gen_competencia.h"
#include"submenu_gen_competencia.h"
#include"visual.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	
	//Declaracion
	competidores competencia[totalDeportes]; 
	//Inicializacion
	for(int i = 0; i < 87 ;i++){
		for(int j = 0; j < 16 ;j++){
			competencia[i].paises[j] = 0; //Inicializo en 0 los paises
			
		}
		competencia[i].tl = 0; //inicializo en 0 tamaño logico de cada deporte
		
	}
	
	int deporte_medallas[totalDeportes][3];  // declaracion de deportes de medallas
	archivoCompetencia file_competencia;  //declaracion variable para archivo
	
	
	
	//bienvenida
	bienvenida();
	system("cls");
	
	//iniciar sesion
	system("COLOR 87");
	if(login(file_competencia)){
		//menu principal
		system("cls");
		menuPrincipal(competencia, deporte_medallas, file_competencia);
	}
	else {
		cout<<"Limite de ingresos erroneos alcanzado. Por favor, reinicie el programa para reintentar."<<endl;
	}
	
	
	//PRUEBA
	
	//menuPrincipal(competencia,deporte_medallas,file_competencia);
	
	return 0;
}

