#include "tipos.h"
#include "color.h"
#include "servicios.h"

#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material[20];
    int isEmpty;
} eBicicleta;


#endif // BICICLETAS_H_INCLUDED


/** \brief Inicializa el campo is.Empty de la estructura eBicicletas en 1
 *
 * \param eBicicleta bicicletas[] lista de estructura eBicicleta
 * \param int tam tamanio de la lista
 * \return (0) en caso de error, (1) en caso de que se haya ejecutado correctamente
 *
 */

int inicializarBicicletas(eBicicleta bicicletas[], int tam);


/** \brief recorre la lista bicicletas buscando un indice en el que el campo isEmpty en 1
 *
 * \param eBicicleta bicicletas[] lista de estructura eBicicleta
 * \param int tam tamanio de la lista
 * \return (-1) en caso de no existir un indice con el campo isEmpty en 1 (indice) en caso de encontrar un indice con el campo isEmpty en 1
 *
 */

int buscarLibre(eBicicleta bicicletas[],int tam);


/** \brief carga un indice vacio de la lista de estructura eBicicleta
 *
 * \param eBicicleta bicicletas[] lista de estructura eBicicleta
 * \param int tam tamanio de la lista bicicleta
 * \param int* nextId
 * \param eTipo tipo[]
 * \param int tam_tipo
 * \param eColor color[]
 * \param int tam_color
 * \param eServicio servicio[]
 * \param int tam_servicio
 * \return
 *
 */

int altaBici(eBicicleta bicicletas[],int tam, int* nextId, eTipo tipo[], int tam_tipo, eColor color[], int tam_color, eServicio servicio[], int tam_servicio);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarBici(eBicicleta bicicleta,eTipo listaT[], int tam, eColor listaC[], int tamC);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int mostrarBicis(eBicicleta bicis[],int tam, eTipo tipo[],int tamTipo, eColor color[],int tamColor);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int buscarPorId(eBicicleta bicis[], int tam, int id);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int validarBici(eBicicleta bicis[], int tam);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void modificarBici(eBicicleta lista[],int tam, eTipo tipo[], int tamTipo, eColor color[], int tamColor, int indice);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int bajaBici(eBicicleta lista[], int tam);
