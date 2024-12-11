#ifndef MENU_H
#define MENU_H
#include<ctime>
//ESTRUCTURA COMPETIDORES
struct competidores{
	int paises[16] = {0}; //INICIALIZO EN 0
	int tl = 0;  
};
struct archivoCompetencia {
	competidores competencia[87];
	int deporte_medallas[87][3];
	tm fechaCreacion;
	int legajo;
};

void menuPrincipal(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia);

#endif
