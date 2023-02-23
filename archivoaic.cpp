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
    ifstream archiEntrada;
    Imagen imagen;
    string codigoImagen, descripcion, numeral;
    int M;
    int fila=0, columna=0;

    archiEntrada.open(nombreArchivo);

    try
    {
        if(archiEntrada.is_open())
        {
            archiEntrada>>codigoImagen;
            if (codigoImagen != "P2C")
            {
                throw((string) "El codigo de la imagen no se reconoce, es corrupta.");
            }
            else
                imagen.setCodigo(codigoImagen);

            archiEntrada>>numeral;
            if (numeral != "#")
            {
                throw((string)"La imagen es corrupta, no respeta el formato correcto. ");
            }

            getline(archiEntrada, descripcion);
            descripcion.erase(0,1);
            imagen.setDescripcion(descripcion);

            archiEntrada>>columna>>fila;
            if (columna == 0 or fila == 0)
            {
                throw ((string)"La imagen es corrupta posee un ancho y alto que no corresponden. ");
            }
            else
                imagen.setAlto(fila);
            imagen.setAncho(columna);

            archiEntrada>>M;
            imagen.setRangoDinamico(M);
            archiEntrada.ignore();

        }

    }
    catch (string &error)
    {
        cout<<endl<<error<<endl;
    }

    imagen.dimensionarImagen();

    float intensidad = 0;
    unsigned int contador = 0;

    for(int f = 0; f < fila; f++)
    {
        int PixelesporFila = 0;

        while(PixelesporFila < columna)
        {
            archiEntrada>>intensidad>>contador;
            Pixel pAuxiliar(intensidad,intensidad,intensidad);
            for(unsigned int i = 0; i < contador; i ++)
            {
                int auxiliar = PixelesporFila + i;
                imagen.generarPixel(pAuxiliar,f, auxiliar);
            }
            PixelesporFila += contador;
        }
    }
    return imagen;
}


void ArchivoAIC::guardarImagen(Imagen &pImagen, string directorio)
{
    string codigoImagen = pImagen.getCodigo();
    string extension = devolverExtensionAic();
    unsigned int filas = pImagen.getAlto();
    unsigned int columnas = pImagen.getAncho();

    ofstream archiSalida;
    archiSalida.open(directorio+extension);
    if(archiSalida.is_open())
    {
        archiSalida<<codigoImagen<<endl;
        archiSalida<<"# "<<pImagen.getDescripcion()<<endl;
        archiSalida<<columnas<<" "<<filas<<endl;
        archiSalida<<pImagen.getRangoDinamico()<<endl;


        int valorPixel = pImagen.devolverPixel(0,0).getR();
        unsigned int repeticiones = 1;

        for(unsigned int f = 0; f < filas ; f++)
        {
            for(unsigned int c = 1; c < columnas ; c++)
            {

                int pValorPixel = pImagen.devolverPixel(f,c).getR();

                if(valorPixel == pValorPixel)
                {
                    repeticiones++;
                }
                else
                {
                    archiSalida<<valorPixel<<" "<<repeticiones<<" ";
                    valorPixel = pValorPixel;
                    repeticiones = 1;
                }
            }

            archiSalida<<valorPixel<<" "<<repeticiones<<" ";
            repeticiones=1;

        }
        archiSalida.close();
    }
}
string ArchivoAIC::devolverExtensionAic()
{
    return ".aic";
}
