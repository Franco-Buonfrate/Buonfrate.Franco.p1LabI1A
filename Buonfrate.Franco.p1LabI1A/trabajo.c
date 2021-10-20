#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "bicicleta.h"
#include "servicios.h"

int buscarLibreTrabajo(eTrabajo* lista, int tam)
{
    int libre=-1;
    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                libre=i;
                break;
            }
        }
    }
    return libre;
}

int findBiciByIDTrabajo(eBici* lista, int tam, int id)
{
    int posicion=-1;

    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                continue;
            }
            else if(lista[i].idBici==id)
            {
                posicion=i;
                break;
            }
        }
    }
    return posicion;
}



int altaTrabajo(eTrabajo trabajo[], int tamTrab, eBici* lista, int tam, int* nextId,eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor, eServicio servicios[], int tamServicios)
{
    int ret=0;
    if(trabajo!=NULL&&tamTrab>0&&nextId!=NULL)
    {
        int actualIndex;
        int idBici;
        system("cls");
        actualIndex=buscarLibreTrabajo(trabajo,tamTrab);
        printf("\nEl ID del trabajo es %d.\n",*nextId);
        trabajo[actualIndex].id=(*nextId);
        (*nextId)++;
        system("pause");
        system("cls");

        mostrarBicis(lista,tam,listaTipo,tamTipo,listaColor,tamColor);

        do
        {
          idBici=findBiciByID(lista, tam);
        }while(idBici==(-1));
        trabajo[actualIndex].idBici=idBici+1;

        listarServicios(servicios,tamServicios);


        printf("Ingrese id servicio: ");
        ingresarIntPos("id servicio", &trabajo[actualIndex].idServicio, 20000, 20003);

        ingresarIntPos("dia", &trabajo[actualIndex].fecha.dia,1,31);
        ingresarIntPos("mes", &trabajo[actualIndex].fecha.mes,1,12);
        ingresarIntPos("anio", &trabajo[actualIndex].fecha.anio,2000, 2021);

        mostrarTrabajo(trabajo[actualIndex], lista, tam,listaTipo, tamTipo, listaColor, tamColor);

        printf("\nTrabajo cargado con exito.\n");

        system("pause");
        ret=1;
    }
    return ret;
}

void mostrarTrabajo(eTrabajo trabajo, eBici bici[], int tamBici, eTipo* tipo, int tam, eColor* listaC, int tamC)
{
    printf("\n----------------------\n");
    printf("[ID TRABAJO]:     %d \n[ID BICI]:        %d \n[ID SERVICIO]: %d \n[FECHA]:      %d/%d/%d \n\n",
           trabajo.id, trabajo.idBici,trabajo.idServicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
    mostrarBici(bici[findBiciByIDTrabajo(bici, tamBici, trabajo.idBici)], tipo, tam, listaC, tamC);
}




