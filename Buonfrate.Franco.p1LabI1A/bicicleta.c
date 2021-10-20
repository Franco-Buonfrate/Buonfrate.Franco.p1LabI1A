#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bicicleta.h"


int initBicis(eBici* lista, int tam)
{
    int ret=0;
    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        ret=1;
    }
    return ret;
}
int buscarLibre(eBici* lista, int tam)
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
int altaBici(eBici* lista, int tam, int* nextId,eTipo* listaTipo, int tamTipo, eColor* listaColor, int tamColor)
{
    int ret=0;
    if(lista!=NULL&&tam>0&&nextId!=NULL)
    {
        int actualIndex;
        system("cls");
        actualIndex=buscarLibre(lista,tam);
        printf("\nEl ID de la nueva bici es %d.\n",*nextId);
        lista[actualIndex].idBici=(*nextId);
        (*nextId)++;
        system("pause");
        system("cls");
        ingresarStr("marca",lista[actualIndex].marca,20);

        listarTipos(listaTipo,tamTipo);
        printf("\n");
        ingresarIntPos("tipo",&lista[actualIndex].idTipo,1000,1003);

        listarColores(listaColor,tamColor);
        printf("\n");
        ingresarIntPos("color",&lista[actualIndex].idColor,5000,5004);

        ingresarChar("material", &lista[actualIndex].material, 'c', 'a');



        printf("\nBicicleta cargada con exito.\n");

        mostrarBici(lista[actualIndex],listaTipo,tamTipo,listaColor,tamColor);
        system("pause");
        ret=1;
    }
    return ret;
}

/*
int ingresarRodado(float* campo)
{
    int ret=0;
    float auxFloat;

    if(campo!=NULL)
    {
        printf("Ingrese rodado: \n");
        fflush(stdin);
        scanf("%f",&auxFloat);
        while(auxFloat!=20&&auxFloat!=26&&auxFloat!=27.5&&auxFloat!=29)
        {
            printf("Rodado invalido. Reingresar.\n");
            fflush(stdin);
            scanf("%f",&auxFloat);
        }
        *campo=auxFloat;
        ret=1;
    }
    return ret;
}
*/

void mostrarBici(eBici bici,eTipo* listaT, int tamT, eColor* listaC, int tamC)
{
    char descTipo[20];
    char descColor[20];
    cargarTipo(bici.idTipo,listaT,tamT,descTipo);
    cargarColor(bici.idColor,listaC,tamC,descColor);
    printf("\n----------------------\n");
    printf("[ID]:        %d \nMARCA:       %s \nTIPO:        %s \nCOLOR:       %s \nMATERIAL:      %c \n\n",
           bici.idBici, bici.marca, descTipo,descColor,bici.material);

}

int mostrarBicis(eBici* lista, int tam, eTipo* listaT,int tamT, eColor* listaC, int tamC)
{
    int ret=0;
    if(lista!=NULL&&tam>0)
    {
        ret=1;
        system("cls");
        printf("---------LISTA DE BICICLETAS---------\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                mostrarBici(lista[i],listaT,tamT,listaC,tamC);
                printf("------------------------------------\n");
            }
        }
    }
    return ret;
}

int checkBiciCargada(eBici* lista,int tam)
{
    int check=0;
    if(lista!= NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                check=1;
                return check;
                break;
            }

        }
    }
    return check;
}

int findBiciByID(eBici* lista, int tam)
{
    int posicion=-1;

    if(lista!=NULL&&tam>0)
    {
        int userInput;
        printf("Ingrese ID que desea modificar: ");
        fflush(stdin);
        scanf("%d",&userInput);

        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                continue;
            }
            else if(lista[i].idBici==userInput)
            {
                posicion=i;
                break;
            }
        }
        if(posicion==(-1))
        {
            printf("No se encontro dicho ID.\t");
            system("pause");
        }
    }
    return posicion;
}
int editBici(eBici* list, int tam, int index, eTipo* tipos,int tamT,eColor* colores,int tamC)
{
    int ret=0;
    if(list!=NULL&&tam>0&&index>-1)
    {
        int opcion;
        printf("------------------------------------\n");
        mostrarBici(list[index],tipos,tamT,colores,tamC);
        printf("------------------------------------\n");
        printf("Que desea modificar?\n[1]-Marca\n[2]-Tipo\n[3]-Color\n[4]-Material\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            ingresarStr("marca",list[index].marca,20);
            printf("\nMarca cambiada exitosamente. \n");
            system("pause");
            break;
        case 2:
            listarTipos(tipos,tamT);
            ingresarIntPos("tipo",&list[index].idTipo,1000,1003);
            printf("\nTipo cambiado exitosamente. \n");
            system("pause");
            break;
        case 3:
            listarColores(colores,tamC);
            ingresarIntPos("color",&list[index].idColor,5000,5004);
            printf("\nColor cambiado exitosamente. \n");
            system("pause");
            break;
        case 4:

            ingresarChar("material", &list[index].material, 'c', 'a');
            printf("\nMaterial cambiado exitosamente. \n");
            system("pause");
            /*
        case 4:
            ingresarRodado(&list[index].rodado);
            printf("\nRodado cambiado exitosamente. \n");
            system("pause");
            break;
            */
        }
        ret=1;
    }
    return ret;
}
int removeBici(eBici* list,int tam, int index,eTipo* tipos,int tamT,eColor* colores, int tamC)
{
    int ret=0;
    if(list!=NULL && tam>0 && index>(-1))
    {
        char rta;
        ret=1;
        printf("------------------------------------\n");
        mostrarBici(list[index],tipos,tamT,colores,tamC);
        printf("------------------------------------\n");
        printf("\n Desea eliminar permanentemente esta bici? s/n \n");
        fflush(stdin);
        scanf("%c",&rta);
        if(rta=='s')
        {
            list[index].isEmpty=1;

            printf("Bici eliminada exitosamente.\n");
            system("pause");
        }
        else
        {
            printf("No se eliminara esta bici.\n");
            system("pause");
        }

    }
    return ret;
}
