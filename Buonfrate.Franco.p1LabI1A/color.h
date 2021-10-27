#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;


#endif // COLOR_H_INCLUDED


/** \brief Muestra un listado de colores
 *
 * \param list[] eColor El array a mostrar
 * \param tam int El tamaño del array que se muestra
 * \return int -1 si hubo error, 0 si no hubo error.
 *
 */

int listarColor (eColor list[], int tam);


/** \brief Busca la coincidencia de un ID ingresado por el usuario y un ID existente y recupera la descripción asociada a ese ID
 *
 * \param list[] eColor El array donde se busca el ID y se recupera la descripción
 * \param tam int El tamaño del array que se recorre
 * \param id int El ID ingresado por el usuario a comparar
 * \param destino[] char Cadena de caracteres donde se almacena la descripción que se busca
 * \return int -1 si hubo error, 0 si no hubo error.
 *
 */

int cargarColor(eColor list[], int tam, int id, char destino[]);
