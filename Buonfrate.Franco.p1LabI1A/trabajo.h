#include "bicicleta.h"
#include "miBiblioteca.h"
#include "servicios.h"
#include "color.h"
#include "tipos.h"
#include "fecha.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED


/** \brief Da de alta una estructura en el primer índice disponible
 * \param trabajos[] eTrabajo El array de estructuras a mostrar
 * \param tamTrabajo int El tamaño del array a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBicis int El tamaño del array de estructuras anidadas
 * \param tipo[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param color[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServicios int El tamaño del array de estructuras anidadas
 * \param pId int* Puntero a entero del ID a almacenar en el índice donde se da de alta la estructura
 * \return int -1 si hubo error, 0 si no hubo error
 */

int altaTrabajo(eTrabajo trabajo[],int tamTrabajo, eServicio servicios[], int tamServicios, eBicicleta bicicletas[], int tamBicis, eColor color[], int tamColor, eTipo tipo[], int tamTipo, int* pId, eCliente clientes[], int tamCliente);


/** \brief Inicializa todos los campos isEmpty en 1 para que estén disponibles para almacenar información en cada índice
 * \param trabajos[] eTrabajo El array que se recorre para inicializarse como disponible
 * \param tam int El tamaño del array
 * \return int -1 si hubo error, 0 si no hubo error
 */

int inicializarTrabajos(eTrabajo trabajos[], int tam);


/** \brief Busca el primer índice disponible en el array (isEmpty==1) para cargar los datos de una nueva estructura
 * \param lista[] eTrabajo El array que se recorre para buscar el índice disponible
 * \param tam int El tamaño del array
 * \return int El número del primer índice que se encuentra disponible para cargar una nueva estructura, -1 si no hay más lugar disponible
 */

int buscarLibreTrabajo(eTrabajo lista[],int tam);


/** \brief muestra el trabajo almacenado en un indice
 *
  * \param trabajos eTrabajo La estructura específica a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBicis int El tamaño del array de estructuras anidadas
 * \param tipo[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param color[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServicios int El tamaño del array de estructuras anidadas
 * \return (0) en caso de error, (1) en caso de que este todo ok
 *
 */

int mostrarTrabajo(eTrabajo trabajo, eBicicleta bicicletas[], int tamBicis, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicios[], int tamServicios, eCliente clientes[], int tamClientes);


/** \brief Muestra los datos de una estructura individual
 * \param trabajos eTrabajo La estructura específica a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBicis int El tamaño del array de estructuras anidadas
 * \param tipo[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param color[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServicios int El tamaño del array de estructuras anidadas
 * \return void No retorna ningún valor
 */

void listarTrabajos(eTrabajo trabajos[], int tamTrabajo, eBicicleta bicicletas[], int tamBicis, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicios[], int tamServicios, eCliente clientes[], int tamCliente);


/** \brief muestra los servicios a una bicicleta
 *
 * \param trabajos eTrabajo La estructura específica a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBicis int El tamaño del array de estructuras anidadas
 * \param tipo[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param color[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServicios int El tamaño del array de estructuras anidadas
 * \return (0) en caso de error, (1) en caso de que este todo ok
 *
 */

int mostrarServiciosABicicleta(eBicicleta bicicletas[], int tamBicicleta, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajo, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eCliente clientes[], int tamCliente);


/** \brief muestra la suma de los importes corresppondioente a una bicicleta
 *
  * \param trabajos eTrabajo La estructura específica a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBicis int El tamaño del array de estructuras anidadas
 * \param tipo[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param color[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServicios int El tamaño del array de estructuras anidadas
 * \return (0) en caso de error, (1) en caso de que este todo ok
 *
 */

int mostrarSumaDeImportesBicicleta(eBicicleta bicicletas[], int tamBicicleta, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajo, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eCliente clientes[], int tamCliente);


/** \brief muesttra los servicios mediante el id de la bicicleta
 *
  * \param trabajos eTrabajo La estructura específica a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBicis int El tamaño del array de estructuras anidadas
 * \param tipo[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param color[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServicios int El tamaño del array de estructuras anidadas
 * \return (0) en caso de error, (1) en caso de que este todo ok
 *
 */

int mostrarBicicletasIdServicio(eBicicleta bicicletas[], int tamBicicleta, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajo, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eCliente clientes[], int tamCliente);


/** \brief muestra los servicios en determinada fecha
 *
  * \param trabajos eTrabajo La estructura específica a mostrar
 * \param bicicletas[] eBicicletas El array de estructuras anidadas
 * \param tamBicis int El tamaño del array de estructuras anidadas
 * \param tipo[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param color[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \param servicios[] eColor El array de estructuras anidadas
 * \param tamServicios int El tamaño del array de estructuras anidadas
 * \return (0) en caso de error, (1) en caso de que este todo ok
 *
 */

int mostrarServiciosFecha(eBicicleta bicicletas[], int tamBicicleta, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajo, eTipo tipo[], int tamTipo, eColor color[], int tamColor);
