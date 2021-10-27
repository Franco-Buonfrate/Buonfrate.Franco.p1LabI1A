#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dataWereHouse.h"
#include "trabajo.h"
#include "bicicleta.h"


char marca[10][20] = {
		"Juan",
		"Pedro",
		"Sofia",
		"Miguel",
		"Valentina",
		"Camila",
		"Andrea",
		"Luis",
		"Diego",
		"Analia"
};

int idTipo[10] = {1000, 1000, 1003, 1001, 1002, 1001, 1000, 1003, 1003, 1000};
int idColor[10] = {5001, 5002, 5000, 5001, 5001, 5003, 5004, 5002, 5004, 5001};
char material[10][20] = {"Aluminio", "Carbono", "Carbono", "Aluminio", "Carbono", "Aluminio", "Carbono", "Aluminio", "Aluminio", "Aluminio"};

int hardcodearBicicletas(eBicicleta lista[], int tam, int cant, int* pId)
{
	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0; i < cant; i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].marca, marca[i]);
			strcpy(lista[i].material, material[i]);
			lista[i].idTipo = idTipo[i];
			lista[i].idColor = idColor[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}





int idBicicletas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int idServicios[10] = {20002, 20000, 20002, 20001, 20003, 20000, 20001, 20003, 20003, 20002};

int idPrecios[10] = {400, 250, 400, 300, 350, 250, 300, 350, 350, 400};

int fechaDia[10] = {25, 14, 4, 7, 30, 18, 27, 3, 17, 4};
int fechaMes[10] = {3, 6, 4, 6, 12, 9, 1, 5, 10, 11};
int fechaAnio[10] = {2021, 2020, 2018, 2019, 2021, 2017, 2020, 2018, 2016, 2019};

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pId)
{
	int cont = -1;

	if(trabajos != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		cont = 0;
		for(int i = 0 ; i < cant; i++)
		{
			trabajos[i].id = *pId;
			(*pId)++;
			trabajos[i].idBicicleta = idBicicletas[i];
			trabajos[i].idServicio = idServicios[i];
			trabajos[i].fecha.dia = fechaDia[i];
			trabajos[i].fecha.mes = fechaMes[i];
			trabajos[i].fecha.anio = fechaAnio[i];
			trabajos[i].isEmpty = 0;
			cont++;
		}
	}
	return cont;
}

