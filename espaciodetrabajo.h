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
    string getListadoDeArchivos(int ID);

private:
    vector <string> listadoDeArchivos;
};


#endif // ESPACIODETRABAJO_H
