#include "interfazdeusuario.h"
#include"iostream"
using namespace std;

InterfazdeUsuario::InterfazdeUsuario()
{

}

void InterfazdeUsuario::mostrarListaDeOpciones(vector<string> lista)
{
    for(unsigned int i=0; i<lista.size(); i++)
    {
        cout<<i+1<<")"<<lista[i]<<endl;
    }
    cout<<endl;
}

void InterfazdeUsuario::mostrarOpcionElegida(string pNombre)
{
    cout<<pNombre;
}

int InterfazdeUsuario::formatoArchivoGuardar(Imagen &pImagen)
{
    int eleccion;
    cout<<endl<<"Seleccione el formato en el que desea guardar la imagen: ";
    cout<<endl<<"1)En formato texto";
    cout<<endl<<"2)En formato binario";

    if(pImagen.getCodigo()=="P2" or pImagen.getCodigo()=="P5" or pImagen.getCodigo()=="P2C")
    {
        cout<<endl<<"3)En formato AIC";
    }

    cout<<endl<<"Su opcion es: ";
    cin>>eleccion;

    if(eleccion == 3 and (pImagen.getCodigo() == "P2" or pImagen.getCodigo() == "P5" or pImagen.getCodigo() == "P2C"))
    {
       return eleccion;
    }

    if (eleccion!=1 && eleccion!=2)
    {
        cout<<"Opcion incorrecta, ingrese nuevamente el formato: ";
        cin>>eleccion;
    }

    return eleccion;
}
string InterfazdeUsuario::nombreArchivoGuardar()
{
    string nombre;
    cout<<"\nIntroduzca el nombre de la imagen a guardar: ";
    cin>>nombre;

    return nombre;
}

void InterfazdeUsuario::mostrarAtajosdeTeclado()
{
    cout << endl << "Atajos de teclado:" << endl;
    cout << "Ctrl + -> " << ends << " Muesta la siguiente imagen" << endl;
    cout << "Ctrl + <- " << ends << " Muesta la imagen anterior" << endl;
    cout << "Ctrl + H "  << ends << " Muesta el histograma de la imagen acutal y la informacion estadistica" << endl;
    cout << "Ctrl + G " << ends << " Guardar Imagen" << endl;
    cout << "Ctrl + 1 " << ends << " Aplicar LUT 1" << endl;
    cout << "Ctrl + 2 " << ends << " Aplicar LUT 2" << endl;
    cout << "Ctrl + clic izquierdo " << ends << " Colorea area seleccionada, Algoritmo del pintor" << endl;
    cout << "Ctrl + L " << ends << " Limpiar area" << endl;
    cout << "Ctrl + S " << ends << " Aplicar suavizado " << endl;
    cout << "Ctrl + M " << ends << " Aplicar mediana " << endl;
    cout << "Ctrl + C " << ends << " Ajustar contraste " << endl;
    cout << "Ctrl + + " << ends << " Aumentar brillo " << endl;
    cout << "Ctrl + - " << ends << " Disminuir brillo " << endl;
    cout << "Ctrl + B " << ends << " Binarizar imagen de intensidad" << endl << endl;
}
