#include "algortimodelpintor.h"
#include "cmath"

AlgortimodelPintor::AlgortimodelPintor()
{
    tolerancia=30;

}

void AlgortimodelPintor::buscarArea(unsigned int pf, unsigned int pc)
{
    profundidad ++;
    if(profundidad<5000)
    {
        if(pf<matrizMascara.size() && pc<matrizMascara[0].size())
        {
            Pixel paux = ptrImagen->devolverPixel(pf,pc);
            if(matrizMascara[pf][pc]==false &&  devolverDiferenciaPixel(pInicial,paux)<= tolerancia)
            {
                area++;
                matrizMascara[pf][pc]=true;
                for(unsigned int p=0; p<movimiento.size();p++ )
                {
                    buscarArea(pf+movimiento[p].f,pc+movimiento[p].c);
                }
            }
        }

    }
   profundidad--;
}

void AlgortimodelPintor::colorearArea(unsigned int pf, unsigned int pc)
{
    dimensionaMatriz();

    profundidad=0;
    pInicial = ptrImagen->devolverPixel(pf,pc);
    buscarArea(pf,pc);

    Pixel pColor (204,255,0);

    for(unsigned int f=0;f<matrizMascara.size();f++)
    {
        for(unsigned int c=0; c<matrizMascara[0].size();c++)
        {
            if(matrizMascara[f][c]==true)
            {
                ptrImagen->generarPixel(pColor,f,c);
            }
        }
    }

    profundidad = 0;

}

int AlgortimodelPintor::devolverDiferenciaPixel(Pixel &p1, Pixel &p2)
{
    int calculo = sqrt(pow((p1.getR()-p2.getR()),2) + pow((p1.getG()-p2.getG()),2) + pow((p1.getB()-p2.getB()),2));
    return calculo;
}

void AlgortimodelPintor::setImagen(Imagen *pImagen)
{
    ptrImagen=pImagen;
}

void AlgortimodelPintor::limpiarArea()
{
    matrizMascara.clear();
    area = 0;
}

void AlgortimodelPintor::dimensionaMatriz()
{
    matrizMascara.resize(ptrImagen->getAlto(),vector<bool>(ptrImagen->getAncho(),false));
}

float AlgortimodelPintor::devolverArea()
{
    return area;
}


