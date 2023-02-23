#include "filtropasabajos.h"

FiltroPasabajos::FiltroPasabajos()
{
    kernel.resize(9);
    kernel = {(float)1/9, (float)1/9, (float)1/9, (float)1/9,(float) 1/9,(float) 1/9,(float) 1/9,(float) 1/9,(float) 1/9};
}

FiltroPasabajos::~FiltroPasabajos()
{

}

void FiltroPasabajos::aplicarFiltro(Imagen &pImagen)
{
    Imagen auxImagen = pImagen;
    Pixel pAux;

    for(int f=1; f<pImagen.getAlto()-1; f++)
    {
        for(int c=1;c<pImagen.getAncho()-1;c++)
        {
            pAux = (auxImagen.devolverPixel(f-1,c-1)*kernel[0] + auxImagen.devolverPixel(f-1,c)*kernel[1]+auxImagen.devolverPixel(f-1,c+1)*kernel[2]+
                    auxImagen.devolverPixel(f,c-1)*kernel[3]+auxImagen.devolverPixel(f,c)*kernel[4]+auxImagen.devolverPixel(f,c+1)*kernel[5]+
                    auxImagen.devolverPixel(f+1,c-1)*kernel[6]+auxImagen.devolverPixel(f+1,c)*kernel[7]+ auxImagen.devolverPixel(f+1,c+1)*kernel[8]);


            pImagen.generarPixel(pAux,f,c);
        }
    }
}
