#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "miBiblioteca.h"



int inicializarBicicletas(eBicicleta bicicletas[], int tam)
{
    int todoOk = 0;
    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            bicicletas[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eBicicleta bicicletas[],int tam)
{
    int indice = -1;
    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(bicicletas[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


int altaBici(eBicicleta bicicletas[],int tam, int* nextId, eTipo tipo[], int tam_tipo, eColor color[], int tam_color, eServicio servicio[], int tam_servicio)
{
    int validation=0;
    int indice;
    indice=buscarLibre(bicicletas, tam);
    if(bicicletas!=NULL && tam>0 && indice!=-1 && nextId!=NULL && tipo!=NULL && tam_tipo>0 && color!=NULL && tam_color>0 && servicio!= NULL && tam_servicio>0)
    {
        bicicletas[indice].id=*nextId;
        (*nextId)++;
        ingresarStr("marca", bicicletas[indice].marca, 20);

        system("cls");

        listarTipos(tipo, tam_tipo);
        printf("\n");
        ingresarIntPos("tipo", &bicicletas[indice].idTipo, 1000, 1003);

        system("cls");

        listarColor(color, tam_color);
        printf("\n");
        ingresarIntPos("color", &bicicletas[indice].idColor, 5000, 5004);

        system("cls");

        ingresarChar("material (a O c)", bicicletas[indice].material,'c', 'a');

        system("cls");

        bicicletas[indice].isEmpty=0;

        printf("\nSe ha ingresado su bicicleta con exito\n");

        mostrarBici(bicicletas[indice],tipo, tam_tipo, color, tam_color);
        validation=1;
    }
    else
    {
        printf("No se hay lugar disponible en el sistema\n");
    }
    return validation;
}

void mostrarBici(eBicicleta bicicleta,eTipo* listaT, int tamT, eColor* listaC, int tamC)
{
    char descTipo[20];
    char descColor[20];
    cargarTipo(listaT, tamT, bicicleta.idTipo, descTipo);
    cargarColor(listaC, tamC, bicicleta.idColor, descColor);

    printf("ID: %d    \nMARCA: %s    \nTIPO: %s    \nCOLOR: %s   \nMATERIAL: %s\n", bicicleta.id, bicicleta.marca, descTipo, descColor, bicicleta.material);

}

int mostrarBicis(eBicicleta bicis[],int tam, eTipo tipo[],int tamTipo, eColor color[],int tamColor)
{
    int validacion=0;
    if(bicis!=NULL && tam>0 && tipo!=NULL && tamTipo>0 && color!=NULL && tamColor>0)
    {
        printf("\n----Bicis Ingresadas----\n\n");
        for(int i=0; i<tam; i++)
        {
            if(!bicis[i].isEmpty)
            {
                mostrarBici(bicis[i], tipo, tamTipo, color, tamColor);
                printf("\n");
            }
        }
        validacion=1;
    }
    return validacion;
}

int buscarPorId(eBicicleta bicis[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(bicis[i].id==id)
        {
            indice=i;
            break;
        }
    }


    return indice;
}

int validarBici(eBicicleta bicis[], int tam)
{
    int indice=-1;
    int idBici;
    printf("Ingrese Id a modificar: ");
    scanf("%d", &idBici);

    for(int i=0;i<tam; i++)
    {
        if(bicis[i].id==idBici)
        {
            indice=i;
            break;
        }
    }

    if(indice==-1)
    {
        printf("Id invalido\n");
    }

    return indice;
}

void modificarBici(eBicicleta lista[],int tam, eTipo tipo[], int tamTipo, eColor color[], int tamColor, int indice)
{
    int opcion;
    char seguir='s';

    printf("----MENU MODIFICAR----\n");
    printf("1- Tipo\n");
    printf("2- Material\n");
    printf("0- Cancelar\n");
    printf("----------------------\n");

    ingresarIntPos("opcion",&opcion,0,2);

    do{
        switch(opcion)
        {
        case 1:
            listarTipos(tipo,tamTipo);
            ingresarIntPos("tipo", &lista[indice].idTipo,1000, 1003);
            seguir='n';
            break;
        case 2:
            ingresarChar("material (a O c)", lista[indice].material,'a','c');
            seguir='n';
            break;
        case 0:
            seguir='n';
            break;
        }
    }while(seguir=='s');
}

int bajaBici(eBicicleta lista[], int tam)
{
    int validacion=0;
    int id;
    int indice;

    if(lista!=NULL && tam>0)
    {
        ingresarIntPos("id de bici", &id, 0, 1000);

        indice=buscarPorId(lista, tam, id);
        if(indice==-1)
        {
            printf("Id no encontrado\n");
        }
        else
        {
            lista[indice].isEmpty=1;
        }

        validacion=1;
    }
    return validacion;
}
