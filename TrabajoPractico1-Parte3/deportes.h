#ifndef DEPORTES_H

#define totalDeportes 87
#define deportesIndividuales 53
#define deportesColectivos 34
#define numPaises 196

void imprimirDeporte(int indice);
void mostrarDeportes();
void mostrarDeportesIndividuales();
bool verificaIndividuales(int id);
bool verificaColectivos(int id);
void listarDeportesPorCategoria(const char* categoria, const int* indices, int numIndices);
void mostrarDeportesColectivos();
bool deporteCargado(int id, int deporte_medallas[][3]);

#endif
