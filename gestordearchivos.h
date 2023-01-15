#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include "string"
#include "vector"
#include "imagen.h"
#include <espaciodetrabajo.h>
#include "archivo.h"
#include "archivoaic.h"
#include "archivopnm.h"
#include "string"

using namespace std;

class GestordeArchivos
{
public:
    GestordeArchivos();
    Imagen generarImagen(int pID);
    void guardarImagen(string nombreImagen, Imagen& imagen);

    const string &getRaiz() const;
    void setRaiz(const string &newRaiz);

    const string &getRuta() const;
    void setRuta(const string &newRuta);

private:
    EspaciodeTrabajo espaciodetrabajo; //genera un vector que luego usara gestor de archivo para generar los objetos imagen
    string reconocerFormato();//reconoce si es pnm o aic
    string raiz, ruta;//info que pasara al espacio de trabajo para pedirle un vector con nombres de archivos
    //objeto archivo
    int ID;
    Archivo *ptrArchivo;
};

#endif // GESTORDEARCHIVOS_H
