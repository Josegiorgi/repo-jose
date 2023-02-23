#ifndef IMAGEN_H
#define IMAGEN_H
#include "pixel.h"
#include "string"
#include "vector"
#include <string>
using namespace std;

/**
 * @brief Clase Imagen que modela una imagen compuesta por una matriz de pixeles. Puede ser una imagen binaria, de intensidades o RGB.
 * Conoce y devuelve informacion referida a la imagen.
 * @author Josefina Giorgi Insaurralde
 */

class Imagen
{
public:
    /**
     * @brief Imagen Metodo constructor de la clase Imagen
     */
    Imagen();
    /**
     * @brief generarPixel Metodo encargado de establecer un pixel en una posicion especifica
     * @param pPix Parametro que recibe el pixel a establecer
     * @param pFila Parametro que recibe la fila de la posicion especifica del pixel
     * @param pColumna Parametro que recibe la columna de la posicion especifica del pixel
     */
    void generarPixel (Pixel pPix, int pFila, int pColumna);
    /**
     * @brief devolverPixel Metodo encargado de devoler un pixel de una posicion especifica
     * @param pFila Parametro que recibe la fila de la posicion del pixel a devolver
     * @param pColumna Parametro que recibe la columna de la posicion del pixel a devolver
     * @return Devuelve un objeto pixel
     */
    Pixel devolverPixel (int pFila, int pColumna);
    /**
     * @brief setImagen Metodo que define la matriz de pixeles que confroma la imagen
     * @param newImagen Parametro que recibe una una imagen
     */
    void setImagen(vector<vector<Pixel> > newImagen);
    /**
     * @brief getAlto Metodo que devuelve el alto o filas de la imagen
     * @return Devuelte un entero que es el alto de la imagen
     */
    int getAlto();
    /**
     * @brief setAlto Metodo que define el alto o filas de una imagen
     * @param valorAlto Parametro que recibe un entero
     */
    void setAlto(int valorAlto);
    /**
     * @brief getAncho Metodo que devuelve el ancho o columnas de la imagen
     * @return Devuelte un entero que es el ancho de la imagen
     */
    int getAncho();
    /**
     * @brief setAncho Metodo que define el ancho o columnas de una imagen
     * @param valorAncho Parametro que recibe un entero
     */
    void setAncho(int valorAncho);
    /**
     * @brief getRangoDinamico Metodo que devuelve el rango dinamico de la imagen
     * @return Devuelve un entero que es el rango dinamico de la imagen
     */
    int getRangoDinamico();
    /**
     * @brief setRangoDinamico Metodo que define el rango dinamico de la imagen
     * @param pM Parametro que recibe un entero que es el rango dinamico de la imagen
     */
    void setRangoDinamico(int pM);
    /**
     * @brief dimensionarImagen Metodo que redimensiona en ancho y alto de una imagen
     */
    void dimensionarImagen();
    /**
     * @brief getCodigo Metodo que devuelve el codigo que identifica cada imagen
     * @return Devuelve un string con el codigo de la imagen
     */
    string getCodigo() ;
    /**
     * @brief setCodigo Metodo que define el codigo de una imagen
     * @param newCodigo Parametro que recibe un string con el codigo de la imagen
     */
    void setCodigo(string pCodigo);
    /**
     * @brief setDescripcion Metodo que define la descripcion de una imagen
     * @param newDescripcion Parametro que recibe un string con la descripcion
     */
    void setDescripcion(string pDescripcion);
    /**
     * @brief getDescripcion Metodo que devuelve la descripcion de una imagen
     * @return Devuelve un string con la descripcion
     */
    string getDescripcion();


private:
    vector<vector<Pixel>> imagen; /**< Matriz de pixeles que modela la imagen */
    int alto, ancho; /**< Alto y ancho de la imagen */
    int rangoDinamico; /**< Rango dinamico de la imagen */
    string codigo, descripcion; /**< Codigo y descripcion de la imagen */

};
#endif // IMAGEN_H
