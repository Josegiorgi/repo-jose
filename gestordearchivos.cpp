#include "gestordearchivos.h"
#include "archivopnm.h"
#include "archivoaic.h"
#include <fstream>
#include "vector"
#include "iostream"
#include <dirent.h>

using namespace std;

GestordeArchivos::GestordeArchivos()
{

}

GestordeArchivos::~GestordeArchivos()
{

}
Imagen GestordeArchivos::generarImagen(int pID)
{
    IDimagen=pID;
    Imagen imagen;
    string extension;
    extension= reconocerFormato();
    if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
        ptrArchivo = new ArchivoPNM;
    else if(extension == ".aic")
        ptrArchivo = new ArchivoAIC;
    else (throw (string) "No se reconoce");

    imagen = ptrArchivo->leerImagen(RutaCarpeta + getArchivos(pID));

    delete ptrArchivo;
    return imagen;

    // reconocerFormato();
}

void GestordeArchivos::guardarImagen(string nombreImagen, Imagen &imagen)
{

}

string GestordeArchivos::reconocerFormato() //lleva control de error
{
    string nombre = getArchivos(IDimagen);//devuelve un string
    return nombre.substr(nombre.find_last_of('.'), nombre.size());                                     //tomar las ultimas 3 letras y ver que objeto se crea

}

const vector<string> &GestordeArchivos::getListaCarpeta() const
{
    return listaCarpeta;
}

void GestordeArchivos::setListaCarpeta(string Ruta, int ID)
{
    RutaCarpeta =  Ruta + getArchivos(ID-1) + "/";
    listaArchivos.clear();
    listaCarpeta = getListadoDeArchivos(RutaCarpeta);
}

int GestordeArchivos::getIDimagen() const
{
    return IDimagen;
}

void GestordeArchivos::setIDimagen(int opcion)
{
    IDimagen = opcion;
}
const string &GestordeArchivos::getRuta() const
{
    return ruta;
}

void GestordeArchivos::setRuta(const string &newRuta)
{
    ruta = newRuta;
}

//void GestordeArchivos::setListadoDeArchivos(string rutaDirectorio)
//{

//    vector<string> Lista = getListadoDeArchivos(rutaDirectorio);
//    string extension;
//    string nombre;

//    for(unsigned int i=0 ; i<Lista.size() ; i++)
//    {
//        nombre = Lista[i];
//        extension = nombre.substr(nombre.find_last_of('.'), nombre.size());
//        if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm" or extension == ".aic")
//        {
//            listaArchivos.push_back(nombre);
//        }
//    }
//}

vector<string> GestordeArchivos::getListadoDeArchivos(string rutaDirectorio)
{
    //vector<string> lista_de_archivos;
    DIR *dir = opendir(rutaDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                listaArchivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
    return listaArchivos;
}

const string &GestordeArchivos::getRaiz() const
{
    return raiz;
}

void GestordeArchivos::setRaiz(const string &newRaiz)
{
    raiz = newRaiz;
}
string GestordeArchivos::getArchivos(int ID)
{
    return listaArchivos[ID-1];
}

