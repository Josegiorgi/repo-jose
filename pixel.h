#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
public:
    Pixel();
    Pixel(float aR, float aG, float aB);

    float getR();
    float getG();
    float getB();

    void setR(float value);
    void setG(float value);
    void setB(float value);

 //Operaciones algebraicas de pixel:
    bool operator==(Pixel Pix);
    Pixel operator*(float);
    Pixel operator+(Pixel Pix);
    Pixel operator-(Pixel Pix);

private:
    float R;
    float G;
    float B;

};

#endif // PIXEL_H

