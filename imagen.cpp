#include "imagen.h"

Imagen::Imagen()
{

}

void Imagen::GenerarPixel(Pixel pixel , int fila, int columna)
{
    matrizimagen[fila][columna] = pixel;
}

Pixel Imagen::DevolverPixel(int fila, int columna)
{
    return matrizimagen [fila][columna];
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
    matrizimagen.resize(alto);
    for (int i=0; i<alto; i++)
    {
        matrizimagen[i].resize(ancho);
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

