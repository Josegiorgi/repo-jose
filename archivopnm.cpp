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
    ifstream archi;
    Imagen imagen;
    string codigo, descripcion, numeral;
    int M, fila, columna;

    archi.open(nombreArchivo,ios::in|ios::binary);
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
            imagen.setAlto(fila);
            imagen.setAncho(columna);
        }
        {
            //leer M
            archi>>M;
            imagen.setRangoDinamico(M);
        }


    if (codigo == "P1")
    {
        imagen.setCodigonumerico(1);
    }
    if (codigo == "P2")
    {
        imagen.setCodigonumerico(2);
    }
    if (codigo == "P3")
    {
        imagen.setCodigonumerico(3);
    }
    if (codigo == "P4")
    {
        imagen.setCodigonumerico(4);
    }
    if (codigo == "P5")
    {
        imagen.setCodigonumerico(5);
    }
    if (codigo == "P6")
    {
        imagen.setCodigonumerico(6);
    }

    switch (imagen.getCodigonumerico()){
    case 1: LeerP1(imagen, archi);
        break;
    case 2: LeerP2(imagen, archi);
        break;
    case 3: LeerP3(imagen, archi);
        break;
    case 4: LeerP4(imagen, archi);
        break;
    case 5: LeerP5(imagen, archi);
        break;
    case 6: LeerP6(imagen, archi);
        break;
    default: cout<< "No se reconoce el codigo de la imagen a guardar.";
    }}
    else cout<<"No se abre"<<endl;
    return imagen;
}



void ArchivoPNM::escribirImagen(Imagen &imagen, string directorio)
{
    string tipoImagen = imagen.getCodigo();
    agregarExtensionPNM(imagen, directorio);

    ofstream archisalida;
    archisalida.open (directorio);
    if (archisalida.is_open())
    {
        cout<<"SE GUARDA ARCHIVO";
        archisalida<<imagen.getCodigo();
        archisalida<<"# "<<imagen.getDescripcion();
        archisalida<<imagen.getAncho()<<" "<<imagen.getAlto();

        if (tipoImagen != "P1" and tipoImagen != "P4")
        {
            archisalida<<imagen.getRangoDinamico()<<endl;
        }

        if (tipoImagen == "P1")
        {
            imagen.setCodigonumerico(1);
        }
        if (tipoImagen == "P2")
        {
            imagen.setCodigonumerico(2);
        }
        if (tipoImagen == "P3")
        {
            imagen.setCodigonumerico(3);
        }
        if (tipoImagen == "P4")
        {
            imagen.setCodigonumerico(4);
        }
        if (tipoImagen == "P5")
        {
            imagen.setCodigonumerico(5);
        }
        if (tipoImagen == "P6")
        {
            imagen.setCodigonumerico(6);
        }

        switch (imagen.getCodigonumerico()){
        case 1: AlmacenarP1(imagen, archisalida);
            break;
        case 2: AlmacenarP2(imagen, archisalida);
            break;
        case 3: AlmacenarP3(imagen, archisalida);
            break;
        case 4: AlmacenarP4(imagen, archisalida);
            break;
        case 5: AlmacenarP5(imagen, archisalida);
            break;
        case 6: AlmacenarP6(imagen, archisalida);
            break;
        default: cout<< "No se reconoce el codigo de la imagen a guardar.";
        }
    archisalida.close();
    }
    else cout<<"No se pudo crear archisalida";
}

void ArchivoPNM::LeerP1(Imagen &imagen, ifstream &archi)
{
    float auxiliar;
    vector<vector<Pixel>> matriz;
    imagen.setRangoDinamico(1);
    imagen.dimensionar();
    archi.ignore();

    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archi>>auxiliar;
            Pixel Pauxiliar(auxiliar, auxiliar, auxiliar);
            matriz[f][c]= Pauxiliar;
        }
    }
    imagen.setImagen(matriz);

}

void ArchivoPNM::LeerP2(Imagen &imagen, ifstream &archi)
{
    float auxiliar;
    vector<vector<Pixel>> matriz;
    imagen.dimensionar();

    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archi>>auxiliar;
            Pixel Pauxiliar(auxiliar, auxiliar, auxiliar);
            matriz[f][c]= Pauxiliar;
        }
    }
    imagen.setImagen(matriz);
}

