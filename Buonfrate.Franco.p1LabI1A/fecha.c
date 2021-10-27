#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"

void validarFecha (int* dia, int* mes, int* anio)
{
    int ret;
    printf("Ingrese fecha (dd/mm/aaaa): ");
    ret= scanf("%2d/%2d/%4d", dia, mes, anio);

    while(ret != 3 ||
          ((*dia<1 || *dia>31)||
          (*mes <1 || *mes>12)||
          (*anio<2005 || *anio>2021))) // la bicicleteria se fundo en 2005
    {
        printf("Error. Ingrese una fecha valida: ");
        fflush(stdin);
        ret = scanf("%2d/%2d/%4d", dia, mes, anio);
    }
}
