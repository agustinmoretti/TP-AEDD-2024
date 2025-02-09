#ifndef CARGAR_MEDALLAS_H
#define CARGAR_MEDALLAS_H
#include "menu.h"
#include "submenu_gen_competencia.h"

bool cargar_medallas(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia);

void cargaPorDeporteIndividual(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia);
void cargaPorDeporteColectivo(competidores competencia[], int deporte_medallas[][3], archivoCompetencia &file_competencia);

#endif
