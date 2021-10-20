#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include"miBiblioteca.h"
#include "tipos.h"
#include "color.h"

typedef struct
    {
     int idBici;
     char marca[20];
     int idTipo;
     int idColor;
     char material;
     int isEmpty;
    }eBici;

int initBicis(eBici* lista, int tam);
int buscarLibre(eBici* lista, int tam);
int altaBici(eBici* lista, int tam, int* nextId,eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor);
int ingresarRodado(float* campo);
void mostrarBici(eBici bici,eTipo* lista, int tam, eColor* listaC, int tamC);
int mostrarBicis(eBici* lista, int tam, eTipo* listaT,int tamT, eColor* listaC, int tamC);
int checkBiciCargada(eBici* lista,int tam);
int findBiciByID(eBici* lista, int tam);
int editBici(eBici* list, int tam, int index, eTipo* tipos,int tamT,eColor* colores,int tamC);
int removeBici(eBici* list,int tam, int index,eTipo* tipos,int tamT,eColor* colores, int tamC);

#endif // BICICLETA_H_INCLUDED
