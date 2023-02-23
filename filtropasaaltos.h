#ifndef FILTROPASAALTOS_H
#define FILTROPASAALTOS_H
#include "filtro.h"
#include "imagen.h"

class FiltroPasaaltos : public Filtro
{
public:
    FiltroPasaaltos();
    ~FiltroPasaaltos() override;
    void aplicarFiltro(Imagen &pImagen) override;
private:
    vector<float> kernel;

};

#endif // FILTROPASAALTOS_H
