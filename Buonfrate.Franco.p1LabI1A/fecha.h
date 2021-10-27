#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;



#endif // FECHA_H_INCLUDED



/** \brief Valida una fecha ingresada en formato (DD/MM/AAAA)
 *
 * \param dia int* puntero a dia
 * \param mes int* puntero a mes
 * \param anio int* puntero a anio
 * \return (-1) si hubo error, (0) en caso de carga correcta
 */

void validarFecha (int* dia, int* mes, int* anio);
