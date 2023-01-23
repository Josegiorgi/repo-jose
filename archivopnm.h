#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H
#include "archivo.h"
#include "imagen.h"

class ArchivoPNM : public Archivo
{
public:
    ArchivoPNM();
    ~ArchivoPNM();
    Imagen leerImagen(string nombreArchivo) override;
    void escribirImagen(Imagen& imagen, string directorio) override;

private:
    void LeerP1(Imagen &imagen, ifstream &archi);
    void LeerP2(Imagen &imagen, ifstream &archi);
    void LeerP3(Imagen &imagen, ifstream &archi);
    void LeerP4(Imagen &imagen, ifstream &archi);
    void LeerP5(Imagen &imagen, ifstream &archi);
    void LeerP6(Imagen &imagen, ifstream &archi);

    void agregarExtensionPNM(Imagen &imagen, string rutaImagen);

    void AlmacenarP1 (Imagen &imagen, ofstream &archisalida);
    void AlmacenarP2 (Imagen &imagen, ofstream &archisalida);
    void AlmacenarP3 (Imagen &imagen, ofstream &archisalida);
    void AlmacenarP4 (Imagen &imagen, ofstream &archisalida);
    void AlmacenarP5 (Imagen &imagen, ofstream &archisalida);
    void AlmacenarP6 (Imagen &imagen, ofstream &archisalida);


};

#endif // ARCHIVOPNM_H
