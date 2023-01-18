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


  switch (imagen.getCodigo()[1]){
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
  }
return imagen;
}



void ArchivoPNM::escribirImagen(Imagen &imagen, string nombreArchivo, string directorio)
{

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
    float r, g, b;
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

void ArchivoPNM::AlmacenarP1(Imagen &imagen, ofstream &archisalida)
{

}

void ArchivoPNM::AlmacenarP2(Imagen &imagen, ofstream &archisalida)
{

}

void ArchivoPNM::AlmacenarP3(Imagen &imagen, ofstream &archisalida)
{

}

void ArchivoPNM::AlmacenarP4(Imagen &imagen, ofstream &archisalida)
{

}

void ArchivoPNM::AlmacenarP5(Imagen &imagen, ofstream &archisalida)
{

}

void ArchivoPNM::AlmacenarP6(Imagen &imagen, ofstream &archisalida)
{

}
