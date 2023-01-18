#ifndef INTERFAZDEUSUARIO_H
#define INTERFAZDEUSUARIO_H
#include "gestordearchivos.h"
#include "vector"
#include "string"

using namespace std;

class InterfazdeUsuario
{
public:
    InterfazdeUsuario();
    void MostrarMenudeOpciones(vector<string> lista);
    void MostrareArchivoSeleccionado(GestordeArchivos &Gestor);
    void MostrarAtajosdeteclado();

};

#endif // INTERFAZDEUSUARIO_H
