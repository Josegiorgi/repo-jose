#include "archivopnm.h"
#include "iostream"
#include "fstream"

using namespace  std;


ArchivoPNM::ArchivoPNM()
{

}
ArchivoPNM::~ArchivoPNM()
{

}

Imagen ArchivoPNM::leerImagen(string nombreArchivo)
{
    ifstream archiEntrada;
    Imagen imagen;
    string codigoImagen, descripcion, numeral, auxiliar;
    int M, filas, columnas;

    archiEntrada.open(nombreArchivo,ios::in|ios::binary);

    try
    {
        if(archiEntrada.is_open())
        {
            archiEntrada>>codigoImagen;
            imagen.setCodigo(codigoImagen);
            archiEntrada>>numeral;
            if (numeral != "#")
            {
                throw((string)"La imagen a leer no respeta el formato correcto, es corrupta. ");
            }

            getline(archiEntrada, descripcion);
            descripcion.erase(0,1);
            imagen.setDescripcion(descripcion);

            archiEntrada>>columnas>>filas;
            if (columnas == 0 or filas == 0)
            {
                throw ((string)"La imagen es corrupta posee un ancho y alto que no corresponden. ");
            }
            else
                imagen.setAlto(filas);
            imagen.setAncho(columnas);

            archiEntrada>>M;
            imagen.setRangoDinamico(M);
            archiEntrada.ignore();

            switch (codigoImagen[1]){
            case '1': leerP1(imagen, archiEntrada);
                break;
            case '2': leerP2(imagen, archiEntrada);
                break;
            case '3': leerP3(imagen, archiEntrada);
                break;
            case '4': leerP4(imagen, archiEntrada);
                break;
            case '5': leerP5(imagen, archiEntrada);
                break;
            case '6': leerP6(imagen, archiEntrada);
                break;
            default: cout<< "No se reconoce el codigo de la imagen a guardar.";
            }
        }

    }
    catch (string &error)
    {
        cout<<endl<<error<<endl;
    }

    archiEntrada.close();
    return imagen;
}



void ArchivoPNM::guardarImagen(Imagen &pImagen, string directorio)
{
    string codigoImagen = pImagen.getCodigo();
    string extension = devolverExtensionPnm(pImagen);

    ofstream archiSalida;
    archiSalida.open (directorio + extension, ios::binary);
    if (archiSalida.is_open())
    {
        //cout<<"SE GUARDA ARCHIVO";
        archiSalida<<codigoImagen<<endl;
        archiSalida<<"# "<<pImagen.getDescripcion()<<endl;
        archiSalida<<pImagen.getAncho()<<" "<<pImagen.getAlto()<<endl;

        if(codigoImagen != "P1" and codigoImagen != "P4")
        {
            archiSalida<<pImagen.getRangoDinamico()<<endl;
        }


        switch (codigoImagen[1]){
        case '1': almacenarP1(pImagen, archiSalida);
            break;
        case '2': almacenarP2(pImagen, archiSalida);
            break;
        case '3': almacenarP3(pImagen, archiSalida);
            break;
        case '4': almacenarP4(pImagen, archiSalida);
            break;
        case '5': almacenarP5(pImagen, archiSalida);
            break;
        case '6': almacenarP6(pImagen, archiSalida);
            break;
        default: cout<< "No se reconoce el codigo de la imagen a guardar.";
        }
        archiSalida.close();
    }
}

void ArchivoPNM::leerP1(Imagen &imagen, ifstream &archiEntrada)
{
    float auxiliar=0;
    imagen.dimensionarImagen();
    imagen.setRangoDinamico(1);

    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archiEntrada>>auxiliar;
            Pixel pAuxiliar (auxiliar,auxiliar,auxiliar);
            imagen.generarPixel(pAuxiliar,f,c);
        }
    }

}

void ArchivoPNM::leerP2(Imagen &imagen, ifstream &archiEntrada)
{
    float auxiliar=0;
    imagen.dimensionarImagen();

    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archiEntrada>>auxiliar;
            Pixel pAuxiliar(auxiliar, auxiliar, auxiliar);
            imagen.generarPixel(pAuxiliar,f,c);
        }
    }
}

