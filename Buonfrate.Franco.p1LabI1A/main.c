#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"
#include "bicicleta.h"
#include "color.h"
#include "servicios.h"
#include "tipos.h"
#include "trabajo.h"
#include "dataWereHouse.h"

#define TAM 5
#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define TAM_TRABAJO 5


int main()
{
    int seguir='s';
    eBicicleta bicicletas[TAM];
    eTrabajo trabajo[TAM_TRABAJO];
    int nextId=1;
    int nextIdTrabajo=1;
    int indiceModificar;
    int flag=0;
    eTipo tipo[TAM_TIPO]={{1000, "Rutera"},
                          {1001, "Carrera"},
                          {1002,"Mountain"},
                          {1003,"BMX"}};

    eColor color[TAM_COLOR]={{5000,"Gris"},
                            {5001,"Negro"},
                            {5002,"Blanco"},
                            {5003,"Azul"},
                            {5004,"Rojo"}};

    eServicio servicio[TAM_SERVICIO]={{20000,"Limpieza",250},
                                      {20001,"Parche",300},
                                      {20002,"Centrado",400},
                                      {20003,"Cadena",350}};


    inicializarBicicletas(bicicletas,TAM);
    inicializarTrabajos(trabajo, TAM_TRABAJO);

    hardcodearBicicletas(bicicletas, TAM, 3, &nextId);
    hardcodearTrabajos(trabajo, TAM_TRABAJO, 3, &nextIdTrabajo);
do
{
    switch(menu())
    {
    case 1:
        altaBici(bicicletas, TAM, &nextId, tipo, TAM_TIPO, color, TAM_COLOR, servicio, TAM_SERVICIO);
        flag=1;
        system("pause");
        break;
    case 2:
        if(flag)
        {
            indiceModificar=validarBici(bicicletas,TAM);
            if(indiceModificar!=-1)
            {
            modificarBici(bicicletas,TAM,tipo, TAM_TIPO, color, TAM_COLOR, indiceModificar);
            }
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
            system("pause");
        }
        break;
    case 3:
        if(flag){
        bajaBici(bicicletas, TAM);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
            system("pause");
        }
        break;
    case 4:
        if(flag){
        mostrarBicis(bicicletas, TAM, tipo, TAM_TIPO, color, TAM_COLOR);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        system("pause");
        break;
    case 5:
        if(flag)
        {
        listarTipos(tipo, TAM_TIPO);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        system("pause");
        break;
    case 6:
        if(flag)
        {
        listarColor(color, TAM_COLOR);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        system("pause");
        break;
    case 7:
        if(flag){
        listarServicios(servicio,TAM_SERVICIO);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        system("pause");
        break;
    case 8:
        if(flag){
        altaTrabajo(trabajo, TAM_TRABAJO, servicio, TAM_SERVICIO, bicicletas, TAM, color, TAM_COLOR, tipo, TAM_TIPO, &nextIdTrabajo);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        system("pause");
        break;
    case 9:
        if(flag){
        listarTrabajos(trabajo, TAM_TRABAJO, bicicletas, TAM, tipo, TAM_TIPO, color, TAM_COLOR, servicio, TAM_SERVICIO);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        system("pause");
        break;
    case 0:
        seguir='n';
        break;
    default:
        printf("Error. Ingrese una opcion valida\n");
        system("pause");
        break;
    }
}while(seguir=='s');
    return 0;
}
