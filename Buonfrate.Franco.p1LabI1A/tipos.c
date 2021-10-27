#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipos.h"

int listarTipos(eTipo list[], int tam)
{
    int validation=0;
    if(list!=NULL && tam>0)
    {
        printf("\n----LISTA DE TIPOS----\n");
        printf("--------------------------\n");
        for(int i=0;i<tam; i++)
        {
            printf("ID: %d -  TIPO: %s \n", list[i].id, list[i].descripcion);
        }

        validation=1;
    }
    return validation;
}

int cargarTipo(eTipo* lista, int tam, int id, char destino[])
{
    int validacion=0;

    if(lista!=NULL && tam>0 && id>999 && id<1004 && destino!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].id==id)
            {
                strcpy(destino, lista[i].descripcion);
                break;
            }
        }
        validacion=1;
    }

    return validacion;
}
