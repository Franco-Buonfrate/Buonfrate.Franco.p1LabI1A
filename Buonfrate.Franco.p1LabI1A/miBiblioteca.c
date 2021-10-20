#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"

int menu()
{
    int opcion;
    system("cls");
    printf("--------MENU BICICLETERIA--------\n\n");
    printf("1. ALTA BICICLETA\n");
    printf("2. MODIFICAR BICICLETA\n");
    printf("3. BAJA BICICLETA\n");
    printf("4. LISTAR BICICLETAS\n");
    printf("5. LISTAR TIPOS\n");
    printf("6. LISTAR COLORES\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("0. Salir del programa.\n\n");

    ingresarIntPos("opcion",&opcion,0,0);

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

int ingresarChar(char texto[], char* campo,char parametroUno, char parametroDos)
{
    int ret=0;
    char auxChar;
    printf("Ingrese %s (c O a)", texto);
    fflush(stdin);
    scanf("%c", &auxChar);
    if(texto!=NULL)
    {
        while(auxChar!=parametroDos && auxChar!=parametroUno)
        {
            printf("Invalido. Reingrese %s", texto);
            fflush(stdin);
            scanf("%c", &auxChar);
        }
        *campo=auxChar;
        ret=1;
    }
    return ret;
}

