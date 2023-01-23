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
            cout<<codigo<<endl;
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
            cout<<descripcion<<endl;
        }
        {
            //leer tamanio
            archi>>columna>>fila;
            cout<<fila<<" "<<columna<<endl;
            imagen.setAlto(fila);
            imagen.setAncho(columna);
        }
        {
            //leer M
            archi>>M;
            cout<<M;
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


void ArchivoAIC::escribirImagen(Imagen &imagen, string directorio)
{
    string tipoArchivo = imagen.getCodigo();
    agregarExtension(tipoArchivo,directorio);

    ofstream archisalida;
    archisalida.open(directorio);
    if(archisalida.is_open())
    {
        cout<<"se crea archivo";
        archisalida<<imagen.getCodigo();
        archisalida<<"# "<<imagen.getDescripcion();
        archisalida<<imagen.getAncho()<<" "<<imagen.getAlto();
        archisalida<<imagen.getRangoDinamico();

        unsigned int repeticion = 1, filas = imagen.getAlto(), columnas = imagen.getAncho();
        float valorpixel, prueba;
        Pixel Pauxiliar1, Pprueba;

        for(unsigned int f=0; f<filas; f++)
        {
            Pixel Pauxiliar1;
            Pauxiliar1 = imagen.DevolverPixel(f,0);
            valorpixel = Pauxiliar1.getR();
            for(unsigned int c=1; c<columnas; c++)
            {
                Pprueba = imagen.DevolverPixel(f,c);
                prueba = Pprueba.getR();

                if (prueba==valorpixel)
                {
                    repeticion++;
                    if(c == (columnas-1))
                    {
                        archisalida<<valorpixel<<" "<<repeticion<<" ";

                    }
                    else
                    {
                        archisalida<<valorpixel<<" "<<repeticion<<" ";
                        valorpixel=prueba;
                        repeticion=1;
                        if (c == (columnas-1))
                        {
                         archisalida<<valorpixel<<" "<<repeticion<<" ";
                        }
                    }
                }
            }
            repeticion = 1;
        }
     archisalida.close();
    }
    else cout<<"No se pudo crear";

}

void ArchivoAIC::agregarExtension(string codigo, string directorio)
{
    //agregar excepcion
    if(codigo == "P2C")
        directorio += ".aic";
}
