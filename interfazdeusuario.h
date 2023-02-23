#ifndef INTERFAZDEUSUARIO_H
#define INTERFAZDEUSUARIO_H
#include "gestordearchivos.h"
#include "imagen.h"
#include "vector"
#include "string"
using namespace std;

/**
 * @brief Clase InterfazdeUsuario modela una interfaz que permite interactuar con el usuario
 * mostrandole la lista de carpetas e imagenes disponible, asi como tambien la lista de opciones
 * a seleccionar.
 * @author Josefina Giorgi Insaurralde
 */

class InterfazdeUsuario
{
public:
    /**
     * @brief InterfazdeUsuario Metodo constructor de la clase interfaz de usuario
     */
    InterfazdeUsuario();
    /**
     * @brief mostrarListaDeOpciones Metodo que muestra al usuario la lista de opciones de carpetas e imagenes.
     * @param lista Parametro que recibe una lista de string
     */
    void mostrarListaDeOpciones(vector<string> lista);
    /**
     * @brief mostrarOpcionElegida Metodo encargado de mostrar al usuario el nombre de la opcion elegida
     * @param pNombre Parametro que recibe un string del nombre
     */
    void mostrarOpcionElegida(string pNombre);
    /**
     * @brief formatoArchivoGuardar Metodo encargado de obtener el formato en el que se desea guardar la Imagen
     * @param pImagen Direccion en memoria de la Imagen
     * @return Devuelve un entero con la opcion seleccionada del formato a guardar
     */
    int formatoArchivoGuardar(Imagen &pImagen);
    /**
     * @brief nombreArchivoGuardar Metodo encargado de obtener a traves del usuario el nombre de la imagen a guardar
     * @return Devuelve un string de la imagen a guardar
     */
    string nombreArchivoGuardar();
    /**
     * @brief mostrarAtajosdeteclado Metodo encargado de mostrar al usuario las opciones de atajos de teclados
     */
    void mostrarAtajosdeTeclado();

};

#endif // INTERFAZDEUSUARIO_H
