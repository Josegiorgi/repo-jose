#include "interfazdeusuario.h"
#include"iostream"
using namespace std;

InterfazdeUsuario::InterfazdeUsuario()
{

}

void InterfazdeUsuario::MostrarMenudeOpciones(vector<string> lista)
{
   for(int i=0; i<lista.size(); i++)
   {
    cout<<i<<")"<<lista[i]<<endl;
   }
   cout<<endl;
}

void InterfazdeUsuario::MostrareArchivoSeleccionado(GestordeArchivos &Gestor)
{
    cout<<"El nombre de la imagen es: "<<Gestor.getArchivos(Gestor.getIDimagen());
}

void InterfazdeUsuario::MostrarAtajosdeteclado()
{

}
