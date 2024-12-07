#ifndef SUBMENU_GEN_COMPETENCIA_H
#define SUBMENU_GEN_COMPETENCIA_H
#include<ctime>

struct archivoCompetencia {
	competidores competencia[87];
	int deporte_medallas[87][3];
	tm fechaCreacion;
	int legajo;
};

bool cargarCompetencia();
bool submenuCompetencia();

extern archivoCompetencia file_competencia;

#endif
