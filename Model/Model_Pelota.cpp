#include "Model_Pelota.h"


Pelota::Pelota()
{
    //Initialize the offsets
    mPosX = (ANCHO_NIVEL/2)-(ANCHO_PELOTA/2);
    mPosY = (ALTO_NIVEL/2)-(ANCHO_PELOTA/2);

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    colli_pelo.x=this->getPosX();
    colli_pelo.y=this->getPosY();
    colli_pelo.h=this->ANCHO_PELOTA;
    colli_pelo.w=this->ANCHO_PELOTA;
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
    if (mVelX>0){
        mVelX--;
    }
    if (mVelX<0){
        mVelX++;
    }
     if (mVelY>0){
        mVelY--;
    }
    if (mVelY<0){
        mVelY++;
    }

    this->colli_pelo.x = this->getPosX();
    this->colli_pelo.y = this->getPosY();
}

void Pelota::setVelocidadX(int velocidad){
     mVelX = velocidad ;
  }
    void Pelota::setVelocidadY(int velocidad){
        mVelY = velocidad;
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

SDL_Rect * Pelota::getCollider()
{
    return &colli_pelo;
}

