#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;



#endif // TIPO_H_INCLUDED

int listarTipos(eTipo list[], int tam);
int cargarTipo(eTipo* lista, int tamT, int id, char destino[]);
