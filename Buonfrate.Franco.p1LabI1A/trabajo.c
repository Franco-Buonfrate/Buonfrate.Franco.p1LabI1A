#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "bicicleta.h"
#include "miBiblioteca.h"
#include "servicios.h"
#include "color.h"
#include "tipos.h"
#include "fecha.h"

int buscarLibreTrabajo(eTrabajo lista[],int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


int altaTrabajo(eTrabajo trabajo[],int tamTrabajo, eServicio servicios[], int tamServicios, eBicicleta bicicletas[], int tamBicis, eColor color[], int tamColor, eTipo tipo[], int tamTipo, int* pId)
{
    int validacion=0;
    int indice;

    indice=buscarLibreTrabajo(trabajo, tamTrabajo);

    if(trabajo!=NULL && tamTrabajo>0 && servicios!=NULL && tamServicios && bicicletas!=NULL && tamBicis>0 && color!=NULL && tamColor>0 && tipo!=NULL && tamTipo)
    {
        if(indice!=-1)
        {
            trabajo[indice].id=(*pId);
            (*pId)++;
            listarServicios(servicios, tamServicios);
            printf("\n");
            ingresarIntPos("id servicio",&trabajo[indice].idServicio, 20000, 20003);

            system("cls");

            mostrarBicis(bicicletas, tamBicis, tipo, tamTipo, color, tamColor);
            printf("\n");
            ingresarIntPos("id bicicleta", &trabajo[indice].idBicicleta, 0, 1000);

            while(buscarPorId(bicicletas, tamBicis, trabajo[indice].idBicicleta)==-1)
            {
                ingresarIntPos("id bicicleta valido", &trabajo[indice].idBicicleta, 0, 1000);
            }

            validarFecha(&trabajo[indice].fecha.dia, &trabajo[indice].fecha.mes, &trabajo[indice].fecha.anio);

            trabajo[indice].isEmpty=0;
        }
        else
        {
            printf("No hay espacio en el sistema\n");
        }
       validacion=1;
    }

    return validacion;
}


void listarTrabajos(eTrabajo trabajos[], int tamTrabajo, eBicicleta bicicletas[], int tamBicis, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicios[], int tamServicios)
{
    printf("\n");
    printf("------------Lista trabajos------------\n");
    printf("\n");

    for(int i=0; i<tamTrabajo; i++)
    {
        int indice;
        if(!trabajos[i].isEmpty)
        {
            printf("ID TRABAJO:%d\n", trabajos[i].id);
            indice=buscarPorId(bicicletas, tamBicis, trabajos[i].idBicicleta);
            mostrarBici( bicicletas[indice], tipo, tamTipo, color, tamTipo);
            mostrarServicios(servicios, tamServicios, trabajos[i].idServicio);
            printf("--------------------------\n");
        }

    }

}

