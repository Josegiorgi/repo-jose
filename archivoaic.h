#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H
#include "archivo.h"

class ArchivoAIC : public Archivo
{
public:
    ArchivoAIC();
    ~ArchivoAIC();
    Imagen leerImagen(string nombreArchivo) override ;
    void escribirImagen(Imagen& imagen, string nombreArchivo, string directorio) override;
};


#endif // ARCHIVOAIC_H
