#ifndef EDITORDEIMAGEN_H
#define EDITORDEIMAGEN_H
#include "imagen.h"
#include "interfazdeusuario.h"
#include "lut.h"
#include "filtro.h"
#include "procesadorestadistico.h"

/**
 * @brief Clase EditordeImagen que modela un sistema de edicion de imagen, permite modificar ciertos parametros de la imagenes
 * @author Josefina Giorgi Insaurralde
 */

class EditordeImagen
{
public:
    /**
     * @brief EditordeImagen Metodo constructor de la clase editor de imagen
     */
    EditordeImagen();
    /**
     * @brief aumentarBrillo Metodo que aumenta el brillo de una imagen
     * @param pImagen Parametro que recibe por referencia de la imagen a la cual se le aumenta el brillo
     */
    void aumentarBrillo(Imagen &pImagen);
    /**
     * @brief disminuirBrillo Metodo que disminuye el brillo de una imagen
     * @param pImagen Parametro que recibe por referencia de la imagen a la cual se le disminuye el brillo
     */
    void disminuirBrillo(Imagen &pImagen);
    /**
     * @brief modificarContraste Metodo encargado de modificar el contraste de la imagen
     * @param pImagen Parametro que recibe por referencia de la imagen a modificar
     */
    void modificarContraste(Imagen &pImagen);
    /**
     * @brief negativoImagen Metodo encargado de negativizar la imagen
     * @param pImagen Parametro que recibe por referencia la imagen a modificar
     */
    void negativoImagen(Imagen &pImagen);
    /**
     * @brief aplicarFiltro Metodo encargado de aplicar el filtro correspondiente a la imagen
     * @param pImagen Parametro que recibe por referecnia la imagen a la cual se le aplicara el filtro
     * @param pOpcion Parametro entero que recibe la opcion del filtro seleccionada por el usuario
     */
    void aplicarFiltro(Imagen &pImagen, int pOpcion);
    /**
     * @brief aplicarLut Metodo encargado de aplicar LUT a la imagen
     * @param pImagen Parametro que recibe por referecnia la imagen a la cual se le aplica LUT
     * @param pOpcion Parametro entero que recibe la opcion de la tabla LUT seleccionada por el usuario
     */
    void aplicarLut(Imagen &pImagen, int pOpcion);
    /**
     * @brief binarizar Metodo encargado de binarizar la imagen
     * @param pImagen Parametro que recibe por referecnia la imagen a binarizar
     */
    void binarizar(Imagen &pImagen);

private:
    ProcesadorEstadistico procesador; /**< Procesador estadistico necesario para modificar los parametros de la imagen en la edicion */
    Lut lut; /**< tabla de mapas de colores para lograr pseudocolorear la imagen */
    Filtro *ptrFiltro; /**< Puntero a filtro */
};

#endif // EDITORDEIMAGEN_H
