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

class GestordeArchivos
{
public:
    GestordeArchivos();
    ~GestordeArchivos();
    Imagen generarImagen(int pID);
    void guardarImagen(string nombreImagen, Imagen& imagen);
    string reconocerFormato();

    const string &getRaiz() const;
    void setRaiz(const string &newRaiz);
    const string &getRuta() const;
    void setRuta(const string &newRuta);

    void setListadoDeArchivos(string rutaDirectorio);
    vector<string> getListadoDeArchivos(string rutaDirectorio);
    string getArchivos(int ID);

    const vector<string> &getListaCarpeta() const;
    void setListaCarpeta(string Ruta, int ID);


    int getIDimagen() const;
    void setIDimagen(int opcion);



private:

    //string reconocerFormato();//reconoce si es pnm o aic
    string raiz, ruta;//info que pasara al espacio de trabajo para pedirle un vector con nombres de archivos
    vector<string> listaArchivos;
    vector<string> listaCarpeta;
    string RutaCarpeta;

    int IDimagen;
    Archivo *ptrArchivo;

};

#endif // GESTORDEARCHIVOS_H
