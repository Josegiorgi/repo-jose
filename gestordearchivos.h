#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include "string"
#include "vector"
#include "imagen.h"
#include "archivo.h"
#include "archivoaic.h"
#include "archivopnm.h"
#include "string"
using namespace std;

/**
 * @brief Clase GestordeArchivos que modela un sistema encargado de gestionar un directorio y las carpetas de archivos de imagenes del mismo, tambien es capaz de generar y guardar imagenes.
 * @author Josefina Giorgi Insaurralde
 */

class GestordeArchivos
{
public:
    /**
     * @brief GestordeArchivos Metodo constructor de la clase gestor de archivos
     */
    GestordeArchivos();
    /**
     * @brief ~GestodeArchivos Metodo destructor de la clase gestor de archivos
     */
    ~GestordeArchivos();
    /**
     * @brief generarImagen Metodo encargado de generar una imagen dependiendo de la extension del archivo en PNM y AIC
     * @return Devuelve un objeto imagen
     */
    Imagen generarImagen();
    /**
     * @brief guardarImagen Metodo que genera un archivo PNM o AIC a partir de una Imagen que se desea guardar
     * @param pNombre Parametro string que recibe el nombre de la imagen a guardar
     * @param pImagen Parametr que recibe la direccion de memoria de la imagen a guardar
     */
    void guardarImagen(string pNombre, Imagen &pImagen);
    /**
     * @brief guardarUltimaImagen
     * @param pImagen
     */
    void guardarUltimaImagen(Imagen &pImagen);
    /**
     * @brief edicionFormatoguardar Metodo encargado de modificar el codigo que identifica cada imagen, para lograr modificar el formato en el que sea guardar, texto, binario y aic.
     * @param pImagen Parametro que recibe la direccion de memoria de la imagen a la cual se le edita el formato
     * @param pEleccion Parametro que recibe un entero con la eleccion de formato a guardar
     */
    void edicionFormatoguardar(Imagen &pImagen, int pEleccion);

    /**
     * @brief getRaiz Metodo que devuelve la raiz
     * @return Devuelve un string que es la raiz
     */
    string getRaiz();
    /**
     * @brief setRaiz Metodo que define la raiz
     * @param pRaiz Parametro que recibe un string que es la raiz
     */
    void setRaiz(string pRaiz);

    /**
     * @brief getListadoDeArchivos Metodo encargado de barrer un directorio y devolver una lista con los nombres de archivos que se encuentran en una carpeta
     * @param pRaiz Parametro que recibe un string que permite identificar junto con la ruta la carpeta de donde se obtiene la lista de archivos
     * @return
     */
    vector<string> getListadoDeArchivos(string pRaiz);
    /**
     * @brief getArchivos Metodo encargado de devolver el nombre de una carpeta o archivo seleccionado
     * @param pID Parametro que recibe un entero con la posicion del archivo o carpeta que se devuelve
     * @return Devuelve un string con el nombre de la carpeta o archivo
     */
    string getArchivos(int pID);


    /**
     * @brief setListaImagenes Metodo encargado de definir una lista con los nombres de los archivos de imagenes presentes en cada carpeta
     * @param pRaiz Parametro que recibe un string con parte de la direccion de la carpeta a la cual pertenece el listado de archivos de imagenes
     * @param pID Parametro que recibe un entero con la posicion e que identifica la carpeta donde se encuentra el listado de archivos de imagenes
     */
    void setListaImagenes(string pRaiz, int pID);
    /**
     * @brief getListaImagenes Metodo encargado de devolver una lista con los nombres de los archivos de imagenes presentes en cada carpeta
     * @return Devuelve un vector de string con nombres de archivos de imagenes
     */
    vector<string> getListaImagenes();
    /**
     * @brief getIDimagen Metodo que devuelve la posicion que identifica un archivo o carpeta
     * @return Devuelve un entero que representa la posicion en una lista de un archivo o carpeta
     */
    int getIDimagen();
    /**
     * @brief setIDimagen Metodo que define la posicion que identifica a un archivo o carpeta
     * @param pOpcion Parametro entero que recibe la posicion de un archivo o carpeta
     */
    void setIDimagen(int pOpcion);


private:
    /**
     * @brief reconocerFormato Metodo encargado de reconocer el formato de cada imagen a leer o generar
     * @return Devuelve un string con la extension que permite reconocer el formato de cada imagen
     */
    string reconocerFormato();

    string ruta, raiz; /**< direccion hacia el directorio */
    vector<string> listaArchivos; /**< lista de archivos de imagenes o carpeta con archivos de imagenes */
    vector<string> listaImagenes; /**< lista de archivos de imagenes */
    string rutaCarpeta; /**< direccion hacia la carpeta con imagenes seleccionadas */
    int idImagen; /**< posicion del archivo imagen o carpeta */
    Archivo *ptrArchivo; /**< puntero archivo */

};

#endif // GESTORDEARCHIVOS_H