void ArchivoPNM::LeerP3(Imagen &imagen, ifstream &archi)
{
    float r, g ,b;
    vector<vector<Pixel>> matriz;
    imagen.dimensionar();

    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archi>>r>>g>>b;
            Pixel Pauxiliar(r, g, b);
            matriz[f][c]= Pauxiliar;
        }
    }
    imagen.setImagen(matriz);
}

void ArchivoPNM::LeerP4(Imagen &imagen, ifstream &archi)
{
    char auxiliar;
    vector<vector<Pixel>> matriz;
    imagen.setRangoDinamico(1);
    imagen.dimensionar();
    archi.ignore();

    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archi.read((char * ) &auxiliar , sizeof(auxiliar));
            Pixel Pauxiliar(auxiliar, auxiliar, auxiliar);
            matriz[f][c]= Pauxiliar;
        }
    }
    imagen.setImagen(matriz);
}

void ArchivoPNM::LeerP5(Imagen &imagen, ifstream &archi)
{
    char auxiliar;
    vector<vector<Pixel>> matriz;
    imagen.dimensionar();


    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archi.read((char * ) &auxiliar , sizeof(auxiliar));
            Pixel Pauxiliar(auxiliar, auxiliar, auxiliar);
            matriz[f][c]= Pauxiliar;
        }
    }
    imagen.setImagen(matriz);
}

void ArchivoPNM::LeerP6(Imagen &imagen, ifstream &archi)
{
    char r, g, b;
    vector<vector<Pixel>> matriz;
    imagen.dimensionar();


    for(int f=0; f<imagen.getAlto();f++){
        for(int c=0; c<imagen.getAncho();c++){

            archi.read((char * ) &r , sizeof(r));
            archi.read((char * ) &g , sizeof(r));
            archi.read((char * ) &b , sizeof(r));
            Pixel Pauxiliar(r, g, b);
            matriz[f][c]= Pauxiliar;
        }
    }
    imagen.setImagen(matriz);
}

void ArchivoPNM::agregarExtensionPNM(Imagen &imagen, string rutaImagen)
{
    string tipoArchivo = imagen.getCodigo();

    if(tipoArchivo == "P6" or tipoArchivo == "P3")
    {
        rutaImagen+=".ppm";
    }
    else if (tipoArchivo == "P5" or tipoArchivo == "P2")
    {
        rutaImagen+=".pgm";
    }
    else if (tipoArchivo == "P4" or tipoArchivo == "P1")
    {
       rutaImagen+=".pbm";
    }
}

void ArchivoPNM::AlmacenarP1(Imagen &imagen, ofstream &archisalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAncho(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.DevolverPixel(f,c);
            archisalida<< Pauxiliar.getR()<<" ";
        }
    }

}

void ArchivoPNM::AlmacenarP2(Imagen &imagen, ofstream &archisalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAncho(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.DevolverPixel(f,c);
            archisalida<< Pauxiliar.getR()<<" ";
        }
    }
}

void ArchivoPNM::AlmacenarP3(Imagen &imagen, ofstream &archisalida)
{
    Pixel Pauxiliar;
    float R,G,B;

    for(int f=0; f<imagen.getAncho(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.DevolverPixel(f,c);
            R=Pauxiliar.getR();
            G=Pauxiliar.getG();
            B=Pauxiliar.getB();
            archisalida<<R<<" "<<G<<" "<<B<<" ";
        }
    }
}

void ArchivoPNM::AlmacenarP4(Imagen &imagen, ofstream &archisalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAncho(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.DevolverPixel(f,c);
            float valor = Pauxiliar.getR();
            archisalida.write((char*)&valor, sizeof (float));

        }
    }
}

void ArchivoPNM::AlmacenarP5(Imagen &imagen, ofstream &archisalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAncho(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.DevolverPixel(f,c);
            float valor = Pauxiliar.getR();
            archisalida.write((char*)&valor, sizeof (float));
        }
    }

}

void ArchivoPNM::AlmacenarP6(Imagen &imagen, ofstream &archisalida)
{
    Pixel Pauxiliar;

    for(int f=0; f<imagen.getAncho(); f++)
    {
        for(int c=0; c<imagen.getAncho(); c++)
        {
            Pauxiliar = imagen.DevolverPixel(f,c);
            float valorR = Pauxiliar.getR();
            float valorG = Pauxiliar.getG();
            float valorB = Pauxiliar.getB();

            archisalida.write((char*)&valorR, sizeof (float));
            archisalida.write((char*)&valorG, sizeof (float));
            archisalida.write((char*)&valorB, sizeof (float));

        }
    }
}
