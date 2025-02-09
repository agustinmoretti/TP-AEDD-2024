#ifndef SUBMENU_GEN_COMPETENCIA_H
#define SUBMENU_GEN_COMPETENCIA_H
#include "menu.h"
#include <cstring>
#include <time.h>
using namespace std;
bool cargarCompetencia(archivoCompetencia &file_competencia);
bool submenuCompetencia(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia);
void asignar_var_archivo(archivoCompetencia &file_competencia, competidores competencia[], int deporte_medallas[][3]);
string crearfecha(archivoCompetencia &file_competencia);
void cargar_archivo(string nombrearchivo, archivoCompetencia &file_competencia);

void cargar_variable(competidores competencia[], int deporte_medallas[][3], archivoCompetencia file_competencia);
#endif
