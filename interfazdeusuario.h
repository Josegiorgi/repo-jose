#ifndef INTERFAZDEUSUARIO_H
#define INTERFAZDEUSUARIO_H
#include "gestordearchivos.h"
#include "imagen.h"
#include "vector"
#include "string"

using namespace std;

class InterfazdeUsuario
{
public:
    InterfazdeUsuario();
    void MostrarMenudeOpciones(vector<string> lista);
    void MostrareArchivoSeleccionado(GestordeArchivos &Gestor);
   // int formatoArchivoGuardar(Imagen &imagen);
    string nombreArchivoGuardar ();
    void MostrarAtajosdeteclado();

};

#endif // INTERFAZDEUSUARIO_H
