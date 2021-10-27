#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "bicicleta.h"
#include "miBiblioteca.h"
#include "servicios.h"
#include "color.h"
#include "tipos.h"
#include "fecha.h"

int buscarLibreTrabajo(eTrabajo lista[],int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;
    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


int altaTrabajo(eTrabajo trabajo[],int tamTrabajo, eServicio servicios[], int tamServicios, eBicicleta bicicletas[], int tamBicis, eColor color[], int tamColor, eTipo tipo[], int tamTipo, int* pId, eCliente clientes[], int tamCliente)
{
    int validacion=0;
    int indice;

    indice=buscarLibreTrabajo(trabajo, tamTrabajo);

    if(trabajo!=NULL && tamTrabajo>0 && servicios!=NULL && tamServicios && bicicletas!=NULL && tamBicis>0 && color!=NULL && tamColor>0 && tipo!=NULL && tamTipo)
    {
        if(indice!=-1)
        {
            trabajo[indice].id=(*pId);
            (*pId)++;
            listarServicios(servicios, tamServicios);
            printf("\n");
            ingresarIntPos("id servicio",&trabajo[indice].idServicio, 20000, 20003);

            system("cls");

            mostrarBicis(bicicletas, tamBicis, tipo, tamTipo, color, tamColor, clientes, tamCliente);
            printf("\n");
            ingresarIntPos("id bicicleta", &trabajo[indice].idBicicleta, 0, 1000);

            while(buscarPorId(bicicletas, tamBicis, trabajo[indice].idBicicleta)==-1)
            {
                ingresarIntPos("id bicicleta valido", &trabajo[indice].idBicicleta, 0, 1000);
            }

            validarFecha(&trabajo[indice].fecha.dia, &trabajo[indice].fecha.mes, &trabajo[indice].fecha.anio);

            trabajo[indice].isEmpty=0;
        }
        else
        {
            printf("No hay espacio en el sistema\n");
        }
       validacion=1;
    }

    return validacion;
}

int mostrarTrabajo(eTrabajo trabajo, eBicicleta bicicletas[], int tamBicis, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicios[], int tamServicios, eCliente clientes[], int tamClientes)
{
    int validacion=0;
    int indice;
    if(bicicletas!=NULL && tamBicis>0 && tipo!=NULL && tamTipo>0 && color!=NULL && tamColor>0 && servicios!=NULL && tamServicios>0){
            printf("ID TRABAJO:%d\n", trabajo.id);
            indice=buscarPorId(bicicletas, tamBicis, trabajo.idBicicleta);
            mostrarBici( bicicletas[indice], tipo, tamTipo, color, tamTipo, clientes, tamClientes);
            mostrarServicios(servicios, tamServicios, trabajo.idServicio);
            validacion=1;
    }
    return validacion;
}


void listarTrabajos(eTrabajo trabajos[], int tamTrabajo, eBicicleta bicicletas[], int tamBicis, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicios[], int tamServicios, eCliente clientes[], int tamCliente)
{
    printf("\n");
    printf("------------Lista trabajos------------\n");
    printf("\n");

    for(int i=0; i<tamTrabajo; i++)
    {
        int indice;
        if(!trabajos[i].isEmpty)
        {
            printf("ID TRABAJO:%d\n", trabajos[i].id);
            indice=buscarPorId(bicicletas, tamBicis, trabajos[i].idBicicleta);
            mostrarBici( bicicletas[indice], tipo, tamTipo, color, tamTipo, clientes, tamCliente);
            mostrarServicios(servicios, tamServicios, trabajos[i].idServicio);
            printf("--------------------------\n");
        }

    }

}

int mostrarServiciosABicicleta(eBicicleta bicicletas[], int tamBicicleta, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajo, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eCliente clientes[], int tamCliente)
{
    int validacion=0;
    int indiceBicicleta;

    if(bicicletas!=NULL && tamBicicleta>0 && servicios!=NULL && tamServicio>0 && trabajos!=NULL && tamTrabajo>0 && tipo!=NULL && tamTipo>0 && color!=NULL && tamColor>0)
    {
        mostrarBicis(bicicletas, tamBicicleta, tipo, tamTipo, color, tamColor, clientes, tamCliente);
        indiceBicicleta=validarBici(bicicletas, tamBicicleta);

        if(indiceBicicleta>-1)
        {
            for(int i=0; i<tamTrabajo; i++)
            {
                if(trabajos[i].idBicicleta==bicicletas[indiceBicicleta].id && bicicletas[indiceBicicleta].isEmpty==0 && trabajos[i].isEmpty==0)
                {
                    printf("-------------------------------\n");
                    mostrarTrabajo(trabajos[i],bicicletas, tamBicicleta, tipo, tamTipo, color, tamColor, servicios, tamServicio, clientes, tamCliente);
                    printf("-------------------------------\n");
                }
            }
        }
        validacion=1;
    }
    return validacion;
}

int mostrarSumaDeImportesBicicleta(eBicicleta bicicletas[], int tamBicicleta, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajo, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eCliente clientes[], int tamCliente)
{
    int validacion=0;
    int indiceBicicleta;
    int acumImportes=0;

    if(bicicletas!=NULL && tamBicicleta>0 && servicios!=NULL && tamServicio>0 && trabajos!=NULL && tamTrabajo>0 && tipo!=NULL && tamTipo>0 && color!=NULL && tamColor>0)
    {
        mostrarBicis(bicicletas, tamBicicleta, tipo, tamTipo, color, tamColor, clientes, tamCliente);
        indiceBicicleta=validarBici(bicicletas, tamBicicleta);

        if(indiceBicicleta>-1)
        {
            for(int i=0; i<tamTrabajo; i++)
            {
                if(trabajos[i].idBicicleta==bicicletas[indiceBicicleta].id && bicicletas[indiceBicicleta].isEmpty==0 && trabajos[i].isEmpty==0)
                {
                    for(int j=0; j<tamServicio; j++)
                    {
                        if(trabajos[i].idServicio==servicios[j].id)
                        {
                            acumImportes+=servicios[j].precio;
                        }
                    }
                }
            }

            if(acumImportes==0)
            {
                printf("No hay importes para esa bicicleta\n");
            }
            else
            {
               printf("La suma de los importes a pagar es %d\n", acumImportes);
            }

        }
        validacion=1;
    }
    return validacion;
}

int mostrarBicicletasIdServicio(eBicicleta bicicletas[], int tamBicicleta, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajo, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eCliente clientes[], int tamCliente)
{
    int validacion=0;
    int idServicios;
    int flag=0;

    if(bicicletas!=NULL && tamBicicleta>0 && servicios!=NULL && tamServicio>0 && trabajos!=NULL && tamTrabajo>0 && tipo!=NULL && tamTipo>0 && color!=NULL && tamColor>0)
    {
        listarServicios(servicios, tamServicio);
        ingresarIntPos("id servicio", &idServicios, 20000,20003);

        for(int i=0; i<tamTrabajo; i++)
        {
            for(int j=0; j<tamBicicleta;j++)
            {
                if(servicios[j].id==trabajos[i].idServicio && trabajos[i].isEmpty==0)
                {
                    for(int k=0; k<tamBicicleta; k++)
                    {
                        if(bicicletas[k].id==trabajos[i].idBicicleta && bicicletas[k].isEmpty==0)
                        {

                            printf("\nFECHA: %d/%d/%d\n", trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                            mostrarBici(bicicletas[k], tipo, tamTipo, color, tamColor, clientes, tamCliente);
                            printf("\n");
                            flag=1;
                        }
                    }
                }
            }
        }

        if(!flag)
        {
            printf("No hay bicicletas con ese servicio\n");
        }

        validacion=1;
    }

    return validacion;
}

int mostrarServiciosFecha(eBicicleta bicicletas[], int tamBicicleta, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajo, eTipo tipo[], int tamTipo, eColor color[], int tamColor)
{
    int validacion=0;
    eFecha auxFecha;
    int flag=0;

    if(bicicletas!=NULL && tamBicicleta>0 && servicios!=NULL && tamServicio>0 && trabajos!=NULL && tamTrabajo>0 && tipo!=NULL && tamTipo>0 && color!=NULL && tamColor>0)
    {
        validarFecha(&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
        for(int i=0; i<tamTrabajo; i++)
        {
            if(trabajos[i].isEmpty==0 && trabajos[i].fecha.dia==auxFecha.dia && trabajos[i].fecha.mes==auxFecha.mes && trabajos[i].fecha.anio==auxFecha.anio)
            {
                for(int j=0; j<tamServicio; j++)
                {
                    if(trabajos[i].idServicio==servicios[j].id)
                    {
                        mostrarServicios(servicios, tamServicio, servicios[j].id);
                        flag=1;
                    }
                }
            }
        }

        if(!flag)
        {
            printf("No hay servicios en esa fecha\n");
        }

        validacion=1;
    }
    return validacion;
}





