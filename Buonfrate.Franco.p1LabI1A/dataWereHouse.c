#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dataWereHouse.h"


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
char material[10] = {'a', 'c', 'c', 'a', 'c', 'a', 'c', 'a', 'a', 'a'};

int hardcodearBicicletas(eBici lista[], int tam, int cant, int* pId)
{
	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0; i < cant; i++)
		{
			lista[i].idBici = *pId;
			(*pId)++;
			strcpy(lista[i].marca, marca[i]);
			lista[i].material = material[i];
			lista[i].idTipo = idTipo[i];
			lista[i].idColor = idColor[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
