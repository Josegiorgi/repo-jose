#include "gestordearchivos.h"
#include "archivopnm.h"
#include "archivoaic.h"
#include <fstream>

GestordeArchivos::GestordeArchivos()
{

}
Imagen GestordeArchivos::generarImagen(int pID)
{
    ID=pID;
    Imagen imagen;
    string extension;
    extension= reconocerFormato();
    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagen = ptrArchivo->leerImagen(espaciodetrabajo.getListadoDeArchivos(ID));

    delete ptrArchivo;
    return imagen;

    reconocerFormato();
    //archivo->leerImagen(espacioDeTrabajo.getListadoDeArchivos(ID));
}

void GestordeArchivos::guardarImagen(string nombreImagen, Imagen &imagen)
{

}

string GestordeArchivos::reconocerFormato() //lleva control de error
{
    string nombre = espaciodetrabajo.getListadoDeArchivos(ID);//devuelve un string
    return nombre.substr(nombre.find_last_of('.'), nombre.size());                                      //tomar las ultimas 3 letras y ver que objeto se crea

}
const string &GestordeArchivos::getRuta() const
{
    return ruta;
}

void GestordeArchivos::setRuta(const string &newRuta)
{
    ruta = newRuta;
}

const string &GestordeArchivos::getRaiz() const
{
    return raiz;
}

void GestordeArchivos::setRaiz(const string &newRaiz)
{
    raiz = newRaiz;
}
