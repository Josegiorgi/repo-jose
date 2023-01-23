#include "visualizador.h"
#include <iostream>

Visualizador::Visualizador(GestordeArchivos *pgestor, int ID)
{
    gestor = pgestor;
    cargarImagen(ID);
}

Visualizador::~Visualizador()
{

}

void Visualizador::graficarImagen()
{
    unsigned int filas = imagen.getAlto(),columnas = imagen.getAncho(),M = imagen.getRangoDinamico();

    glPushMatrix();
    // mover la imagen al centro de la ventana
    {
        glTranslatef(desplx, desply, 0.0f);

        // escalar que mantenga sus proporciones para cualquier tamaño de ventana

        glScalef(escala, escala, 1.0f);

        glBegin(GL_QUADS);

        Pixel aux;

        for(uint f = 0; f < filas; ++f)
        {
            for(uint c = 0; c < columnas; ++c)

            {
                aux = imagen.DevolverPixel(f,c);
                glColor3f(aux.getR()/(float)M , aux.getG()/(float)M , aux.getB()/(float)M);

                glVertex3f(c  , f  , 0);
                glVertex3f(c  , f+1, 0);
                glVertex3f(c+1, f+1, 0);
                glVertex3f(c+1, f  , 0);
            }
        }
        glEnd();
    }
    glPopMatrix();

}

void Visualizador::cargarImagen(int ID)
{
    imagen = gestor->generarImagen(ID);
}

void Visualizador::initializeGL()
{
    glClearColor(0.3,0.3,0.3, 0.0f); // color para fondo
}

void Visualizador::paintGL()
{
    resizeGL(width(), height());
    glClear(GL_COLOR_BUFFER_BIT);


    unsigned int filas = imagen.getAlto() , columnas = imagen.getAncho();
    float relAncho = ((float)width())  / ((float)imagen.getAncho());
    float relAlto  = ((float)height()) / ((float)imagen.getAlto());

    desply = desplx = 0.0f;
    escala = 1.0f;

    if(relAncho < relAlto)
    {
        escala = relAncho;
        desply = (height() - (float)filas * escala) * 0.5f;
    }
    else
    {
        escala = relAlto;
        desplx = (width() - (float)columnas * escala) * 0.5f;
    }

    graficarImagen();

}

void Visualizador::resizeGL(int ancho, int alto)
{
    glViewport(0, 0, ancho, alto);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float xMin = -5.0f, xMax = ancho + 5.0f, yMin = -5.0f, yMax = alto + 5.0f;

    glOrtho(xMin, xMax, yMin, yMax, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


