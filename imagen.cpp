#include "imagen.h"

Imagen::Imagen()
{

}

void Imagen::generarPixel(Pixel pPix , int pFila, int pColumna)
{
    imagen[pFila][pColumna] = pPix;
}

Pixel Imagen::devolverPixel(int pFila, int pColumna)
{
    return imagen [pFila][pColumna];
}

int Imagen::getAlto()
{
    return alto;
}

void Imagen::setAlto( int valorAlto)
{
    alto = valorAlto;
}

int Imagen::getAncho()
{
    return ancho;
}

void Imagen::setAncho(int valorAncho)
{
    ancho = valorAncho;
}

int Imagen::getRangoDinamico()
{
    return rangoDinamico;
}

void Imagen::setRangoDinamico(int pM)
{
    rangoDinamico = pM;
}
void Imagen::dimensionarImagen()
{
    imagen.resize(alto);
    for (int i=0; i<alto; i++)
    {
       imagen[i].resize(ancho);
    }
}

string Imagen::getCodigo()
{
    return codigo;
}

void Imagen::setCodigo(string pCodigo)
{
    codigo = pCodigo;
}

string Imagen::getDescripcion()
{
    return descripcion;
}

void Imagen::setDescripcion(string pDescripcion)
{
    descripcion = pDescripcion;
}
void Imagen::setImagen(vector<vector<Pixel> > newImagen)
{
    imagen = newImagen;
}




