#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H
#include "archivo.h"
#include "imagen.h"
/**
 * @brief Clase ArchivoPNM que modela un archivo de imagen de tipo PNM, permite guardar y leer archivos de imagen de tipo PNM
 * @author Josefina Giorgi Insaurralde
 */
class ArchivoPNM : public Archivo
{
public:
    /**
     * @brief ArchivoPNM Metodo constructor de la clase archivoAIC
     */
    ArchivoPNM();
    /**
     * @brief ~ArchivoPNM Metodo destructor de la clase archivoAIC
     */
    ~ArchivoPNM();
    /**
     * @brief leerImagen Metodo virtual que genera una imagen a partir de la direccion de esta.
     * @param nombreArchivo Parametro que recibe el nombre del archivo de la imagen
     * @return Devuelve un objeto imagen
     */
    Imagen leerImagen(string nombreArchivo) override;
    /**
     * @brief guardarImagen Metodo virtual que genera un archivo a partir de una imagen
     * @param pImagen Parametro  que indica la direccion en memoria de la imagen a guardar.
     * @param directorio String con la direccion de carpeta en donde seran almacenadas las imagenes guardadas
     */
    void guardarImagen(Imagen &pImagen, string directorio) override;

private:
    /**
     * @brief leerP1 Metodo privado encargado de leer imagenes del tipo P1
     * @param imagen Parametro que recibe la imagen por referencia
     * @param archiEntrada Parametro que recibe el archivo a leer por referencia
     */
    void leerP1(Imagen &imagen, ifstream &archiEntrada);
    /**
     * @brief leerP2 Metodo privado encargado de leer imagenes del tipo P2
     * @param imagen Parametro que recibe la imagen por referencia
     * @param archiEntrada Parametro que recibe el archivo a leer por referencia
     */
    void leerP2(Imagen &imagen, ifstream &archiEntrada);
    /**
     * @brief leerP3 Metodo privado encargado de leer imagenes del tipo P3
     * @param imagen Parametro que recibe la imagen por referencia
     * @param archiEntrada Parametro que recibe el archivo a leer por referencia
     */
    void leerP3(Imagen &imagen, ifstream &archiEntrada);
    /**
     * @brief leerP4 Metodo privado encargado de leer imagenes del tipo P4
     * @param imagen Parametro que recibe la imagen por referencia
     * @param archiEntrada Parametro que recibe el archivo a leer por referencia
     */
    void leerP4(Imagen &imagen, ifstream &archiEntrada);
    /**
     * @brief leerP5 Metodo privado encargado de leer imagenes del tipo P5
     * @param imagen Parametro que recibe la imagen por referencia
     * @param archiEntrada Parametro que recibe el archivo a leer por referencia
     */
    void leerP5(Imagen &imagen, ifstream &archiEntrada);
    /**
     * @brief leerP6 Metodo privado encargado de leer imagenes del tipo P6
     * @param imagen Parametro que recibe la imagen por referencia
     * @param archiEntrada Parametro que recibe el archivo a leer por referencia
     */
    void leerP6(Imagen &imagen, ifstream &archiEntrada);

    /**
     * @brief devolverExtensionPnm Metodo encargado de devolver la extension PNM correspondiente a la direccion de imagen a guardar
     * @param imagen Parametro que recibe por referencia la imagen
     * @return Devuelve un string con la extension
     */
    string devolverExtensionPnm(Imagen &imagen);

    /**
     * @brief almacenarP1 Metodo privado encargado de guardar el archivo de la imagen de tipo P1
     * @param imagen Parameto que recibe por referencia la imagen a guardar
     * @param archiSalida Parametro que recibe por referencia el archivo donde la imagen se almacena
     */
    void almacenarP1 (Imagen &imagen, ofstream &archiSalida);
    /**
     * @brief almacenarP2 Metodo privado encargado de guardar el archivo de la imagen de tipo P2
     * @param imagen Parameto que recibe por referencia la imagen a guardar
     * @param archiSalida Parametro que recibe por referencia el archivo donde la imagen se almacena
     */
    void almacenarP2 (Imagen &imagen, ofstream &archiSalida);
    /**
     * @brief almacenarP3 Metodo privado encargado de guardar el archivo de la imagen de tipo P3
     * @param imagen Parameto que recibe por referencia la imagen a guardar
     * @param archiSalida Parametro que recibe por referencia el archivo donde la imagen se almacena
     */
    void almacenarP3 (Imagen &imagen, ofstream &archiSalida);
    /**
     * @brief almacenarP4 Metodo privado encargado de guardar el archivo de la imagen de tipo P4
     * @param imagen Parameto que recibe por referencia la imagen a guardar
     * @param archiSalida Parametro que recibe por referencia el archivo donde la imagen se almacena
     */
    void almacenarP4 (Imagen &imagen, ofstream &archiSalida);
    /**
     * @brief almacenarP5 Metodo privado encargado de guardar el archivo de la imagen de tipo P5
     * @param imagen Parameto que recibe por referencia la imagen a guardar
     * @param archiSalida Parametro que recibe por referencia el archivo donde la imagen se almacena
     */
    void almacenarP5 (Imagen &imagen, ofstream &archiSalida);
    /**
     * @brief almacenarP6 Metodo privado encargado de guardar el archivo de la imagen de tipo P6
     * @param imagen Parameto que recibe por referencia la imagen a guardar
     * @param archiSalida Parametro que recibe por referencia el archivo donde la imagen se almacena
     */
    void almacenarP6 (Imagen &imagen, ofstream &archiSalida);


};

#endif // ARCHIVOPNM_H
