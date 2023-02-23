#ifndef FILTRO_H
#define FILTRO_H
#include "imagen.h"

/**
 * @brief Clase Filtro abstracta que representa un sistema de filtrado a partir de operaciones matematicas entre las intensidades
 * de pixeles vecinos.
 * @author Josefina Giorgi Insaurralde
 */

class Filtro
{
public:
    /**
     * @brief Filtro Metodo constructor de la clase filtro
     */
    Filtro();
    /**
     * @brief ~Filtro Filtro Metodo destructor de la clase filtro
     */
    virtual ~Filtro();
    /**
     * @brief aplicarFiltro Metodo virtual puro que a partir de operaciones matematicas permite el filtrado de una imagen.
     * @param pImagen Parametro que recibe por referencia la imagen de la cual se obtiene informacion y se aplica el filtro
     */
    virtual void aplicarFiltro(Imagen &pImagen)=0;
};

#endif // FILTRO_H
