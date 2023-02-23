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
   ruta = "C:/Users/Jose/OneDrive/Documentos/Proyecto final JG/";
}

GestordeArchivos::~GestordeArchivos()
{

}
Imagen GestordeArchivos::generarImagen()
{
    Imagen imagen;
    string extension;
    extension= reconocerFormato();
    try {

        if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
            ptrArchivo = new ArchivoPNM;
        else if(extension == ".aic")
            ptrArchivo = new ArchivoAIC;
        else (throw (string) "No se reconoce tipo de archivo");
    }
    catch (string &error)
    {
        delete ptrArchivo;
        cout<<endl<<error<<endl;
    }

    imagen = ptrArchivo->leerImagen(ruta + rutaCarpeta + getArchivos(idImagen));

    delete ptrArchivo;
    return imagen;
}

void GestordeArchivos::guardarImagen(string pNombre,Imagen &pImagen)
{
    string directorio = "C:/Users/Jose/OneDrive/Documentos/Proyecto final JG/Autotest/imagenes_guardadas/" + pNombre;
    string codigo = pImagen.getCodigo();

    if (codigo=="P2C")
    {
        ptrArchivo= new ArchivoAIC;
    }
    else
        ptrArchivo = new ArchivoPNM;

    ptrArchivo-> guardarImagen(pImagen,directorio);
    delete ptrArchivo;
}

void GestordeArchivos::guardarUltimaImagen(Imagen &pImagen)
{
    string directorio = "C:/Users/Jose/OneDrive/Documentos/Proyecto final JG/Autotest/ultima_imagen/UltimaImagen" ;
    string codigo = pImagen.getCodigo();

    if (codigo=="P2C")
    {
        ptrArchivo= new ArchivoAIC;
    }
    else
        ptrArchivo = new ArchivoPNM;

    ptrArchivo-> guardarImagen(pImagen,directorio);
    delete ptrArchivo;
}

void GestordeArchivos::edicionFormatoguardar(Imagen &pImagen, int pEleccion)
{
    string codigo = pImagen.getCodigo();

    if(pEleccion==1)
    {
        if (codigo=="P4")
            pImagen.setCodigo("P1");
        if(codigo=="P5")
            pImagen.setCodigo("P2");
        if(codigo=="P6")
            pImagen.setCodigo("P3");
    }
    if(pEleccion==2)
    {
        if (codigo=="P1")
            pImagen.setCodigo("P4");
        if(codigo=="P2")
            pImagen.setCodigo("P5");
        if(codigo=="P3")
            pImagen.setCodigo("P6");
    }
    if(pEleccion==3)
    {
        pImagen.setCodigo("P2C");
    }

}
string GestordeArchivos::reconocerFormato()
{
    string nombre = getArchivos(idImagen);//devuelve un string
    return nombre.substr(nombre.find_last_of('.'), nombre.size());//tomar las ultimas 3 letras y ver que objeto se crea
}
string GestordeArchivos::getRaiz()
{
    return raiz;
}

void GestordeArchivos::setRaiz(string pRaiz)
{
    raiz = pRaiz;
}
vector<string> GestordeArchivos::getListadoDeArchivos(string pRaiz)
{
    listaArchivos.clear();
    string directorio = ruta + pRaiz;
    DIR *dir = opendir(directorio.c_str());
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
string GestordeArchivos::getArchivos(int pID)
{
    return listaArchivos[pID];
}
void GestordeArchivos::setListaImagenes(string pRaiz, int pID)
{
    listaImagenes.clear();
    rutaCarpeta = pRaiz + getArchivos(pID) + "/";
    listaImagenes = getListadoDeArchivos(rutaCarpeta);
}
vector<string> GestordeArchivos::getListaImagenes()
{
    return listaImagenes;
}
int GestordeArchivos::getIDimagen()
{
    return idImagen;
}

void GestordeArchivos::setIDimagen(int pOpcion)
{
    idImagen = pOpcion;
}




