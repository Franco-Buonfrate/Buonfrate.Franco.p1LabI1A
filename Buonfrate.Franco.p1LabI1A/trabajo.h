#include "bicicleta.h"
#include "miBiblioteca.h"
#include "servicios.h"
#include "color.h"
#include "tipos.h"
#include "fecha.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

int altaTrabajo(eTrabajo trabajo[],int tamTrabajo, eServicio servicios[], int tamServicios, eBicicleta bicicletas[], int tamBicis, eColor color[], int tamColor, eTipo tipo[], int tamTipo, int* pId);
int inicializarTrabajos(eTrabajo trabajos[], int tam);
int buscarLibreTrabajo(eTrabajo lista[],int tam);
void listarTrabajos(eTrabajo trabajos[], int tamTrabajo, eBicicleta bicicletas[], int tamBicis, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicios[], int tamServicios);
