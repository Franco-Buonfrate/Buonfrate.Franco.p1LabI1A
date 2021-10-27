#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"

int listarColor (eColor list[], int tam)
{
    int validacion=0;

    if(list!=NULL && tam>0)
    {
        printf("\n----LISTA COLORES----\n");
        printf("--------------------------\n");
        for(int i=0; i<tam; i++)
        {
            printf("ID: %d-  COLOR: %s\n", list[i].id, list[i].nombreColor);
        }
        validacion=1;
    }
    return validacion;
}

int cargarColor(eColor list[], int tam, int id, char destino[])
{
    int validacion=0;

    if(list!=NULL && tam>0 && destino!=NULL && id>=5000 && id<=5004)
    {
        for(int i=0;i<tam; i++)
        {
            if(list[i].id==id)
            {
                strcpy(destino, list[i].nombreColor);
                break;
            }
        }
        validacion=1;
    }
    return validacion;
}
