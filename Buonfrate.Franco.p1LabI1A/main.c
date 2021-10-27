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
#include "cliente.h"

#define TAM 10
#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define TAM_TRABAJO 10
#define TAM_CLIENTE 5


int main()
{
    char seguir='s';
    char seguirInforme='s';
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

    eCliente clientes[TAM_CLIENTE]= {{1,"Martina",'f'},
                                    {2,"Franco",'m'},
                                    {3,"Valentino",'m'},
                                    {4,"Christian",'f'},
                                    {5,"Felipe",'m'}};
    inicializarBicicletas(bicicletas,TAM);
    inicializarTrabajos(trabajo, TAM_TRABAJO);

    hardcodearBicicletas(bicicletas, TAM, 9, &nextId);
    hardcodearTrabajos(trabajo, TAM_TRABAJO, 9, &nextIdTrabajo);
do
{
    switch(menu())
    {
    case 1:
        altaBici(bicicletas, TAM, &nextId, tipo, TAM_TIPO, color, TAM_COLOR, clientes, TAM_CLIENTE);
        flag=1;
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
        }
        break;
    case 3:
        if(flag){
        bajaBici(bicicletas, TAM);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        break;
    case 4:
        if(flag){
        mostrarBicis(bicicletas, TAM, tipo, TAM_TIPO, color, TAM_COLOR, clientes, TAM_CLIENTE);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
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
        break;
    case 7:
        if(flag){
        listarServicios(servicio,TAM_SERVICIO);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        break;
    case 8:
        if(flag){
        altaTrabajo(trabajo, TAM_TRABAJO, servicio, TAM_SERVICIO, bicicletas, TAM, color, TAM_COLOR, tipo, TAM_TIPO, &nextIdTrabajo, clientes, TAM_CLIENTE);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        break;
    case 9:
        if(flag){
        listarTrabajos(trabajo, TAM_TRABAJO, bicicletas, TAM, tipo, TAM_TIPO, color, TAM_COLOR, servicio, TAM_SERVICIO, clientes, TAM_CLIENTE);
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        break;
    case 10:
        if(flag){
            seguirInforme='s';
            do{
                switch(menuInformes())
                {
                case 1:
                    mostrarBicicletasColor(bicicletas, TAM, color, TAM_COLOR, tipo, TAM_TIPO, clientes, TAM_CLIENTE);
                    break;
                case 2:
                    mostrarBicicletaTipo(bicicletas, TAM, color, TAM_COLOR, tipo, TAM_TIPO, clientes, TAM_CLIENTE);
                    break;
                case 3:
                    mostrarBicicletaMaterial(bicicletas, TAM, color, TAM_COLOR, tipo, TAM_TIPO);
                    break;
                case 4:
                    mostrarBicicletaPorTipo(bicicletas, TAM, color, TAM_COLOR, tipo, TAM_TIPO, clientes, TAM_CLIENTE);
                    break;
                case 5:
                    listarBicicletasColorTipo(bicicletas, TAM, color, TAM_COLOR, tipo, TAM_TIPO);
                    break;
                case 6:
                    colorMasElegido(bicicletas, TAM, color, TAM_COLOR, tipo, TAM_TIPO);
                    break;
                case 7:
                    mostrarServiciosABicicleta(bicicletas, TAM, servicio, TAM_SERVICIO, trabajo, TAM_TRABAJO, tipo, TAM_TIPO, color, TAM_COLOR, clientes, TAM_CLIENTE);
                    break;
                case 8:
                    mostrarSumaDeImportesBicicleta(bicicletas, TAM, servicio, TAM_SERVICIO, trabajo, TAM_TRABAJO, tipo, TAM_TIPO, color, TAM_COLOR, clientes, TAM_CLIENTE);
                    break;
                case 9:
                    mostrarBicicletasIdServicio(bicicletas, TAM, servicio, TAM_SERVICIO, trabajo, TAM_TRABAJO, tipo, TAM_TIPO, color, TAM_COLOR, clientes, TAM_CLIENTE);
                    break;
                case 10:
                    mostrarServiciosFecha(bicicletas, TAM, servicio, TAM_SERVICIO, trabajo, TAM_TRABAJO, tipo, TAM_TIPO, color, TAM_COLOR);
                    break;
                case 0:
                    seguirInforme='n';
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }while(seguirInforme=='s');
        }
        else
        {
            printf("Antes debe dar de alta una bici\n");
        }
        break;
    case 0:
        seguir='n';
        break;
    default:
        printf("Error. Ingrese una opcion valida\n");
        break;
    }
    system("pause");
}while(seguir=='s');
    return 0;
}
