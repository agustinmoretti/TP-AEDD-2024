#include<iostream>
//INCLUIR ARCHIVOS CABECERA ACA 
#include"menu.h"
#include"bienvenida.h"
#include"login.h"
#include"deportes.h"
#include"paises.h"
#include"mostrar_medallero.h"
#include"cargar_medallas.h"
#include"gen_competencia.h"
#include"visual.h"

int  deporte_medallas[totalDeportes][3];
competidores competencia[totalDeportes];

using namespace std;

int main (int argc, char *argv[]) {
	
	for(int i=0;i<totalDeportes;i++){
		for(int j=0;j<3;j++){
			deporte_medallas[i][j]=0;
		}
	}
	
	//bienvenida
	bienvenida();
	system("cls");
	
	//iniciar sesion
	system("COLOR 87");
	if(login()){
		//menu principal
		system("cls");
		menuPrincipal();
	}
	else {
		cout<<"Limite de ingresos erroneos alcanzado. Por favor, reinicie el programa para reintentar."<<endl;
	}
	//OFICIAL
	return 0;
}

