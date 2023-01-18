#include "imagen.h"

Imagen::Imagen()
{

}

void Imagen::GenerarPixel(Pixel pixel , int fila, int columna)
{
    imagen[fila][columna] = pixel;
}

Pixel Imagen::DevolverPixel(int fila, int columna)
{
    return imagen [fila][columna];
}

int Imagen::getAlto() const
{
    return alto;
}

void Imagen::setAlto(unsigned int valorAlto)
{
    alto = valorAlto;
}

int Imagen::getAncho() const
{
    return ancho;
}

void Imagen::setAncho(int valorAncho)
{
    ancho = valorAncho;
}

int Imagen::getRangoDinamico() const
{
    return RangoDinamico;
}

void Imagen::setRangoDinamico(int M)
{
    RangoDinamico = M;
}
void Imagen::dimensionar()
{
    imagen.resize(alto);
    for (int i=0; i<alto; i++)
    {
       imagen[i].resize(ancho);
    }
}

const string &Imagen::getCodigo() const
{
    return codigo;
}

void Imagen::setCodigo(const string &newCodigo)
{
    codigo = newCodigo;
}

const string &Imagen::getDescripcion() const
{
    return descripcion;
}

void Imagen::setDescripcion(const string &newDescripcion)
{
    descripcion = newDescripcion;
}

const vector<vector<Pixel> > &Imagen::getImagen() const
{
    return imagen;
}

void Imagen::setImagen(const vector<vector<Pixel> > &newImagen)
{
    imagen = newImagen;
}

int Imagen::getCodigonumerico() const
{
    return codigonumerico;
}

void Imagen::setCodigonumerico(int newCodigonumerico)
{
    codigonumerico = newCodigonumerico;
}



