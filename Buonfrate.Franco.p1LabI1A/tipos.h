#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;



#endif // TIPO_H_INCLUDED



/** \brief Muestra un listado de tipos
 * \param list[] eTipo El array a mostrar
 * \param tam int El tamaño del array que se muestra
 * \return int -1 si hubo error, 0 si no hubo error.
 */

int listarTipos(eTipo list[], int tam);


/** \brief Busca la coincidencia de un ID ingresado por el usuario y un ID existente y recupera la descripción asociada a ese ID
 *
 * \param lista[] eTipo El array donde se busca el ID y se recupera la descripción
 * \param tamT int El tamaño del array que se recorre
 * \param id int El ID ingresado por el usuario a comparar
 * \param destino[] char Cadena de caracteres donde se almacena la descripción que se busca
 * \return int -1 si hubo error, 0 si no hubo error.
 *
 */

int cargarTipo(eTipo* lista, int tamT, int id, char destino[]);
