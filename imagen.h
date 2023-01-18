#ifndef IMAGEN_H
#define IMAGEN_H
#include "pixel.h"
#include "string"
#include "vector"

using namespace std;

class Imagen
{
public:
    Imagen();
    void GenerarPixel (Pixel pix, int fila, int columna);
    Pixel DevolverPixel (int fila, int columna);
    int getAlto() const;
    void setAlto(unsigned int valorAlto);
    int getAncho() const;
    void setAncho(int valorAncho);
    int getRangoDinamico() const;
    void setRangoDinamico(int M);
    void dimensionar();
    const string &getCodigo() const;
    void setCodigo(const string &newCodigo);
    const string &getDescripcion() const;
    void setDescripcion(const string &newDescripcion);

    const vector<vector<Pixel> > &getImagen() const;
    void setImagen(const vector<vector<Pixel> > &newImagen);

private:
    vector<vector<Pixel>> imagen;
    int alto, ancho;
    int RangoDinamico;
    string codigo, descripcion;

};
#endif // IMAGEN_H
