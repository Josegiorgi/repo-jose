#include "filtromediana.h"
using namespace std;

FiltroMediana::FiltroMediana()
{

}
FiltroMediana::~FiltroMediana()
{

}
void FiltroMediana:: aplicarFiltro(Imagen &pImagen)
{
  vector<Pixel>listaPixeles;
  listaPixeles.resize(9);
  Pixel aux;
  Imagen auxImagen = pImagen;

  for(int f=1; f<pImagen.getAlto()-1; f++)
  {
      for(int c=1;c<pImagen.getAncho()-1;c++)
      {
          listaPixeles = {auxImagen.devolverPixel(f-1,c-1),auxImagen.devolverPixel(f-1,c),auxImagen.devolverPixel(f-1,c+1),
                          auxImagen.devolverPixel(f,c-1),auxImagen.devolverPixel(f,c),auxImagen.devolverPixel(f,c+1),
                          auxImagen.devolverPixel(f+1,c-1),auxImagen.devolverPixel(f+1,c), auxImagen.devolverPixel(f+1,c+1)};

          sort(listaPixeles.begin(),listaPixeles.end());
          pImagen.generarPixel(listaPixeles[4],f,c);
      }
  }

}