void ArchivoPNM::leerP3(Imagen &imagen, ifstream &archiEntrada)
{
    float r=0, g=0 ,b =0;
    imagen.dimensionarImagen();

    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archiEntrada>>r>>g>>b;
            Pixel Pauxiliar(r, g, b);
            imagen.generarPixel(Pauxiliar,f,c);
        }
    }
}

void ArchivoPNM::leerP4(Imagen &imagen, ifstream &archiEntrada)
{
    unsigned char auxiliar=0;
    imagen.dimensionarImagen();
    imagen.setRangoDinamico(1);


    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archiEntrada.read((char * ) &auxiliar , sizeof(auxiliar));
            Pixel pAuxiliar(auxiliar, auxiliar, auxiliar);
            imagen.generarPixel(pAuxiliar,f,c);
        }
    }
}

void ArchivoPNM::leerP5(Imagen &imagen, ifstream &archiEntrada)
{
    unsigned char auxiliar=0;
    imagen.dimensionarImagen();


    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archiEntrada.read((char * ) &auxiliar , sizeof(auxiliar));
            Pixel pAuxiliar(auxiliar, auxiliar, auxiliar);
            imagen.generarPixel(pAuxiliar,f,c);
        }
    }
}

void ArchivoPNM::leerP6(Imagen &imagen, ifstream &archiEntrada)
{
    unsigned char r=0, g=0, b=0;
    imagen.dimensionarImagen();


    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archiEntrada.read((char * ) &r , sizeof(r));
            archiEntrada.read((char * ) &g , sizeof(g));
            archiEntrada.read((char * ) &b , sizeof(b));
            Pixel pAuxiliar(r, g, b);
            imagen.generarPixel(pAuxiliar,f,c);
        }
    }
}

string ArchivoPNM::devolverExtensionPnm(Imagen &imagen)
{
    string tipoArchivo = imagen.getCodigo();

    if(tipoArchivo == "P6" or tipoArchivo == "P3")
    {
        return ".ppm";
    }
    else if (tipoArchivo == "P5" or tipoArchivo == "P2")
    {
        return ".pgm";
    }
    else

        return ".pbm";

}

void ArchivoPNM::almacenarP1(Imagen &imagen, ofstream &archiSalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAlto(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.devolverPixel(f,c);
            archiSalida<<Pauxiliar.getR()<<" ";
        }
    }

}

void ArchivoPNM::almacenarP2(Imagen &imagen, ofstream &archiSalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAlto(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.devolverPixel(f,c);
            archiSalida<<Pauxiliar.getR()<<" ";
        }
    }
}

void ArchivoPNM::almacenarP3(Imagen &imagen, ofstream &archiSalida)
{
    Pixel Pauxiliar;
    float R,G,B;

    for(int f=0; f<imagen.getAlto(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.devolverPixel(f,c);
            R=Pauxiliar.getR();
            G=Pauxiliar.getG();
            B=Pauxiliar.getB();
            archiSalida<<R<<" "<<G<<" "<<B<<" ";
        }
    }
}

void ArchivoPNM::almacenarP4(Imagen &imagen, ofstream &archiSalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAlto(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.devolverPixel(f,c);
            unsigned char valor = Pauxiliar.getR();
            archiSalida.write((const char*)&valor, sizeof (valor));

        }
    }
}

void ArchivoPNM::almacenarP5(Imagen &imagen, ofstream &archiSalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAlto(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.devolverPixel(f,c);
            unsigned char valor = Pauxiliar.getR();
            archiSalida.write((const char*)&valor, sizeof (valor));
        }
    }

}

void ArchivoPNM::almacenarP6(Imagen &imagen, ofstream &archiSalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAlto(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.devolverPixel(f,c);
            unsigned char valorR = Pauxiliar.getR();
            unsigned char valorG = Pauxiliar.getG();
            unsigned char valorB = Pauxiliar.getB();
            archiSalida.write((const char*)&valorR, sizeof (valorR));
            archiSalida.write((const char*)&valorG, sizeof (valorG));
            archiSalida.write((const char*)&valorB, sizeof (valorB));

        }
    }
}
