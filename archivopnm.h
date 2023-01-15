#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H
#include "archivo.h"

class ArchivoPNM : : public Archivo
{
public:
    ArchivoPNM();
    ~ArchivoPNM();
    Imagen leerImagen(string nombreArchivo) override;
    void escribirImagen(Imagen& imagen, string nombreArchivo, string directorio) override;
};

#endif // ARCHIVOPNM_H
