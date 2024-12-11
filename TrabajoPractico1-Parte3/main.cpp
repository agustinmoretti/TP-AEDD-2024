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
	competidores competencia[totalDeportes];
	int deporte_medallas[totalDeportes][3];
	archivoCompetencia file_competencia;
	
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
	//OFICIAL
	return 0;
}

