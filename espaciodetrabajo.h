#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H
#include "string"
#include "vector"

using namespace std;

class EspaciodeTrabajo
{
public:
    EspaciodeTrabajo();
    void setListadoDeArchivos(string rutaDirectorio);
    vector<string> getListadoDeArchivos(string rutaDirectorio);


private:
    vector<string> listaArchivos;

};


#endif // ESPACIODETRABAJO_H
