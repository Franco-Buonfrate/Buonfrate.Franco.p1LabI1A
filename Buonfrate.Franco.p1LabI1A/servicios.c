#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicios.h"

int listarServicios (eServicio list[], int tam)
{
    int validacion=0;
    if(list!=NULL && tam>0)
    {
        printf("\n----LISTA SERVICIOS----\n");
        printf("--------------------------\n");
        for(int i=0; i<tam; i++)
        {
            printf("ID: %d   \nSERVICIO: %s  \nPRECIO: %d \n", list[i].id, list[i].descripcion, list[i].precio);
            printf("--------------------------\n");
        }
        validacion=1;
    }
    return validacion;
}

void mostrarServicios(eServicio servicios[], int tamServicio, int idServicio)
{
    for(int i=0;i<tamServicio;i++)
    {
        if(servicios[i].id==idServicio)
        {
            printf("SERVICIO: %s \nPRECIO: %d\n", servicios[i].descripcion, servicios[i].precio);
        }
    }
}
