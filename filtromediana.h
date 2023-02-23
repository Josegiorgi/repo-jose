#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H
#include "filtro.h"
#include "imagen.h"
#include "algorithm"

/**
 * @brief Clase FiltroMediana es un tipo de filtro que permite la eliminacion del efecto sal y pimienta de una imagen.
 * @author Josefina Giorgi Insaurralde
 */

class FiltroMediana : public Filtro
{
public:
    /**
     * @brief FiltroMediana Metodo constructor de la clase filtro de mediana
     */
    FiltroMediana();
    /**
     * @brief ~FiltroMediana Metodo destructor de la clase filtro de mediana
     */
    ~FiltroMediana() override;
    /**
     * @brief aplicarFiltro Metodo que aplica el filtro de mediana a la imagen a partir del analisis de cada pixel, sus vecinos
     * y su ordenamiento de menor a mayor.
     * @param pImagen Parametro que recibe por referencia a la imagen de la cual se obtiene informacion y se filtra
     */
    void aplicarFiltro(Imagen &pImagen) override;

};

#endif // FILTROMEDIANA_H
