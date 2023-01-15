#include "pixel.h"
#include "iostream"

Pixel::Pixel()
{

}
Pixel::Pixel(float aR, float aG, float aB)
{
    R=aR;
    G=aG;
    B=aB;
}
float Pixel::getR()
{
    return R;
}

float Pixel::getG()
{
    return G;
}
float Pixel::getB()
{
    return B;
}

void Pixel::setR(float value)
{
    R = value;
}

void Pixel::setG(float value)
{
    G = value;
}

void Pixel::setB(float value)
{
    B = value;
}
Pixel Pixel::operator+(Pixel p)
{
    Pixel aux;
    aux.R = this->R + p.R;
    aux.G = this->G + p.G;
    aux.B = this->B + p.B;
    return aux;
}
Pixel Pixel::operator-(Pixel p)
{
    Pixel aux;
    aux.R = this->R - p.R;
    aux.G = this->G - p.G;
    aux.B = this->B - p.B;
    return aux;
}
Pixel Pixel::operator*(float pFloat)
{
    Pixel aux;
    aux.R = this->R * pFloat;
    aux.G = this->G * pFloat;
    aux.B = this->B * pFloat;
    return aux;
}
bool Pixel::operator ==(Pixel pPix)
{
    return (this->R == pPix.getR() and this->G == pPix.getG() and this->B == pPix.getB());
}
