#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H
#include "archivo.h"
#include "imagen.h"

class ArchivoAIC : public Archivo
{
public:
    ArchivoAIC();
    ~ArchivoAIC();
    Imagen leerImagen(string nombreArchivo) override ;
    void escribirImagen(Imagen& imagen, string directorio) override;
private:
    void agregarExtension(string codigo, string directorio);
};


#endif // ARCHIVOAIC_H
