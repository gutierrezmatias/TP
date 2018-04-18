#include "Model_Pelota.h"


Pelota::Pelota()
{
    //Initialize the offsets
    mPosX = (ANCHO_NIVEL/2)-(ANCHO_PELOTA/2);
    mPosY = (ALTO_NIVEL/2)-(ANCHO_PELOTA/2);

    //Initialize the velocity
    mVelX = 50;
    mVelY = 50;
}

void Pelota::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + ANCHO_PELOTA > ANCHO_NIVEL) )
    {
        //Move back
        mPosX -= mVelX;
        mVelX=(-1)*mVelX;

    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + ANCHO_PELOTA > ALTO_NIVEL ) )
    {
        //Move back
        mPosY -= mVelY;
        mVelY=(-1)*mVelY;
    }

}

int Pelota::getPosX()
{
    return mPosX;
}

int Pelota::getPosY()
{
    return mPosY;
}

void Pelota::setPosX(int PosX)
{
    mPosX= PosX;
}

void Pelota::setPosY(int PosY)
{
    mPosY=PosY ;
}



void Pelota::disminuirVelocidadX()
{
    mVelX -= VELOCIDAD_PELOTA;;
}

void Pelota::disminuirVelocidadY()
{
    mVelY -= VELOCIDAD_PELOTA; ;
}

void Pelota::aumentarVelocidadX()
{
    mVelX += VELOCIDAD_PELOTA; ;
}

void Pelota::aumentarVelocidadY()
{
    mVelY += VELOCIDAD_PELOTA; ;
}

int Pelota::getVelX()
{
    return mVelX;
}

int Pelota::getVelY()
{
    return mVelY;
}


