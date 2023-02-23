#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H
#include "filtro.h"
#include "imagen.h"

/**
 * @brief Clase FiltroPasabajos es un filtro de suavizado a una imagen
 * @author Josefina Giorgi Insaurralde
 */
class FiltroPasabajos : public Filtro
{
public:
    /**
     * @brief FiltroPasabajos Metodo constructtor de la clase filtro pasa bajos
     */
    FiltroPasabajos();
    /**
     * @brief ~FiltroPasabajos Metodo destructor de la clase filtro pasa bajos
     */
    ~FiltroPasabajos() override;
    /**
     * @brief aplicarFiltro Metodo encargado de aplicar el filtro a la imagen a traves de operaciones algebraica entre el kernel de suavizado y los pixeles de la imagen
     * @param pImagen Parametro que recibe por referencia a la imagen de la cual se obtiene infromacion y se aplica el filtrado
     */
    void aplicarFiltro(Imagen &pImagen) override;

private:
    vector<float> kernel; /**< lista de valores del kernel de suavizado */
};

#endif // FILTROPASABAJOS_H
