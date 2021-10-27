#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

int listarClientes(eCliente clientes[], int tamClientes)
{
    int validacion=0;
    if(clientes!=NULL && tamClientes>0)
    {
        for(int i=0; i<tamClientes;i++)
        {
           printf("---------------------------\n");
           printf("ID: %d \nCLIENTE: %s \n", clientes[i].id, clientes[i].nombre);
           printf("---------------------------\n");
        }
        validacion=1;
    }
    return validacion;
}

int mostrarCliente(eCliente clientes[], int tamClientes, int idCliente)
{
    int validacion=0;
    if(clientes!=NULL && tamClientes>0){
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].id==idCliente)
            {
                 printf("CLIENTE: %s \n", clientes[i].nombre);
                 validacion=1;
            }
        }
    }
    return validacion;
}



