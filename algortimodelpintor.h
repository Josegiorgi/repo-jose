#ifndef ALGORTIMODELPINTOR_H
#define ALGORTIMODELPINTOR_H
#include "imagen.h"
/**
 * @brief Clase DetectordeArea modela una clase que se encarga de detectar, calcular y colorear el area
 * de regiones con intensidades semejantes bajo un rango de tolerancia determinado.
 * @author Josefina Giorgi Insaurralde
 */

/**
 * @brief Posicion struct compuesto por fila y columna, necesario para crear el vector
 *  movimiento y recorrer los alrededores de una posicion especifica dada por f y c.
 */
struct Posicion
{ int f, c; };
const vector < Posicion > movimiento={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

class AlgortimodelPintor
{
public:
    /**
     * @brief DetectordeArea Metodo constructor de la clase detector de area
     */
    AlgortimodelPintor();

    /**
     * @brief colorearArea Metodo encargado de colorear el area detectada
     * @param pf Parametro que recibe la fila donde se selecciono con el click
     * @param pc Parametro que recibe la columna donde se selecciono con el click
     */
    void colorearArea(unsigned int pf, unsigned int pc);
    /**
     * @brief setImagen Metodo que define el puntero a imagen
     * @param pImagen Parametro que recibe como puntero a la imagen
     */
    void setImagen(Imagen *pImagen);
    /**
     * @brief limpiarArea Metodo encargado de limpiar la matriz donde se guardan los pixeles pintados
     */
    void limpiarArea();
    /**
     * @brief devolverArea Metodo encargado de devolver un valor que identifica el area detectada
     * @return Devuelve un flotante que representa el area detectada
     */
    float devolverArea();

private:
    /**
     * @brief dimensionaMatriz Metodo que redimensiona la matriz booleana con las dimensiones de la imagen
     */
    void dimensionaMatriz();
    /**
     * @brief buscarArea Metodo que representa un algoritmo recursivo que busca areas con intensidades semejantes bajo un rango de
     * tolerancia determinado.
     * @param pf Parametro que recibe la fila de la posicion donde se realizo el click
     * @param pc Parametro que recibe la columna de la posicion donde se realizo el click
     */
    void buscarArea(unsigned int pf, unsigned int pc);
    /**
     * @brief devolverDiferenciaPixel metodo que obtiene la diferencia de intensidad entre las componentes RGB de dos pixeles vecinos.
     * @param p1 Parametro que recibe un primer pixel por referencia
     * @param p2 Parametro que recibe el segundo pixel por referencia
     * @return Devuelve un entero que es la diferencia entre ambos pixeles
     */
    int devolverDiferenciaPixel (Pixel &p1, Pixel &p2);

    vector<vector<bool>> matrizMascara; /**< Mascara booleana */
    Pixel pInicial; /**< Pixel inicial al hacer el click */
    Imagen *ptrImagen; /**< Puntero imagen */
    int profundidad; /**< profundidad de busqueda del algoritmo recursivo */
    int tolerancia; /**< valor de tolerancia entre intensidades */
    float area=0; /**< valor del area calculada */


};

#endif // ALGORTIMODELPINTOR_H
