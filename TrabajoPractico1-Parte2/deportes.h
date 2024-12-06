#ifndef DEPORTES_H

#define totalDeportes 87
#define deportesIndividuales 53
#define deportesColectivos 34
#define numPaises 196

//ESTRUCTURA COMPETIDORES

struct competidores{
	int paises[16] = {0}; //INICIALIZO EN 0
	int tl = 0;  
};

void imprimirDeporte(int indice);
void mostrarDeportes();
void mostrarDeportesIndividuales();
void listarDeportesPorCategoria(const char* categoria, const int* indices, int numIndices);
void mostrarDeportesColectivos();

//VARIABLES GLOBALES

extern competidores competencia[totalDeportes] ; 
extern int indicesIndividuales[deportesIndividuales];
extern int indicesColectivos[deportesColectivos];
extern int deporte_medallas[totalDeportes][3] ;
extern int cantdatos ;

#endif
