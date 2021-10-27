#include "bicicleta.h"
#include "trabajo.h"
#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED




#endif // DATAWAREHOUSE_H_INCLUDED


/** \brief Carga previa de datos para facilitar el testeo del programa
 * \param lista[] eBicicleta Array a recorrer para ir cargando datos
 * \param tam int El tamanio del array a recorrer
 * \param cant int Cantidad de items que se desea incluir en el hardcodeo
 * \param pId int* Puntero a entero
 * \return (-1) si hubo error, (0) en caso de carga correcta
 */

int hardcodearBicicletas(eBicicleta lista[], int tam, int cant, int* pId);


/** \brief Carga previa de datos para facilitar el testeo del programa
 * \param trabajos[] eTrabajos Array a recorrer para ir cargando datos
 * \param tam int El tamanio del array a recorrer
 * \param cant int Cantidad de items que se desea incluir en el hardcodeo
 * \param pId int* Puntero a entero
 * \return (-1) si hubo error, (0) en caso de carga correcta
 */

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pId);
