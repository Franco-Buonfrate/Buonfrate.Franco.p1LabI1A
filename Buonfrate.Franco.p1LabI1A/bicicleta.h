#include "tipos.h"
#include "color.h"
#include "servicios.h"
#include "cliente.h"

#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
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
 * \param int* nextId puntero a id
 * \param eTipo tipo[] eTipo El array de estructuras anidadas
 * \param int tam_tipo int El tamaño del array de estructuras anidadas
 * \param eColor color[] eColor El array de estructuras anidadas
 * \param int tam_color int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

int altaBici(eBicicleta bicicletas[],int tam, int* nextId, eTipo tipo[], int tam_tipo, eColor color[], int tam_color, eCliente clientes[], int tamClientes);


/** \brief Muestra los datos de una estructura individual
 *
 * \param bicicleta eBicicleta La estructura específica a mostrar
 * \param listaT[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param listaC[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return void No retorna ningún valor
 *
 */

void mostrarBici(eBicicleta bicicleta,eTipo* listaT, int tamT, eColor* listaC, int tamC, eCliente clientes[], int tamClientes);


/** \brief Muestra una lista de los datos de múltiples estructuras
 *
 * \param bicicletas[] eBicicleta El array de estructuras a mostrar
 * \param tam int El tamaño de del array a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

int mostrarBicis(eBicicleta bicis[],int tam, eTipo tipo[],int tamTipo, eColor color[],int tamColor, eCliente clientes[], int tamClientes);


/** \brief Recorre un array de estructuras para chequear que el ID ingresado por el usuario exista
 *
 * \param bicis[] eBicicleta El array de estructuras a recorrer para validar que exista el ID
 * \param tam int El tamaño del array de estructuras
  * \param id int El ID ingresado por el usuario a comparar con los existentes
 * \return int El índice donde se encuentra el ID que coincide con el ingresado por el usuario, -1 si no existe
 *
 */


int buscarPorId(eBicicleta bicis[], int tam, int id);


/** \brief pide el ingreso del id, para buscar su indice en la estructura
 *
 * \param bicis[] eBicicleta El array de estructuras a recorrer para validar que exista el ID
 * \param tam int El tamaño del array de estructuras
 * \return int El índice donde se encuentra el ID que coincide con el ingresado por el usuario, -1 si no existe
 *
 */

int validarBici(eBicicleta bicis[], int tam);


/** \brief Modifica un dato particular de la estructura en caso de que el usuario se haya equivocado al dar de alta
 *
 * \param lista[] eBicicleta El array de estructuras donde se realizará la modificación
 * \param tam int El tamaño del array de estructuras
 * \param tipo[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param color[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

void modificarBici(eBicicleta lista[],int tam, eTipo tipo[], int tamTipo, eColor color[], int tamColor, int indice);


/** \brief Da de baja una estructura del ID que solicite el usuario
 *
 * \param lista[] eBicicleta El array de estructuras donde se encuentra el ID a dar de baja
 * \param tam int El tamaño del array de estructuras
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

int bajaBici(eBicicleta lista[], int tam);


/** \brief Muestra las bicicletas de detarminado color
 *
 * \param bicicletas[] eBicicleta El array de estructuras a mostrar
 * \param tam int El tamaño de del array a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 * \return
 *
 */

int mostrarBicicletasColor(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente clientes[], int tamCliente);


/** \brief muestra las bicicletas de determinado tipo
 *
 * \param bicicletas[] eBicicleta El array de estructuras a mostrar
 * \param tam int El tamaño de del array a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

int mostrarBicicletaTipo(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente);


/** \brief muestra la cantidad de bicicletas por material
 *
 * \param bicicletas[] eBicicleta El array de estructuras a mostrar
 * \param tam int El tamaño de del array a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

int mostrarBicicletaMaterial (eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo);


/** \brief muestra todas las bicicletas ordenadas por tipo
 *
 * \param bicicletas[] eBicicleta El array de estructuras a mostrar
 * \param tam int El tamaño de del array a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

int mostrarBicicletaPorTipo(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente clientes[], int tamClientes);


/** \brief muestra las bicicletas de determinado tipo y color
 *
 * \param bicicletas[] eBicicleta El array de estructuras a mostrar
 * \param tam int El tamaño de del array a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

int listarBicicletasColorTipo(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo);


/** \brief devuelve la cantidad de bicicletas con el color mas elegido
 *
 * \param bicicletas[] eBicicleta El array de estructuras a mostrar
 * \param tam int El tamaño de del array a mostrar
 * \param tipos[] eTipo El array de estructuras anidadas
 * \param tamTipo int El tamaño del array de estructuras anidadas
 * \param colores[] eColor El array de estructuras anidadas
 * \param tamColor int El tamaño del array de estructuras anidadas
 * \return int -1 si hubo error, 0 si no hubo error
 *
 */

int colorMasElegido(eBicicleta bicicletas[], int tamBicicletas, eColor color[], int tamColor, eTipo tipo[], int tamTipo);
