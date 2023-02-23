#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H
#include "archivo.h"
#include "imagen.h"
/**
 * @brief Clase ArchivoAIC que modela un archivo de imagen de tipo AIC, permite guardar y leer archivos de imagen de tipo AIC
 * @author Josefina Giorgi Insaurralde
 */
class ArchivoAIC : public Archivo
{
public:
    /**
     * @brief ArchivoAIC
     */
    ArchivoAIC();
    /**
     * @brief ~ArchivoAIC
     * */
    ~ArchivoAIC();
    /**
     * @brief leerImagen Metodo virtual que genera una imagen a partir de la direccion de esta.
     * @param nombreArchivo Parametro que recibe el nombre del archivo de la imagen
     * @return Devuelve un objeto imagen
     */
    Imagen leerImagen(string nombreArchivo) override ;
    /**
     * @brief guardarImagen Metodo virtual que genera un archivo a partir de una imagen
     * @param pImagen Parametro  que indica la direccion en memoria de la imagen a guardar.
     * @param directorio String con la direccion de carpeta en donde seran almacenadas las imagenes guardadas
     */
    void guardarImagen(Imagen &pImagen, string directorio) override;

private:
    /**
     * @brief agregarExtensionAic Metodo encargado de devolver la extension .aic para el guardado del archivo de imagen
     * @return Devuelve un string con la extension aic
     */
    string devolverExtensionAic();
};


#endif // ARCHIVOAIC_H
