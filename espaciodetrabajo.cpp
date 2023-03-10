#include "espaciodetrabajo.h"
#include <dirent.h>
#include <iostream>

EspaciodeTrabajo::EspaciodeTrabajo()
{

}

void EspaciodeTrabajo::setListadoDeArchivos(string rutaDirectorio)
{

    vector<string> Lista = getListadoDeArchivos(rutaDirectorio);
    string extension;
    string nombre;

    for(unsigned int i=0 ; i<Lista.size() ; i++)
    {
        nombre = Lista[i];
        extension = nombre.substr(nombre.find_last_of('.'), nombre.size());
        if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm" or extension == ".aic")
        {
            listaArchivos.push_back(nombre);
        }
    }
}

vector<string> EspaciodeTrabajo::getListadoDeArchivos(string rutaDirectorio)
{
    vector<string> lista_de_archivos;
    DIR *dir = opendir(rutaDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                lista_de_archivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
    return lista_de_archivos;
}


