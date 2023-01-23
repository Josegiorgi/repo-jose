#include "interfazdeusuario.h"
#include"iostream"
using namespace std;

InterfazdeUsuario::InterfazdeUsuario()
{

}

void InterfazdeUsuario::MostrarMenudeOpciones(vector<string> lista)
{
   for(unsigned int i=0; i<lista.size(); i++)
   {
    cout<<i+1<<")"<<lista[i]<<endl;
   }
   cout<<endl;
}

void InterfazdeUsuario::MostrareArchivoSeleccionado(GestordeArchivos &Gestor)
{
    cout<<"El nombre de la imagen es: "<<Gestor.getArchivos(Gestor.getIDimagen());
}

//int InterfazdeUsuario::formatoArchivoGuardar(Imagen &imagen)
//{
//    int eleccion;
//    cout<<endl<<"Seleccione el formato en el que desea guardar la imagen: ";
//    cout<<endl<<"1)En formato texto";
//    cout<<endl<<"2)En formato binario";

//    if(imagen.getCodigo()=="P2" or imagen.getCodigo()=="P5" or imagen.getCodigo()=="P2C")
//    {
//        cout<<endl<<"3)En formato AIC";
//    }

//    cout<<endl<<"Su opcion es: ";
//    cin>>eleccion;

//}

string InterfazdeUsuario::nombreArchivoGuardar()
{
    string nombre;
    cout<<"\nIntroduzca el nombre de la imagen a guardar: ";
    cin>>nombre;

    return nombre;
}

void InterfazdeUsuario::MostrarAtajosdeteclado()
{

}
