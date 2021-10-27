#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
} eServicio;


#endif // SERVICIO_H_INCLUDED

int listarServicios (eServicio list[], int tam);
void mostrarServicios(eServicio servicios[], int tamServicio, int idServicio);
