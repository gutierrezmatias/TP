#include "Inactivo.h"

#define VELOCIDAD_JUGADOR 3
#define TOLERANCIA 1

Inactivo::Inactivo()
{
    //ctor
}

Inactivo::~Inactivo()
{
    //dtor
}

void Inactivo::move()
{
    if (posInitX>mPosX){
        this->mVelX=VELOCIDAD_JUGADOR;
        this->mPosX += this->mVelX;
    }
    if (posInitX<mPosX){
        this->mVelX=-VELOCIDAD_JUGADOR;
        this->mPosX += this->mVelX;
    }

    if (posInitY>mPosY){
        this->mVelY=VELOCIDAD_JUGADOR;
        this->mPosY += this->mVelY;
    }
     if (posInitY<mPosY){
        this->mVelY=-VELOCIDAD_JUGADOR;
        this->mPosY += this->mVelY;
    }
    if (posInitX==mPosX){
    this->mVelX=0;
    }
    if (posInitY==mPosY){
    this->mVelY=0;
    }
}
bool Inactivo::estaActivo()
{
    return false;
}
