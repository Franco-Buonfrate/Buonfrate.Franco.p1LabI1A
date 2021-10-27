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


int altaBici(eBicicleta bicicletas[],int tam, int* nextId, eTipo tipo[], int tam_tipo, eColor color[], int tam_color, eCliente clientes[], int tamClientes)
{
    int validation=0;
    int indice;
    indice=buscarLibre(bicicletas, tam);
    if(bicicletas!=NULL && tam>0 && indice!=-1 && nextId!=NULL && tipo!=NULL && tam_tipo>0 && color!=NULL && tam_color>0)
    {
        listarClientes(clientes, tamClientes);
        ingresarIntPos("Ingrese id cliente", &bicicletas[indice].idCliente, 1, 5);

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

        mostrarBici(bicicletas[indice],tipo, tam_tipo, color, tam_color, clientes, tamClientes);
        validation=1;
    }
    else
    {
        printf("No se hay lugar disponible en el sistema\n");
    }
    return validation;
}

void mostrarBici(eBicicleta bicicleta,eTipo* listaT, int tamT, eColor* listaC, int tamC, eCliente clientes[], int tamClientes)
{
    char descTipo[20];
    char descColor[20];
    cargarTipo(listaT, tamT, bicicleta.idTipo, descTipo);
    cargarColor(listaC, tamC, bicicleta.idColor, descColor);\
    mostrarCliente(clientes, tamClientes, bicicleta.idCliente);

    printf("ID: %d    \nMARCA: %s    \nTIPO: %s    \nCOLOR: %s   \nMATERIAL: %s\n", bicicleta.id, bicicleta.marca, descTipo, descColor, bicicleta.material);

}

