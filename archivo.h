#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "imagen.h"
#include "string"
using namespace std;

/**
 * @brief Clase Archivo abstracta que permite leer y guardar archivos de imagenes, los cuales pueden ser tipo PNM o AIC.
 * @author Josefina Giorgi Insaurralde
 */

class Archivo
{
public:
    /**
     * @brief Archivo Metodo que modela el constructor de la clase archivo
     */
    Archivo();
    /**
     * @brief ~Archivo Metodo que modela el destructor de la clase archivo
     */
    virtual ~Archivo();
    /**
     * @brief leerImagen Metodo virtual que genera una imagen a partir de la direccion de esta.
     * @param nombreArchivo Parametro que recibe el nombre del archivo de la imagen
     * @return Devuelve un objeto imagen
     */
    virtual Imagen leerImagen(string nombreArchivo)=0;
    /**
     * @brief guardarImagen Metodo virtual que genera un archivo a partir de una imagen
     * @param pImagen Parametro que indica la direccion en memoria de la imagen a guardar.
     * @param directorio String con la direccion de carpeta en donde seran almacenadas las imagenes guardadas
     */
    virtual void guardarImagen(Imagen &pImagen, string directorio)=0;
};


#endif // ARCHIVO_H
