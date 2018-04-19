#include "Estado.h"

#define VELOCIDAD_JUGADOR 3

Estado::Estado()
{
    //Initialize the offsets
    this->posInitX = 0;
    this->posInitY = 0;
    this->mPosX = this->posInitX;
    this->mPosY = this->posInitY;
    //Initialize the velocity
    this->mVelX = 0;
    this->mVelY = 0;
    this->aceleracion = VELOCIDAD_NORMAL;
}

Estado::~Estado()
{
    //dtor
}

//Position accessors
int Estado::getPosX()
{
    return this->mPosX;
}
int Estado::getPosY()
{
    return this->mPosY;
}
//Position accessors
int Estado::getVelX()
{
    return this->mVelX;
}
int Estado::getVelY()
{
    return this->mVelY;
}

void Estado::setPosX(int PosX)
{
    this->mPosX = PosX;
}
void Estado::setPosY(int PosY)
{
    this->mPosY = PosY;
}

void Estado::setPosInitX(int posX)
{
    this->posInitX = posX;
}
void Estado::setPosInitY(int posY)
{
    this->posInitY = posY;
}
void Estado::copiarEstado(Estado* estado)
{
    this->posInitX = estado->posInitX;
    this->posInitY = estado->posInitY;
    this->mPosX = estado->mPosX;
    this->mPosY = estado->mPosY;
    this->mVelX = estado->mVelX;
    this->mVelY = estado->mVelY;
}
void Estado::disminuirVelocidadX()
{
    this->mVelX -= this->aceleracion;
}
void Estado::disminuirVelocidadY()
{
    this->mVelY -= this->aceleracion;
}
void Estado::aumentarVelocidadX()
{
    this->mVelX += this->aceleracion;
}
void Estado::aumentarVelocidadY()
{
    this->mVelY += this->aceleracion;
}

void Estado::detenerVelocidad() {
    this->mVelX = 0;
    this->mVelY = 0;
}

void Estado::desacelerar() {
    this->aceleracion = VELOCIDAD_NORMAL;
}