int mostrarBicis(eBicicleta bicis[],int tam, eTipo tipo[],int tamTipo, eColor color[],int tamColor, eCliente clientes[], int tamClientes)
{
    int validacion=0;
    if(bicis!=NULL && tam>0 && tipo!=NULL && tamTipo>0 && color!=NULL && tamColor>0)
    {
        printf("\n----Bicis Ingresadas----\n\n");
        for(int i=0; i<tam; i++)
        {
            if(!bicis[i].isEmpty)
            {
                mostrarBici(bicis[i], tipo, tamTipo, color, tamColor, clientes, tamClientes);
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
    printf("Ingrese Id de la Bicicleta: ");
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

int mostrarBicicletasColor(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente clientes[], int tamCliente)
{
    int validacion=0;
    int idColor;
    int flag=0;

    if(bicicletas!=NULL && tamBicicletas>0 && color!=NULL && tamColor>0)
    {
        listarColor(color, tamColor);
        ingresarIntPos("id color", &idColor, 5000, 5004);
        printf("\n");

        for(int i=0;i<tamBicicletas; i++)
        {
            if(bicicletas[i].idColor==idColor && bicicletas[i].isEmpty==0)
            {
                mostrarBici(bicicletas[i], tipo, tamTipo, color, tamColor, clientes, tamCliente);
                printf("\n");
                flag=1;
            }
        }

        if(!flag)
        {
            printf("No hay bicicletas en ese color\n");
        }
        validacion=1;
    }

    return validacion;
}

int mostrarBicicletaTipo(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente)
{
    int validacion=0;
    int idTipo;
    int flag=0;

    if(bicicletas!=NULL && tamBicicletas>0 && color!=NULL && tamColor>0)
    {
        listarTipos(tipo, tamTipo);
        ingresarIntPos("id tipo", &idTipo, 1000, 1003);
        printf("\n");

        for(int i=0;i<tamBicicletas; i++)
        {
            if(bicicletas[i].idTipo==idTipo && bicicletas[i].isEmpty==0)
            {
                mostrarBici(bicicletas[i], tipo, tamTipo, color, tamColor, cliente, tamCliente);
                printf("\n");
                flag=1;
            }
        }

        validacion=1;

        if(!flag)
        {
            printf("No hay bicicletas de ese tipo\n");
        }
    }


    return validacion;
}

int mostrarBicicletaMaterial (eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int validacion=0;
    int contadorCarbono=0;
    int contadorAluminio=0;

    if(bicicletas!=NULL && tamBicicletas>0 && color!=NULL && tamColor>0)
    {

        printf("\n");

        for(int i=0;i<tamBicicletas; i++)
        {
            if(strcmp(bicicletas[i].material, "Carbono")==0 && bicicletas[i].isEmpty==0)
            {
                contadorCarbono++;
            }
            else if(strcmp(bicicletas[i].material, "Aluminio")==0 && bicicletas[i].isEmpty==0)
            {
                contadorAluminio++;
            }
        }

        if(contadorAluminio>contadorCarbono)
        {
            printf("Hay mas bicicletas de Aluminio, con un total de %d\n", contadorAluminio);
        }
        else if(contadorCarbono>contadorAluminio)
        {
            printf("Hay mas bicicletas de Carbono, con un total de %d\n", contadorCarbono);
        }
        else
        {
            printf("Hay la misma cantidad de carbono y aluminio, con un total de %d\n", contadorAluminio);
        }


        validacion=1;
    }

    return validacion;
}

int mostrarBicicletaPorTipo(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente clientes[], int tamClientes)
{
    int validacion=0;
    if(bicicletas!=NULL && tamBicicletas>0 && color!=NULL && tamColor>0)
    {
        for(int i=0; i<tamTipo; i++)
        {
            printf("--------------------------\n");
            printf("%s\n", tipo[i].descripcion);
            printf("--------------------------\n");
            printf("\n");

            for(int j=0; j<tamBicicletas; j++)
            {
                if(bicicletas[j].idTipo==tipo[i].id && bicicletas[j].isEmpty==0)
                {
                    mostrarBici(bicicletas[j], tipo, tamTipo, color, tamColor, clientes, tamClientes);
                    printf("\n");
                }
            }
        }
        validacion=1;
    }
    return validacion;
}

int listarBicicletasColorTipo(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int validacion=0;
    int idColor;
    int idTipo;
    char descColor[21];
    char descTipo[21];
    int contador=0;

    if(bicicletas!=NULL && tamBicicletas>0 && color!=NULL && tamColor>0)
    {
        listarColor(color, tamColor);
        ingresarIntPos("id color", &idColor, 5000, 5004);
        cargarColor(color, tamColor, idColor, descColor);
        printf("\n");
        listarTipos(tipo, tamTipo);
        ingresarIntPos("id tipo", &idTipo, 1000, 1003);
        cargarTipo(tipo, tamTipo, idTipo, descTipo);

        for(int i=0; i<tamBicicletas; i++)
        {
            if(bicicletas[i].idColor==idColor && bicicletas[i].idTipo==idTipo && bicicletas[i].isEmpty==0)
            {
                contador++;
            }
        }

        printf("Hay %d de color %s y tipo %s\n", contador, descColor, descTipo);


        validacion=1;
    }
    return validacion;
}

int colorMasElegido(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int validacion=0;
    int contador[5]={0};
    int flag=0;
    int indiceMasGrande;


    if(bicicletas!=NULL && tamBicicletas>0 && color!=NULL && tamColor>0 && tipo!=NULL && tamTipo>0)
    {
        for(int i=0; i<tamColor; i++)
        {
            for(int j=0; j<tamBicicletas; j++)
            {
                if(bicicletas[j].idColor==color[i].id && bicicletas[j].isEmpty==0)
                {
                    contador[i]++;
                }
            }
        }

        for(int i=0; i<tamColor; i++)
        {
            if(i==0 || contador[i]>contador[indiceMasGrande])
            {
                indiceMasGrande=i;
            }
        }

        for(int i=0; i<tamColor; i++)
        {
            if(contador[i]==contador[indiceMasGrande])
            {
                if(!flag)
                {
                    printf("El/Los color/es mas elegido/s es/son: %s", color[i].nombreColor);
                    flag=1;
                }
                else
                {
                    printf(" %s", color[i].nombreColor);
                }
            }
        }
        printf("\n");
        validacion=1;
    }

    return validacion;
}


