#include <QCoreApplication>
#include <gestordearchivos.h>
#include <interfazdeusuario.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    InterfazdeUsuario interfaz;
    GestordeArchivos gestor;

    cout<<"Trabajo final;"<<endl;
    cout<<"Selecciona la opcion a elegir:"<<endl<<endl;
    gestor.setRuta("../Proyecto final JG/");
    string ruta = gestor.getRuta();
    gestor.setRaiz("Autotest/");
    string raiz = gestor.getRaiz();
    vector<string> lista = gestor.getListadoDeArchivos(ruta + raiz);

    interfaz.MostrarMenudeOpciones(lista);
    int opcion;

    cout<<"Opcion: ";
    cin>>opcion;

    cout<<endl<<"La opcion seleccionada es: "<<gestor.getArchivos(opcion)<<endl;
    cout<<"Las opciones son: "<<endl;

    gestor.setListaCarpeta(ruta + raiz,opcion+1);
    vector<string> listacarpetas = gestor.getListaCarpeta();

    interfaz.MostrarMenudeOpciones(listacarpetas);

    cout<<endl<<"Seleccione la imagen o si desea terminar el programa ingerese '0': ";
    cin>>opcion;

    gestor.setIDimagen(opcion);
    string fromato = gestor.reconocerFormato();
    cout<<"El formato es: "<<fromato<<endl;


    if(opcion!= 0)
    {
        gestor.generarImagen(opcion+1);
    }








    return a.exec();
}
