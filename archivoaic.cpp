#include "archivoaic.h"
#include "iostream"
#include "fstream"

ArchivoAIC::ArchivoAIC()
{

}

ArchivoAIC::~ArchivoAIC()
{

}

Imagen ArchivoAIC::leerImagen(string nombreArchivo)
{
    ifstream archi;
    Imagen imagen;
    string codigo, descripcion, numeral;
    int M, fila, columna;

    archi.open(nombreArchivo);
    if(archi.is_open())
    {
        cout<<"SE ABRE ARHCIVO"<<endl;
        {   //leer codigo
            archi>>codigo;
            imagen.setCodigo(codigo);
            archi>>numeral;
            if (numeral != "#")
            {
                cout<<"imagencorrupta";
            }
        }
        {
            //leer descripcion
            getline(archi, descripcion);
            descripcion.erase(0,1);
            imagen.setDescripcion(descripcion);
        }
        {
            //leer tamanio
            archi>>columna>>fila;
            cout<<columna<<endl<<fila;
            imagen.setAlto(fila);
            imagen.setAncho(columna);
        }
        {
            //leer M
            archi>>M;
            imagen.setRangoDinamico(M);
        }}

    else cout<<"No se abre";

    archi.ignore();
    int valor, repeticion, pixelesFila = 0;
    vector<vector<Pixel>> matrizimagen;
    imagen.dimensionar();

    for(int i=0 ; i<imagen.getAlto() ; i++)
    {
        do
        {
            archi >> valor >> repeticion;
            for(int j=0 ; j<repeticion ; j++)
                matrizimagen[i][pixelesFila + j] = Pixel(valor,valor,valor);
                        pixelesFila += repeticion;

        } while( pixelesFila < imagen.getAncho() );
    }
  imagen.setImagen(matrizimagen);

  return imagen;
}


void ArchivoAIC::escribirImagen(Imagen &imagen, string nombreArchivo, string directorio)
{

}
