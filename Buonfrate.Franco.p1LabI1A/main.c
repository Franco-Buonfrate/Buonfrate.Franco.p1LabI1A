#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bicicleta.h"
#include "miBiblioteca.h"
#include "tipos.h"
#include "color.h"
#include "servicios.h"
#include "trabajo.h"
#include "dataWereHouse.h"




#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define TAM_BICI 10
#define TAM_TRABAJO 4

int main()
{
    eTipo tipos[TAM_TIPO] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };
    eColor colores[TAM_COLOR] =
    {
        {5000, "Gris"},
        {5001, "Negro"},
        {5002, "Blanco"},
        {5003, "Azul"},
        {5004, "Rojo"}
    };
    eServicio servicios[TAM_SERVICIO] =
    {
        {20000, "Limpieza",250},
        {20001, "Parche",300},
        {20002, "Centrado",400},
        {20003, "Cadena",350}
    };

    eTrabajo trabajo[TAM_TRABAJO];

    int iterador=1;
    eBici listaBicis[10];
    int nextId=1;
    int nextIdTrabajo=1;

     initBicis(listaBicis,TAM_BICI);
     hardcodearBicicletas(listaBicis,TAM_BICI,10, &nextId);

    do
    {
        switch(menu())
        {
        case 1:
            altaBici(listaBicis,TAM_BICI,&nextId,tipos,TAM_TIPO,colores,TAM_COLOR);
            break;
        case 2:
            if(checkBiciCargada(listaBicis,TAM_BICI))
            {
                editBici(listaBicis,TAM_BICI,findBiciByID(listaBicis,TAM_BICI),tipos,TAM_TIPO,colores,TAM_COLOR);
            }
            else
            {
                printf("Cargue primero una bici.");
                system("pause");
            }
            break;
        case 3:
             if(checkBiciCargada(listaBicis,TAM_BICI))
            {
                removeBici(listaBicis,TAM_BICI,findBiciByID(listaBicis,TAM_BICI),tipos,TAM_TIPO,colores,TAM_COLOR);
            }
            else
            {
                printf("Cargue primero una bici.");
                system("pause");
            }
            break;
        case 4:
            if(checkBiciCargada(listaBicis,TAM_BICI))
            {
                mostrarBicis(listaBicis,TAM_BICI,tipos,TAM_TIPO,colores,TAM_COLOR);
                system("pause");
            }
            else
            {
                printf("Cargue primero una bici.");
                system("pause");
            }
            break;
        case 5:
            listarTipos(tipos,TAM_TIPO);
            system("pause");
            break;
        case 6:
            listarColores(colores,TAM_COLOR);
            system("pause");
            break;
        case 7:
            listarServicios(servicios,TAM_SERVICIO);
            system("pause");
            break;
        case 8:
            altaTrabajo(trabajo, TAM_TRABAJO, listaBicis, TAM_BICI, &nextIdTrabajo, tipos, TAM_TIPO, colores, TAM_COLOR, servicios, TAM_SERVICIO);
            break;
        case 0:
            iterador=0;
            break;
        default:
            printf("Invalido. Ingrese otra opcion.");
            system("pause");
            break;
        }
    }
    while(iterador==1);
    return 0;
}
