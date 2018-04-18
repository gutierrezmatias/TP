#ifndef MODEL_PELOTA_H_
#define MODEL_PELOTA_H_
#include <SDL2/SDL.h>
#include "LTexture.h"

class Pelota
{
public:
    //The dimensions of the dot
    static const int ANCHO_PELOTA = 12;
    static const int ALTO_PELOTA = 12;

    //Maximum axis velocity of the dot
    static const int VELOCIDAD_PELOTA = 3;

    //Initializes the variables
    Pelota();

    //Moves the dot
    void move();

    //Position accessors
    int getPosX();
    int getPosY();
    //Position accessors
    int getVelX();
    int getVelY();

    void setPosX(int PosX);

    void setPosY(int PosY);

    void disminuirVelocidadX();

    void disminuirVelocidadY();

    void aumentarVelocidadX();

    void aumentarVelocidadY();

private:
    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;

};

#endif
