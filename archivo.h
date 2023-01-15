#ifndef ARCHIVO_H
#define ARCHIVO_H


class Archivo
{
public:
    Archivo();
    virtual ~Archivo();
    virtual Imagen leerImagen(string nombreArchivo)=0;
    virtual void escribirImagen(Imagen& imagen, string nombreArchivo, string directorio)=0;
};


#endif // ARCHIVO_H
