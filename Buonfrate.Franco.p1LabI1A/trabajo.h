#include "fecha.h"
#include "bicicleta.h"
#include "servicios.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBici;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

int buscarLibreTrabajo(eTrabajo* lista, int tam);
int findBiciByIDTrabajo(eBici* lista, int tam, int id);
int altaTrabajo(eTrabajo trabajo[], int tamTrab, eBici* lista, int tam, int* nextId,eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor, eServicio servicios[], int tamServicios);
void mostrarTrabajo(eTrabajo trabajo, eBici bici[], int tamBici,eTipo* lista, int tam, eColor* listaC, int tamC);


#endif // TRABAJO_H_INCLUDED
