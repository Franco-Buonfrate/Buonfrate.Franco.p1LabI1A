#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
} eServicio;


#endif // SERVICIO_H_INCLUDED



/** \brief Muestra un listado de servicios
 *
 * \param list[] eServicio El array a mostrar
 * \param tam int El tamaño del array que se muestra
 * \return (-1) si hubo error, (0) en caso de carga correcta
 *
 */

int listarServicios (eServicio list[], int tam);


/** \brief Muestra un listado de servicios
 *
 * \param list[] eServicio El array a mostrar
 * \param tamServicio int El tamaño del array que se muestra
 * \param idServicio int id del array de servicio a mostrar
 * \return (-1) si hubo error, (0) en caso de carga correcta
 *
 */

void mostrarServicios(eServicio servicios[], int tamServicio, int idServicio);
