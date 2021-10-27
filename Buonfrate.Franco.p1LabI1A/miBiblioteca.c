#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"

int menu()
{
    int opcion;

    system("cls");
    printf("            *** ABM Bicicletas ***              \n");
    printf("---------------------------------------------\n");
    printf("1- Alta Bicicletas\n");
    printf("2- Modificar Bicicletas\n");
    printf("3- Baja Bicicletas\n");
    printf("4- Listar bicicletas\n");
    printf("5- Listar Tipos\n");
    printf("6- Listar colores\n");
    printf("7- Listar servicios\n");
    printf("8- Alta trabajo\n");
    printf("9- Listar trabajos\n");
    printf("10- menu informes\n");
    printf("0- Salir\n");


    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("            *** Menu informes ***              \n");
    printf("---------------------------------------------\n");
    printf("1- Mostrar Bicicletas por color\n");
    printf("2- Mostrar Bicicletas por tipo\n");
    printf("3- Informe cantidad por material\n");
    printf("4- Informe de Bicicletas ordenadas por marca\n");
    printf("5- Contar bicicletas por color y tipo\n");
    printf("6- Mostrar color mas elegido\n");
    printf("7- Mostrar trabajos a una bicicleta\n");
    printf("8- Suma de importes Bicicleta\n");
    printf("9- Mostrar bicicletas con un Trabajo\n");
    printf("10- Trabajos por fecha\n");
    printf("0- Salir\n");


    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int ingresarIntPos(char texto[],int* campo,int minimo,int limite)
{
    int ret=0;
    int auxInt;
    if(limite==0)
    {
        limite=2147483647;
    }
    if(texto!=NULL&&campo!=NULL&&limite >(-1))
    {
        printf("Ingrese %s: \n",texto);
        fflush(stdin);
        scanf("%d",&auxInt);
        while(auxInt<minimo||auxInt>limite)
        {
            printf("Invalido. Reingresar %s.\n",texto);
            fflush(stdin);
            scanf("%d",&auxInt);
        }
        *campo=auxInt;
        ret=1;
    }
    return ret;
}

int ingresarStr(char texto[],char* campo,int tam)
{
    int ret=0;
    char auxStr[100];
    if(texto!=NULL&&campo!= NULL&&tam>0)
    {
        printf("Ingrese %s:\n",texto);
        fflush(stdin);
        gets(auxStr);
        while(strlen(auxStr)==0 || strlen(auxStr)>tam)
        {
            printf("Invalido. Reingresar %s:\n",texto);
            fflush(stdin);
            gets(auxStr);
        }
        strcpy(campo, auxStr);
        ret=1;
    }
    return ret;
}

int ingresarFloatPos(char texto[],float* campo,int minimo,int limite)
{
    int ret=0;
    float auxFloat;
    if(limite==0)
    {
        limite=2147483647;
    }
    if(texto!=NULL&&campo!=NULL&&limite >(-1) )
    {
        printf("Ingrese %s: \n",texto);
        fflush(stdin);
        scanf("%f",&auxFloat);
        while(auxFloat<minimo||auxFloat>limite)
        {
            printf("Invalido. Reingresar %s.\n",texto);
            fflush(stdin);
            scanf("%f",&auxFloat);
        }
        *campo=auxFloat;
        ret=1;
    }
    return ret;
}

int ingresarChar(char texto[], char* campo, char parametroUno, char parametroDos)
{
    int ret=0;
    char auxChar;
    printf("Ingrese %s : ", texto);
    fflush(stdin);
    scanf("%c", &auxChar);
    auxChar=tolower(auxChar);
    if(texto!=NULL)
    {
        while(auxChar!=parametroDos && auxChar!=parametroUno)
        {
            printf("Invalido. Reingrese %s : ", texto);
            fflush(stdin);
            scanf("%c", &auxChar);
        }

        if(auxChar=='c')
        {
            strcpy(campo,"Carbono");
        }
        else if(auxChar=='a')
        {
            strcpy(campo,"Aluminio");
        }
        ret=1;
    }
    return ret;
}

