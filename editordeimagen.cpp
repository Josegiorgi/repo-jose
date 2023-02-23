#include "editordeimagen.h"
#include "filtromediana.h"
#include "filtropasaaltos.h"
#include "filtropasabajos.h"

EditordeImagen::EditordeImagen()
{

}

void EditordeImagen::disminuirBrillo(Imagen &pImagen)
{
    Pixel pAuxiliar;

    for(int f=0; f<pImagen.getAlto();f++)
    {
        for(int c=0; c<pImagen.getAncho();c++)
        {
            pAuxiliar=pImagen.devolverPixel(f,c);
            float valorR = pAuxiliar.getR();
            float valorG = pAuxiliar.getG();
            float valorB = pAuxiliar.getB();
            valorR=valorR-5;
            valorG=valorG-5;
            valorB=valorB-5;

            if(valorR<0)
            {
                pAuxiliar.setR(0);
            }

            else pAuxiliar.setR(valorR);


            if(valorG<0)
            {
                pAuxiliar.setG(0);
            }

            else pAuxiliar.setG(valorG);

            if(valorB<0)
            {
                pAuxiliar.setB(0);
            }
            else pAuxiliar.setB(valorB);


            pImagen.generarPixel(pAuxiliar,f,c);
        }
    }
}
void EditordeImagen::aumentarBrillo(Imagen &pImagen)
{
    unsigned int M = pImagen.getRangoDinamico();
    Pixel pAuxiliar;

    for(int f=0; f<pImagen.getAlto();f++)
    {
        for(int c=0; c<pImagen.getAncho();c++)
        {
            pAuxiliar=pImagen.devolverPixel(f,c);
            float valorR = pAuxiliar.getR();
            float valorG = pAuxiliar.getG();
            float valorB = pAuxiliar.getB();
            valorR=valorR+5;
            valorG=valorG+5;
            valorB=valorB+5;


            if(valorR>M)
            {
                pAuxiliar.setR((float)M);
            }

            else pAuxiliar.setR(valorR);


            if(valorG>M)
            {
                pAuxiliar.setG((float)M);
            }

            else pAuxiliar.setG(valorG);

            if(valorB>M)
            {
                pAuxiliar.setB((float)M);
            }
            else pAuxiliar.setB(valorB);


            pImagen.generarPixel(pAuxiliar,f,c);
        }
    }
}

void EditordeImagen::modificarContraste(Imagen &pImagen)
{
    procesador.setImagen(pImagen);
    Pixel max = procesador.getMaximo();
    Pixel min = procesador.getMinimo();
    float rango = pImagen.getRangoDinamico();

    Pixel pAux1;

    for(int i=0 ; i < pImagen.getAlto() ; i++)
    {
        for(int j=0 ; j < pImagen.getAncho() ; j++)
        {
            pAux1 = pImagen.devolverPixel(i,j);
            float componenteR = pAux1.getR();
            float componenteG = pAux1.getG();
            float componenteB = pAux1.getB();

            float nuevaComponenteR = (((componenteR-min.getR())/(max.getR()-min.getR()))*rango);
            float nuevaComponenteG = (((componenteG-min.getG())/(max.getG()-min.getG()))*rango);
            float nuevaComponenteB = (((componenteB-min.getB())/(max.getB()-min.getB()))*rango);

            Pixel pAux2(nuevaComponenteR,nuevaComponenteG,nuevaComponenteB);
            pImagen.generarPixel(pAux2,i,j);
        }
    }
}

void EditordeImagen::negativoImagen(Imagen &pImagen)
{
    int rango = pImagen.getRangoDinamico();
    Pixel aux;
    for(int f = 0; f < pImagen.getAlto(); ++f)
    {
        for(int c = 0; c < pImagen.getAncho(); ++c)
        {
            aux = pImagen.devolverPixel(f,c);
            float intensidadR = aux.getR();
            float intensidadG = aux.getG();
            float intensidadB = aux.getB();
            float nueva_intensidadR = rango - intensidadR;
            float nueva_intensidadG = rango - intensidadG;
            float nueva_intensidadB = rango - intensidadB;

            Pixel aux1(nueva_intensidadR, nueva_intensidadG, nueva_intensidadB);
            pImagen.generarPixel(aux1,f,c);
        }
    }
}

void EditordeImagen::aplicarFiltro(Imagen &pImagen, int pOpcion)
{
    if(pOpcion==1)
    {
        ptrFiltro = new FiltroMediana;
        ptrFiltro->aplicarFiltro(pImagen);
        delete ptrFiltro;
    }

    if(pOpcion==2)
    {
        ptrFiltro = new FiltroPasabajos;
        ptrFiltro->aplicarFiltro(pImagen);
        delete ptrFiltro;
    }
}

void EditordeImagen::aplicarLut(Imagen &pImagen, int pOpcion)
{
    if(pImagen.getCodigo() == "P5" or pImagen.getCodigo() == "P2")
    {
            pImagen.setCodigo("P3");
    }
    lut.aplicarPseudocoloreo(pOpcion,pImagen);
}
void EditordeImagen::binarizar(Imagen &pImagen)
{
    float intensidad = pImagen.getRangoDinamico()/(float)2;

    pImagen.setCodigo("P1");
    pImagen.setRangoDinamico(1);

    for (int f=0 ; f < pImagen.getAlto() ; f++)
    {
        for(int c=0 ; c < pImagen.getAncho() ; c++)
        {
            Pixel aux = pImagen.devolverPixel(f,c);
            if(aux.getR() > intensidad && aux.getG() > intensidad && aux.getB() > intensidad)
            {
                Pixel aux1(1.0f,1.0f,1.0f);
                pImagen.generarPixel(aux1,f,c);
            }
            else
            {
                Pixel aux2(0.0f,0.0f,0.0f);
                pImagen.generarPixel(aux2,f,c);
            }
        }

    }
 }
