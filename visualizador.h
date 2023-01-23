#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H
#include "imagen.h"
#include "gestordearchivos.h"
#include "imagen.h"
#include <QApplication>
#include <QOpenGLWidget>


using namespace std;

class Visualizador : public QOpenGLWidget
{
public:
    Visualizador(GestordeArchivos *pgestor, int ID);
    ~Visualizador();
    // Atributos gráficos del dibujo en el graficador
    float escala;  // Para matenener las proporciones para cualquier ventana.
    float desplx, desply; // Para desplazar la imagen al centro de la ventana.
    void graficarImagen();
    void cargarImagen(int ID);

protected:
    // Métodos obligatorios que se deben redefinir aquí en protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int ancho, int alto) override;
private:
    Imagen imagen;
    GestordeArchivos *gestor;
};
#endif // VISUALIZADOR_H
