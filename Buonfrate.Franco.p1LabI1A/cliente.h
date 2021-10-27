#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}   eCliente;

#endif // CLIENTE_H_INCLUDED


/** \brief muestra el listado de los clientes
 *
 * \param clientes eCliente estructura de clientes
 * \param tamClientes int tamanio de la estructura cliente
 * \return (0) en caso de error, (1) en caso de que este todo ok
 *
 */

int listarClientes(eCliente clientes[], int tamClientes);


/** \brief muestra un cliente por id
 *
 * \param clientes eCliente estructura de clientes
 * \param tamClientes int tamanio de la estructura cliente
 * \param idCliente id del cliente a mostrar
 * \return (0) en caso de error, (1) en caso de que este todo ok
 *
 */

int mostrarCliente(eCliente clientes[], int tamClientes, int idCliente);
